#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

//Node &y is like passing same variable to another function and *y is passing pointer of the variable and 
//if one pointer is holding the address of another variable then when passed 
// a new variable is created then this new variable stores the value of adress

//appened at start
void addAtHead(int data, node*& head) {
    node* elem = new node(data);
    elem->next = head;
    head = elem;
}

//travese and print 
void printLinkedList(node*& head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


//add at end
void appenedAtEnd(int data, node*& head) {
    node* temp = head;
    if (head == NULL) {
        addAtHead(data, head);
        return;
    }
    node* n = new node(data);

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;

}
//nth element from last
int getNthFromLast(node*& head, int n) {
    if (n <= 0) return -1;
    int len = 1;
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    temp = head;
    len = len - n;
    if (len < 0) return-1;
    while (len--) {
        temp = temp->next;
    }
    return temp->data;
}
//get the size of the linked list
int getsize(node* head) {
    int n = 0;
    while (head != NULL) {
        n++;
        head = head->next;
    }
    return n;
}
int getJoiningUnit(node* a, node* b, int n) {
    while (n--) {
        a = a->next;
    }
    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a->data;
}
//find the joining point in list
int getJoiningPoint(node* heada, node* headb) {
    int a = getsize(heada);
    int b = getsize(headb);
    if (a > b) {
        return getJoiningUnit(heada, headb, a - b);
    }
    return getJoiningUnit(headb, heada, b - a);
}

void deleteElem(node*& head, int val) {
    node* temp = head;
    node* todelete = NULL;
    if (temp->data == val) {
        todelete = head;
        head = temp->next;
        delete todelete;
        return;
    }
    while (temp->next->data != val) {
        temp = temp->next;
    }
    todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    return;
}

//reverse the linked list
void reverseLinkedList(node*& head) {
    node* temp = head;//pointing to the head
    node* toadd = NULL;
    node* second = head->next;
    temp->next = NULL;
    while (second != NULL) {
        toadd = second;
        second = second->next;
        toadd->next = temp;
        temp = toadd;
    }
    head = temp;
}
int main() {
    node* head = NULL;
    appenedAtEnd(1, head);
    appenedAtEnd(4, head);
    appenedAtEnd(2, head);
    appenedAtEnd(3, head);
    printLinkedList(head);
    reverseLinkedList(head);
    printLinkedList(head);
}