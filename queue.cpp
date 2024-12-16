// ENQUEUE DEQUEUE 
#include<iostream>
using namespace std;

class Node {
    public : 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class queuell {
    public : 
    int count ;
    Node* front;
    Node* rear;

    queuell () {
      count = 0;
      front = NULL;
      rear = NULL;
    }

    bool isEmpty (){
        return front == NULL;
    }

    int enqueue (int val){
        count ++;
        Node* n = new Node (val);
        if (isEmpty()){
            front = n;
            rear = n;
            return 0;
        }

        rear -> next = n;
        rear = n;
        return 0;
    }

    int dequeue (){
        if(isEmpty()){
            cout << "List Empty " << endl;
            return -1;
        }
        
        int a = front -> data;
        Node* temp = front;
        front = front -> next;
        delete temp;
        return a;
    }

    void display (){
        if(isEmpty()){
            cout << "List Empty." << endl;
            return;
        }

        Node* temp = front ;
        while (temp != NULL ){
            cout << temp -> data << " ";
            temp = temp -> next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    queuell queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.dequeue();
    queue.display();
    return 0;
}