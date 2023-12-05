#include <iostream>

using namespace std;

/*
- Print list
- Print forward list with recursion
- Print backward list with recursion
- Insert Node at end
- Insert node at beginning 
- Insert node at a position
- Delete node from a position
- Reverse linked list with iteration
- Reverse linked list with recursion
*/

struct Node{
    int data;
    Node* next;
};

void PrintList(Node* root){
    Node* temp = root;
    
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << " NULL" << endl;
}

void PrintForwardRecur(Node** root){
    if(*root == NULL){
        return;
    }
    cout << (*root) -> data << endl;
    PrintForwardRecur(&((*root) -> next));
    
}

void PrintBackwardRecur(Node** root){
    if(*root == NULL){
        return;
    }
    PrintBackwardRecur(&((*root) -> next));
    cout << (*root) -> data << endl;
    
}

void InsertNode(Node** root, int data){
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;
    
    if((*root) == NULL){
        (*root) = newNode;
        return;
    }
    
    Node* temp = (*root);
    while(temp->next != NULL){
        temp = temp -> next;
    }
    
    temp -> next = newNode;
    return;
}

void InsertAtBeginning(Node** root, int data){
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = (*root);
    (*root) = newNode;
    return;
}

void InsertAtPos(Node** root, int data, int pos){
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;
    if(*root == NULL){
        //empty list
        *root = newNode;
        return;
    }
    
    Node* prev;
    Node* temp;
    Node* curr = *root;
    
    for(int i = 0; i < pos; i++){
        if(curr -> next == NULL){
            //append element to end of list 
            curr -> next = newNode;
            return;
        }
        temp = curr;
        curr = curr -> next;
        prev = temp;
    }
    
    newNode -> next = curr;
    prev -> next = newNode;
    return;
}

void DeleteAtPos(Node** root, int pos){
    if(*root == NULL){
        cout << "Can't delete elements from an empty list" << endl;
        return;
    }
    
    if(pos == 1){
        //delete first element
        *root = (*root) -> next;
        return;
    }
    
    Node* prev;
    Node* temp;
    Node* curr = *root;
    for(int i = 1; i < pos; i++){
        if(curr -> next == NULL){
            cout << "Can't delete elements from out of the list" << endl;
        }
        temp = curr;
        curr = curr -> next;
        prev = temp;
    }
    
    prev -> next = curr -> next;
    free(curr);
    return;
}

void ReverseIter(Node** root){
    Node* prev = *root;
    Node* curr = (*root) -> next;
    Node* temp;
    while(curr != NULL){
        temp = curr -> next;
        curr -> next = prev;
        prev = prev = curr;
        curr = temp;
    }
    
    ((*root) -> next) = NULL;
    *root = prev;
    return;
}

void ReverseRecur(Node** actualRoot, Node* p){
    if(p -> next == NULL){
        *actualRoot = p;
        return;
    }
    ReverseRecur(actualRoot,  p -> next);
    Node* q = p -> next;
    q -> next = p;
    p -> next = NULL;
    return;
}


int main()
{
    Node* root;
    
    InsertNode(&root, 2);
    InsertNode(&root, 4);
    InsertNode(&root, 6);
    InsertNode(&root, 8);
    InsertNode(&root, 10);
    PrintList(root);
    
    ReverseRecur(&root, root);
    PrintList(root);
    return 0;
}
