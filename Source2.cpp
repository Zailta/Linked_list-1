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

    Print(&head);
}