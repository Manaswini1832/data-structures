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

void ReverseDLL(Node** root){
    // inp : 8 6 4 2 NULL 
    // oup : 2 4 6 8 NULL 
    Node* temp = *root;
    Node* temp2;
    while(temp -> next != NULL){
        temp2 = temp -> next;
        temp -> next = temp -> prev;
        temp -> prev = temp2;
        temp = temp2;
    }
    
    temp2 = temp -> next;
    temp -> next = temp -> prev;
    temp -> prev = temp2;
    
    *root = temp;
    
    return;
}

int main()
{
    Node* root;
    InsertAtHead(2, &root);
    InsertAtHead(4, &root);
    InsertAtHead(6, &root);
    InsertAtHead(8, &root);
    Print(root);
    ReverseDLL(&root);
    Print(root);
    
    return 0;
}
