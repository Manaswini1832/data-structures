#include <iostream>

using namespace std;

/*
Push operation
Best and avg cases : O(1)
Worst case : O(n) - occurs if array overflows and we need to copy it to a whole new array that's double the previous size
*/

class MyStack{
    private :
        int arr[10];
        int topInd = -1;
    
    public :
        void push(int num){
            int len = sizeof(arr)/sizeof(arr[0]);
            if(topInd < len-1){
                topInd++;
                arr[topInd] = num;
                return;
            }
            
            cout << "Stack is full" << endl;
        }
        
        void pop(){
            topInd--;
            return;
        }
        
        int top(){
            return arr[topInd];
        }
        
        bool isEmpty(){
            if(topInd == -1){
                return true;
            }
            
            return false;
        }
        
        void print(){
            for(int i = 0; i <= topInd; i++){
                cout << arr[i] << endl;
            }
            cout << "DONE" << endl;
            return;
        }
};

int main()
{
    
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
