// Doubly-linked list:
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
void Delete_beg(Node** start) {
    Node* ptr;
    ptr = *start;
    *start = (*start)->next;
    (*start)->prev = NULL;
    delete ptr;

    return;
}
void Delete_end(Node** start) {
    Node* ptr;
    ptr = (*start);
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    (ptr->prev)->next = NULL;
    delete ptr;

    return;
}
void Delete_before(Node** start, int value) {
    Node* ptr, * temp;
    ptr = *start;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    temp = ptr->prev;
    ptr->prev = temp->prev;
    (temp->prev)->next = ptr;

    delete temp;

    return;
}
void Delete_after(Node** start, int value) {
    Node* ptr, * temp;
    ptr = *start;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    (temp->next)->prev = ptr;
    delete temp;

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
    Insert_before(&head, 200, 5);
    Insert_after(&head, 300, 200);
    Delete_beg(&head);
    Delete_end(&head);
    Delete_before(&head, 15);
    Delete_after(&head, 200);
    Print(&head);
}