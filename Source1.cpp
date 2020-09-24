#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void Create(Node** start, int new_data) {
    Node* new_node = new Node();
    Node* ptr;
    new_node->data = new_data;
    if (*start == NULL) {
        new_node->next = new_node;
        *start = new_node;
        return;
    }
    ptr = *start;
    while (ptr->next != *start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = *start;
    return;
}