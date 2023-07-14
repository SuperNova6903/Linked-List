#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
} node;

node* createList(int data){
    node* head;
    head = (node*)malloc(sizeof(node));
    head->data = data;
    head->next = NULL;
    return head;
}

void showList(node* head){
    node* ptr;
    ptr = head;
    cout<<"Linked List: ";
    while(ptr->next != NULL){
        cout<<ptr->data<<", ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
}

void insertAtEnd(node* head, int data){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    node* ptr;
    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

node* insertAtBeginning(node* head, int data){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

void insertAtIndex(node* head, int data, int index){
    if(index==0){
        cout<<"Invalid index: Can't use this command to insert at head"<<endl;
        return;
    }
    node* ptr = head;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    index--;
    while(index--){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void deleteList(node* head){
    node* ptr;
    ptr = head;
    node* temp;
    while(ptr->next != NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(ptr);
}

void deleteAtEnd(node* head){
    node* ptr = head;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    node* temp = ptr->next;
    free(temp);
    ptr->next = NULL;
}

node* deleteAtBeginning(node* head){
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deleteAtIndex(node* head, int index){
    if(index==0){
        cout<<"Invalid index: Can't use this command to delete at head"<<endl;
        return;
    }
    node* ptr = head;
    index--;
    while(index--){
        ptr=ptr->next;
    }
    node* temp = ptr->next;
    ptr->next = ptr->next->next; 
    free(temp);
}

int main(){
    node* head = createList(10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtEnd(head, 60);
    showList(head);
    head = insertAtBeginning(head, 25);
    insertAtIndex(head, 17, 4);
    showList(head);
    head = deleteAtBeginning(head);
    deleteAtEnd(head);
    deleteAtIndex(head, 4);
    showList(head);
    deleteList(head);
}