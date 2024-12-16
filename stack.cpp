// PUSH POP PEEK DISPLAY

#include<iostream>
using namespace std;

class Node {
    public : 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL ;
    }
};

class stackll {
    public : 
    Node* top;
    int count ;
    stackll(){
        top = NULL;
        count = 0;
    }

    bool isEmpty (){
        return top == NULL;
    }

    int push (int val){
        count ++;
        Node* n = new Node (val);
        if(top == NULL){
            top = n;
            return 0;
        }

        n -> next = top;
        top = n;
        return 0;
    }

    int pop (){
        if(isEmpty()){
            return -1;
        }

        if (top -> next == NULL){
            int a = top -> data;
            delete top ;
            top = NULL;
            count --;
            return a;
        }
        
        Node* temp = top;
        int a = temp -> data;
        top = top -> next;
        delete temp;
        count --;
        return a;
    }
    
    int peek (){
        if(isEmpty()){
            cout << "Empty" << endl;
            return -1;
        }
        cout << top -> data << endl;
        return 0;

    }

    void display (){
        if (isEmpty()){
            cout << "Empty" << endl;
            return;
        }

        Node* temp = top;
        while (temp != NULL ){
            cout << temp -> data << " ";
            temp = temp -> next;
        }

        cout << "NULL" << endl;
    }
};


int main()
{
    stackll stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.peek();
    stack.display();
    return 0;
}