#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

class MyLinkedList{
    private :
        Node* root = NULL;
    
    public :
        void setRoot(Node* userRoot){
            root = userRoot;
            return;
        }
        
        void InsertAtBeg(int data){
            Node* newNode = new Node;
            newNode -> data = data;
            newNode -> next = root;
            root = newNode;
            return;
        }
        
        void RemoveFromBeg(){
            root = root -> next;
            return;
        }
        
        Node* getRoot(){
            return root;
        }
        
        void print(){
            Node* temp = root;
            cout << "Printing list" << endl;
            while(temp != NULL){
                cout << temp -> data << " -> ";
                temp = temp -> next;
            }
            
            cout << "NULL" << endl;
        }
};

class MyStack{
    private :
        MyLinkedList list;
    
    public :
        void push(int num){
            list.InsertAtBeg(num);
            return;
        }
        
        void pop(){
            list.RemoveFromBeg();
            return;
        }
        
        int top(){
            return list.getRoot() -> data;
        }
        
        bool isEmpty(){
            if(list.getRoot() == NULL){
                return true;
            }
            
            return false;
        }
        
        void print(){
            list.print();
            return;
        }
};

int main()
{
    Node* root;
    MyLinkedList ll;
    ll.setRoot(root);
    
    MyStack stack;
    stack.push(2);
    stack.push(3);
    stack.push(55);
    stack.print();
    stack.pop();
    stack.print();
    cout << stack.top() << endl;
    return 0;
}
