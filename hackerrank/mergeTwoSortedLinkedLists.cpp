#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/////////////////////////////////////////////
// Complete the mergeLists function below. //
/////////////////////////////////////////////

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1 && !head2) return nullptr;
    else if (!head1) return head2;
    else if (!head2) return head1;
    
    SinglyLinkedListNode* merged_pointer;
    head1->data <= head2->data ? merged_pointer = head1 : merged_pointer = head2;
    merged_pointer == head1 ? head1 = head1->next : head2 = head2->next;
    
    SinglyLinkedListNode* returned_pointer = merged_pointer;
    
    // cout << "merged: " << merged_pointer->data << "  head1: " << head1->data 
        // << " head2: " << head2->data << endl;
    
    while (merged_pointer) {
        if (!head1 && !head2)
            merged_pointer = nullptr;
        else if (!head1) {
            merged_pointer->next = head2;
            merged_pointer = head2;
            head2 = head2->next;
            // cout << "merged: " << merged_pointer->data << " head1 null" << endl;
        } else if (!head2) {
            merged_pointer->next = head1;
            merged_pointer = head1;
            head1 = head1->next;
            // cout << "merged: " << merged_pointer->data << " head2 null" << endl;
        } else {
            if (head1->data <= head2->data) {
                merged_pointer->next = head1;
                merged_pointer = head1;
                head1 = head1->next;
            } else {
                merged_pointer->next = head2;
                merged_pointer = head2;
                head2 = head2->next;
            }
            // cout << "merged: " << merged_pointer->data << endl; 
        }
    }
    
    return returned_pointer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}