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
void Insert_beg(Node** start, int new_data) {
    Node* new_node = new Node();
    (*start)->prev = new_node;
    new_node->next = *start;
    new_node->prev = NULL;
    *start = new_node;
    new_node->data = new_data;
    return;
}
void Insert_end(Node** start, int new_data) {
    Node* ptr;
    Node* new_node = new Node();
    ptr = *start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    new_node->next = NULL;
    new_node->prev = ptr;
    ptr->next = new_node;
    new_node->data = new_data;
    return;
}
void Insert_before(Node** start, int new_data, int value) {
    Node* ptr;
    Node* new_node = new Node();
    new_node->data = new_data;
    ptr = *start;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    (ptr->prev)->next = new_node;
    new_node->prev = ptr->prev;
    ptr->prev = new_node;
    new_node->next = ptr;


    return;

}
void Insert_after(Node** start, int new_data, int value) {
    Node* ptr;
    Node* new_node = new Node();
    new_node->data = new_data;
    ptr = *start;

    while (ptr->data != value) {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    (ptr->next)->prev = new_node;
    ptr->next = new_node;
    new_node->prev = ptr;


    return;

}
void Print(Node** start) {
    Node* ptr;
    ptr = *start;
    while (ptr != NULL) {
        cout << "\t" << ptr->data;
        ptr = ptr->next;
    }
    return;
}
int main() {
    Node* head = NULL;
    Create(&head, 5);
    Create(&head, 10);
    Create(&head, 15);
    Create(&head, 20);
    Insert_beg(&head, 100);
    Insert_end(&head, 600);

    Print(&head);
}