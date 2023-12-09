#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

class BinTree{
    public :
        
        void insert(int data, Node** root){
            
            Node* newNode = new Node();
            newNode -> data = data;
            
            if(*root == NULL){
                *root = newNode;
                return;
            }
            
            if(data <= (*root) -> data){
                insert(data, &((*root) -> left));
            }else{
                insert(data, &((*root) -> right));
            }
            return;
        }
        
        
        void preorder(Node* root){
            if(root == NULL) return;
            cout << root -> data << endl;
            preorder(root -> left);
            preorder(root -> right);
            return;
        }
        
        void inorder(Node* root){
            if(root == NULL) return;
            inorder(root -> left);
            cout << root -> data << endl;
            inorder(root -> right);
            return;
        }
        
        void postorder(Node* root){
            if(root == NULL) return;
            postorder(root -> left);
            postorder(root -> right);
            cout << root -> data << endl;
            return;
        }
        
        //Level order traversal
        void bfs(Node* root){
            if(root == NULL) return;
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* current = q.front();
                cout << current -> data << endl;
                if(current -> left != NULL) q.push(current -> left);
                if(current -> right != NULL) q.push(current -> right);
                q.pop();
            }
            return;
        }
        
        void dfs(Node* root){
            if(root == NULL) return;
            cout << root -> data << endl;
            dfs(root -> left);
            dfs(root -> right);
            return;
        }
        
        bool search(int data, Node* root){
            if(root == NULL) return false;
            if(root -> data == data) return true;
            if(data < root -> data){
                return search(data, root -> left);
            }else{
                return search(data, root -> right);
            }
        }
        
        Node* findMin(Node* root){
            if(root == NULL) return root;
            if(root -> left == NULL) return root;
            return findMin(root -> left);
        }
        
        Node* findMax(Node* root){
            if(root == NULL) return root;
            if(root -> right == NULL) return root;
            return findMax(root -> right);
        }
        
        int height(Node* root){
            if(root == NULL) return -1; // because by convention height of an empty tree is -1 and height of a leaf node is 0
            int leftLen = 1 + height(root -> left);
            int rightLen = 1 + height(root -> right);
            return max(leftLen, rightLen);
        }
        
        // bool isBST(Node* root){
        //     //do inorder and check if sorted
        // }
        
        Node* deleteNode(int data, Node** root){
            if(*root == NULL) return *root;
            
            if(data < (*root) -> data){
                (*root) -> left = deleteNode(data, &((*root) -> left));
            }else if(data > (*root) -> data){
                (*root) -> right = deleteNode(data, &((*root) -> right));
            }else{
                //no child
                if((*root) -> left == NULL && (*root) -> right == NULL){
                    delete *root;
                    *root = NULL;
                }
                
                //one child
                else if((*root) -> left == NULL){
                    Node* temp = *root;
                    *root = (*root) -> right;
                    delete temp;
                }
                
                else if((*root) -> right == NULL){
                    Node* temp = *root;
                    *root = temp;
                    delete temp;
                }
                
                
                //two children
                else{
                    Node* temp = findMin((*root) -> right);
                    (*root) -> data = temp -> data;
                    (*root) -> right = deleteNode(temp -> data, &((*root) -> right));
                }
            }
            return *root;
        }
        
        
};

int main()
{
    Node* root = NULL;
    BinTree bt;
    bt.insert(2, &root);
    bt.insert(5, &root);
    bt.insert(6, &root);
    bt.insert(9, &root);
    bt.insert(8, &root);
    bt.insert(1, &root);
    
    bt.inorder(root);
    
    root = bt.deleteNode(5, &root);
    cout << "======================" << endl;
    bt.inorder(root);
    
    return 0;
}
