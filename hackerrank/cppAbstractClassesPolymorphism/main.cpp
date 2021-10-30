#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache{
public:
    LRUCache(int capacity): Cache() {cp = capacity; tail = nullptr; head = nullptr;}

    void addNodeToMap(int key, int value) {
        if (mp.count(key))
            mp.erase(key);
        Node* my_node = new Node(tail, nullptr, key, value);
        auto it_tail = mp.emplace( key, my_node);
        tail = it_tail.first->second;
        it_tail.first->second->prev->next = it_tail.first->second;
    }

    void set(int key, int value) override {
        auto iter_key = mp.find(key);
        if (iter_key == mp.end()) {
            if (static_cast<int>(mp.size()) < cp) {
                if (head == nullptr) {
                    head = new Node(key, value);
                    tail = head;
                    mp.emplace(key, head);
                } else
                    addNodeToMap(key, value);
            } else {
                // delete head Node, remove from the map
                Node* head_temp = head->next;
                mp.erase(head->key);
                delete head;
                head = head_temp;
                // add Node to map
                addNodeToMap(key, value);
            }
        } else {
            addNodeToMap(key, value);
            auto iter_key = mp.find(key);
            if ((*iter_key).second->prev)
                (*iter_key).second->prev->next = (*iter_key).second->next;
            if ((*iter_key).second->next)
                (*iter_key).second->next->prev = (*iter_key).second->prev;

            (*iter_key).second->next = nullptr;
            (*iter_key).second->prev = tail;

            tail->next = (*iter_key).second;

            tail = (*iter_key).second;
        }
    }

    int get(int key) override {
        auto iter_key = mp.find(key);
        if (iter_key == mp.end())
            return -1;
        else
            return iter_key->second->value;
    }
};

int main() {
   int n, capacity, i;
   ifstream inp("input2.txt", fstream::in);
   //cin >> n >> capacity;
   inp >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      //cin >> command;
      inp >> command;
      if(command == "get") {
         int key;
         //cin >> key;
         inp >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         //cin >> key >> value;
         inp >> key >> value;
         l.set(key,value);
      }
   }
   inp.close();

   return 0;
}
