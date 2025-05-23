// tried to solve this using depth first search but did not work
// copied clever solution from the discussion section for this problem:
// LCA is the node on which the search for a and b diverges. Either split left and right or found a or b.
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    // Node* traverseLeft(Node* root, int v1, int v2, vector<Node*>& lcas, bool& v1_found, bool& v2_found, vector<Node*>& possible_solutions1, vector<Node*>& possible_solutions2, unordered_set<Node*>& visited) {
    //     cout << "traverseLeft function: " << endl;
    //     Node* old_root;
    //     while (root) {
    //         if (root->left || root->right) {
    //             lcas.emplace_back(root);
    //         } else if (
    //             (!root->left && !root->right) || 
    //             (
    //                 visited.find(root->left) != visited.end() && 
    //                 visited.find(root->right) != visited.end()
    //             ) ||
    //             (
    //                 visited.find(root->left) != visited.end() && 
    //                 !root->right
    //             ) ||
    //             (
    //                 !root->left &&
    //                 visited.find(root->right) != visited.end()
    //             )
    //         ){
    //             visited.emplace(root);
    //         }
    //         if (root->data == v1 && !v1_found) {
    //             v1_found = true;
    //             possible_solutions1 = lcas;
    //         } else if (root->data == v2 && !v2_found) {
    //             v2_found = true;
    //             possible_solutions2 = lcas;
    //         }
    //         cout << "root: " << root->data << " v1? " << v1_found << " v2? " << v2_found << endl;
    //         cout << "lcas vector: ";
    //         for (auto item : lcas) {
    //             cout << item->data << " ";
    //         }
    //         cout << endl;
    //         if (v1_found && v2_found) {
    //             return root;
    //         }
    //         old_root = root;
    //         root = root->left;
    //     }

    //     return old_root;
    // }
    
    // Node* traverse(Node* root, int v1, int v2, vector<Node*>& lcas, bool& v1_found, bool& v2_found) {
    //     cout << "traverse function: " << endl;
    //     vector<Node*> possible_solutions1, possible_solutions2;
    //     possible_solutions1.reserve(25); 
    //     possible_solutions2.reserve(25);
    //     unordered_set<Node*> visited;
    //     Node* answer = traverseLeft(root, v1, v2, lcas, v1_found, v2_found, possible_solutions1, possible_solutions2, visited);
    //     while (!lcas.empty()) {
    //         if (v1_found && v2_found) {
    //             vector<Node*> intersection;
    //             set_intersection(
    //                 possible_solutions1.begin(), possible_solutions1.end(),
    //                 possible_solutions2.begin(), possible_solutions2.end(),
    //                 back_inserter(intersection)
    //             );
    //             cout << "intersection vector: ";
    //             for (auto item : intersection) {
    //                 cout << item->data << " ";
    //             }
    //             cout << endl;
                
    //             return intersection.back();
    //         }
    //         root = lcas.back();
    //         cout << "just before right loop, root: " << root->data << endl;
    //         while (root->right) {
    //             root = root->right;
    //             root = traverseLeft(root, v1, v2, lcas, v1_found, v2_found, possible_solutions1, possible_solutions2, visited);
    //             if (visited.find(root) != visited.end() && !lcas.empty()) {
    //                 root = lcas.back();
    //             //     cout << lcas.back()->data << " popped first\n";
    //                 lcas.pop_back();
    //             } 
    //         }
    //         cout << "out of right loop, with root: " << root->data << endl;
    //         if (visited.find(lcas.back()) != visited.end() && !lcas.empty()) {
    //             cout << lcas.back()->data << " popped\n";
    //             lcas.pop_back();
    //         }
    //         if (v1_found && v2_found) {
    //             vector<Node*> intersection;
    //             set_intersection(
    //                 possible_solutions1.begin(), possible_solutions1.end(),
    //                 possible_solutions2.begin(), possible_solutions2.end(),
    //                 back_inserter(intersection)
    //             );
    //             cout << "intersection vector: ";
    //             for (auto item : intersection) {
    //                 cout << item->data << " ";
    //             }
    //             cout << endl;
                
    //             return intersection.back();
    //         }
    //     }
        
    //     return nullptr;
    // }
    
    // Node *lca(Node *root, int v1, int v2) {
    //     if (root->data == v1 || root->data == v2) {
    //         return root;
    //     }
    //     Node* lca{};
    //     vector<Node*> lcas;
    //     lcas.reserve(25);
    //     bool v1_found{false}, v2_found{false};
    //     // depth first search
    //     lca = traverse(root, v1, v2, lcas, v1_found, v2_found);
    //     if (v1_found && v2_found) {
    //         return lca;
    //     }
        
    //     return root;
    // }
    
    Node *lca(Node *root, int v1, int v2) {
        while(true)
        {
            if (v1 > root->data && v2 > root->data)
            {
                root = root->right;
            }
            else if (v1 < root->data && v2 < root->data) 
            {
                root = root->left;
            }
            else {
                return root;
            }
        }
    }
        
        
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
