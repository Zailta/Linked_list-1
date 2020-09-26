#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};
void Create(Node** start, int new_data) {
    Node* new_node = new Node();
    Node* ptr;
    new_node->data = new_data;
    if (*start == NULL) {
        new_node->prev = NULL;
        new_node->next = NULL;
        *start = new_node;

    }    ptr = *start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;

}
int main() {
    Node* head = NULL;
    Create(&head, 5);
}