#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void Create(Node** start, int new_data) {
    Node* ptr;
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if (*start == NULL) {
        *start = new_node;
        return;
    }
    ptr = *start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return;
}

void Insert_beg(Node** start, int new_data) {
    Node* new_node = new Node();
    new_node->next = *start;
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
    ptr->next = new_node;
    new_node->data = new_data;
    return;
}

void Insert_before(Node** start, int new_data, int value) {
    Node* ptr, * tempptr;
    Node* new_node = new Node();
    new_node->data = new_data;
    ptr = *start;
    while (ptr->data != value) {
        tempptr = ptr;
        ptr = ptr->next;
    }
    tempptr->next = new_node;
    new_node->next = ptr;

    return;

}


void Insert_after(Node** start, int new_data, int value) {
    Node* ptr, * tempptr;
    Node* new_node = new Node();
    new_node->data = new_data;
    ptr = *start;
    tempptr = ptr;
    while (tempptr->data != value) {
        tempptr = ptr;
        ptr = ptr->next;
    }
    tempptr->next = new_node;
    new_node->next = ptr;

    return;

}

void Delete_beg(Node** start) {
    Node* ptr;
    ptr = *start;
    *start = (*start)->next;
    delete ptr;

    return;
}

void Delete_end(Node** start) {
    Node* ptr, * tempptr;
    ptr = (*start);
    while (ptr->next != NULL) {
        tempptr = ptr;
        ptr = ptr->next;
    }
    tempptr->next = NULL;
    delete ptr;

    return;
}
void Delete_before(Node** start, int value) {
    Node* ptr, * tempptr;
    ptr = *start;
    while (ptr->data != value) {
        tempptr = ptr;
        ptr = ptr->next;
    }
    tempptr->next = ptr->next;
    delete ptr;

    return;
}



void Delete_after(Node** start, int value) {
    Node* ptr, * tempptr;
    ptr = *start;
    tempptr = ptr;
    while (tempptr->data != value) {
        tempptr = ptr;
        ptr = ptr->next;
    }
    tempptr->next = ptr->next;
    delete ptr;

    return;
}

void Sort(Node** start) {
    Node* ptr1, * ptr2;
    int temp;
    ptr1 = (*start);
    while (ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return;
}

void Reverse(Node** start) {
    Node* curr = *start, * prev = NULL, * next2 = NULL;
    while (curr != NULL) {
        next2 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next2;
    }
    *start = prev;

}


void Print(Node* node) {
    while (node != NULL) {
        cout << node->data;
        node = node->next;

    }
}


int main() {
    Node* head = NULL;
    Create(&head, 7);
    Create(&head, 6);
    Create(&head, 15);
    Insert_beg(&head, 100);
    Insert_end(&head, 600);
    Insert_before(&head, 569, 600);
    Insert_after(&head, 200, 6);
    Delete_beg(&head);
    Delete_end(&head);
    Delete_before(&head, 569);
    Delete_after(&head, 200);
    Sort(&head);
    Reverse(&head);

    Print(head);
}