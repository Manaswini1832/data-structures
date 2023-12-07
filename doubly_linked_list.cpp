#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* prev = NULL;
    Node* next = NULL;
};

void InsertAtHead(int data, Node** root){
    Node* newNode = new Node;
    newNode -> data = data;
    
    if(*root == NULL){
        *root = newNode;
        return;
    }
    
    newNode -> next = *root;
    (*root) -> prev = newNode;
    *root = newNode;
    return;
}

void InsertAtTail(int data, Node** root){
    
    Node* newNode = new Node;
    newNode -> data = data;
    
    //edge case
    if(*root == NULL){
        *root = newNode;
        return;
    }
    
    //traverse to end 
    Node* temp = *root;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    
    //append newNode
    newNode -> prev = temp;
    temp -> next = newNode;
    return;

}

void Print(Node* root){
    Node* temp = root;
    cout << "Printing the list" << endl;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
    return;
}

void ReversePrint(Node* root){
    //traverse till the end
    Node* temp = root;
    while(temp->next != NULL){
        temp = temp -> next;
    }

    //now reverse print
    cout << "Reverse printing the list" << endl;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> prev;
    }
     cout << "NULL" << endl;
    
    return;
}

int main()
{
    Node* root;
    InsertAtHead(2, &root);
    InsertAtHead(4, &root);
    InsertAtHead(6, &root);
    InsertAtHead(8, &root);
    InsertAtTail(10, &root);
    Print(root);
    
    ReversePrint(root);
    return 0;
}
