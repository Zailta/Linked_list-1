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

void Insert_beg(Node** start, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    Node* ptr;
    while (ptr->next != *start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = *start;
    *start = new_node;
    return;
}
void Insert_end(Node** start, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    Node* ptr;
    while (ptr->next != *start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = *start;
    return;
}
void Delete_beg(Node** start) {
    Node* ptr;
    ptr = *start;
    while (ptr->next != *start)
        ptr = ptr->next;
    ptr->next = (*start)->next;
    delete (*start);
    *start = ptr->next;
    return;
}
void Delete_end(Node** start) {
    Node* ptr, * preptr;
    ptr = *start;
    while (ptr->next != *start) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    delete ptr;
    return;
}
void Delete_after(Node** start, int value) {
    Node* ptr, * preptr;
    ptr = *start;
    preptr = ptr;
    while (preptr->data != value) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    if (ptr == *start)
        *start = preptr->next;
    delete ptr;
    return;
}
