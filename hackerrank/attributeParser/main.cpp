#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <stack>
#include <memory>
#include <array>

using namespace std;

struct Tag{
    string name;
    map<string, string> attribute;
    vector<Tag*> children;

    Tag():name(), attribute(), children{} {}
};


void readTags(const string& in, array<Tag, 20>& all_tags, int i_array, stack<Tag*>& stack_tags) {
    Tag mytag;
    Tag* temp_tag;
    if (in[1] == '/') {
//        if (all_tags.size()-2 >= closed_tags_counter) {
        if (stack_tags.size() > 1) {
            temp_tag = stack_tags.top();
//            cout << stack_tags.size() << " " << temp_tag << " "
//                 << stack_tags.top() << " " << &(all_tags[i_array-1]) << endl;
            stack_tags.pop();
            stack_tags.top()->children.push_back(temp_tag);
//            cout << stack_tags.size() << " " << temp_tag << " " << stack_tags.top() << " "
//                 << &(all_tags[i_array-2]) << " " << &(all_tags[i_array-1]) << endl;
//            cout << stack_tags.size() << " " << temp_tag->name << " " << stack_tags.top()->name << endl;
        }
        return;
    }

    auto iter = in.begin();

    while(!(isspace(*iter)) && iter != in.end()) {
        if (isalnum(*iter)) {
            mytag.name += *iter;
        }
        iter++;
    }

    while(isspace(*iter) && iter != in.end() )
        iter++;

    string attr_key, attr_value;
    while(iter != in.end()) {
        while (!isspace(*iter) && *iter != '=') {//isalnum(*iter)) {
            attr_key += *iter;
            iter++;
        }
        while ((isspace(*iter) || *iter == '=' || *iter == '"') && iter != in.end()) // !isalnum(*iter) &&
            iter++;
        while (!isspace(*iter) && *iter != '=' && *iter != '"'  && iter != in.end()) {
            attr_value += *iter;
            iter++;
        }
        mytag.attribute[attr_key] = attr_value;
        attr_key.clear(); attr_value.clear();
        while (!isalnum(*iter) && iter != in.end())
            iter++;
    }

    all_tags[i_array] = mytag;
    stack_tags.push( &(all_tags[i_array]) );
//    cout << stack_tags.top() << " " << &(all_tags[i_array]) << endl;
}


void interpretTags(const string& in, array<Tag, 20>& all_tags) {
    if (in.empty())
        return;

    auto iter = in.begin();
    string pick_name, pick_attribute;
    vector<string> parent_name;
    int ptr_counter(0);

    while(!(isspace(*iter)) && iter != in.end()) {
        if (isalnum(*iter))
            pick_name += *iter;
        else if (*iter == '.') {
            parent_name.push_back(pick_name);
            ptr_counter++;
            pick_name.clear();
        } else if (*iter == '~') {
            iter++;
            break;
        }
        iter++;
    }
    while (iter != in.end()) {
        pick_attribute += *iter;
        iter++;
    }

    Tag* target_tag = &(*find_if(all_tags.begin(), all_tags.end(),
                          [&](const Tag& a)->bool {
                              return a.name == pick_name;
                          }
                      ));
//    while (ptr_counter > 0) {
//        target_tag = (*target_tag).children;
//        ptr_counter--;
//    }
    if (ptr_counter > 0) {
        bool flag = true;
        string name_to_compare = pick_name;
        while (parent_name.size() > 0) {
            Tag* found_parent = find_if(all_tags.begin(), all_tags.end(),
                                        [&](const Tag& a)->bool {
                                            return a.name == parent_name.back();
                                        });
            if (found_parent != all_tags.end()) {
                if ( find_if(found_parent->children.begin(), found_parent->children.end(),
                             [&](const Tag* a)->bool {
                                 return a->name == name_to_compare;
                             }) != found_parent->children.end() ) {
                    name_to_compare = parent_name.back();
                    parent_name.pop_back();
                } else {
                    cout << "Not Found!" << endl;
                    flag = false;
                    break;
                }
            } else {
                cout << "Not Found!" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true) {
            if (target_tag->attribute.count(pick_attribute) > 0)
                cout << target_tag->attribute[pick_attribute] << endl;
            else
                cout << "Not Found!" << endl;
        }
    } else if (find_if(all_tags.begin(), all_tags.end(),
                    [&](const Tag& a)->bool {
                        for (auto ii : a.children) {
                            if (ii->name == pick_name)
                                return true;
                        }
                        return false;
                    }) == all_tags.end() && target_tag->attribute.count(pick_attribute) > 0)
        cout << target_tag->attribute[pick_attribute] << endl;
    else
        cout << "Not Found!" << endl;
}


int main()
{
    ifstream ifs("input6.txt");
    int N, Q;
    //cin >> N >> Q;
    ifs >> N >> Q; ifs.ignore();
    cout << N << " " << Q << endl;
    const int NN = 20;
    array<Tag, NN> all_tags;
    stack<Tag*> stack_tags;

    for (int i = 0; i != N; i++) {
        string input;
        //getline(cin, input);
        getline(ifs, input);
        cout << input << endl;
        readTags(input, all_tags, i, stack_tags);
//        cout << stack_tags.top()->name <<  " UhU " << endl;
    }

    for (Tag i : all_tags) {
        cout << i.name << " ";
        for (auto j : i.attribute)
            cout << j.first << ":" << j.second << " ";
        if ( !(i.children.empty()) ) {
            for (Tag* k : i.children)
                cout << "points to " << k->name << endl;
        } else cout << endl;
    }

    for (int i = 0; i != Q; i++) {
        string input;
        //getline(cin, input);
        getline(ifs, input);
        cout << input << endl;
        interpretTags(input, all_tags);
    }

    ifs.close();

    return 0;
}
