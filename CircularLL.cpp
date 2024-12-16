#include<iostream>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }

    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
};

class circularll {
    public : 
    int count ;
    Node* head;
    Node* tail;

    circularll (){
        count = 0;
        head = NULL;
        tail = NULL;
    }

    int addatstart (int val){
        count ++;
        Node* n = new Node(val);
        if (head == NULL ){
            head = n;
            tail = n;
            return 0;
        }
        n -> next = head;
        tail -> next = n;
        n -> prev = tail;
        head -> prev = n;
        head = n;
        return 0;
    }

    int addatend (int val){
        count ++;
        Node* n = new Node (val);

        if (head == NULL ){
            head = n;
            tail = n;
            return 0;
        }

        tail -> next = n;
        n -> next = head;
        head -> prev = n ;
        n -> prev = tail ;
        tail = n;
        return 0;
    }

    int removeatstart(){
        if (head == NULL ){
            cout << "Empty." << endl ;
            return -1;
        }

        if (head == tail ){
            delete head;
            head = NULL;
            tail = NULL;
            count --;
            return 0;
        }

        Node* temp = head;
        head = head -> next;
        head -> prev = tail;
        tail -> next = head;
        delete temp;
        count --;
        return 0;
    }

    int removeatend (){
        if (head == NULL ){
            cout << "Empty" << endl;
            return -1;
        }

        if (head == tail ){
            delete head;
            head = NULL;
            tail = NULL;
            count --;
            return 0;
        }

        Node* temp = tail;
        tail = tail -> prev;
        tail -> next = head;
        head -> prev = head;
        delete temp;
        count --;
        return 0;
    }

    int addatpos (int val, int pos ){
        if (pos > count + 1 || pos < 1 ){
            return -1;
        }
        if (pos == 1){
            addatstart(val);
            return 0;
        }
        if (pos == count ){
            addatend(val);
            return 0;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i ++){
            temp = temp -> next;
        }

        Node* n = new Node (val);
        n -> next = temp -> next;
        temp -> next -> prev = n;
        temp -> next = n;
        n -> prev = temp;
        count ++;
        return 0;
    }

    int delatpos (int pos ){
        if (pos > count || pos < 1){
            return -1;
        }

        if (pos == 1){
            removeatstart();
            return 0;
        }

        if (pos == count ){
            removeatend();
            return 0;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i ++){
            temp = temp -> next;
        }

        Node* temp2 = temp -> next;
        temp -> next = temp2 -> next;
        temp2 -> next -> prev = temp;
        delete temp2;
        count --;
        return 0;
    }

    bool search (int target){
        if (head == NULL ){
            cout << "Empty" << endl;
            return false;
        }
        Node* temp = head;

        do {
            if (temp -> data == target){
                return true;
            }
            temp = temp -> next;
        }while (temp != NULL);

        return false;
    }
   
    void display (){
        if (head == NULL ){
            cout << "List empty." << endl;
            return ;
        }

        Node* temp = head;
        do {
            cout << temp -> data << " ";
            temp = temp -> next;
        }while (temp != head);

        cout << "NULL" << endl;
    }
};

int main()
{
    circularll ll;
    ll.addatstart(1);
    ll.addatstart(2);
    ll.addatstart(3);
    ll.addatend(4);
    ll.addatend(5);
    ll.removeatstart();
    ll.removeatstart();
    ll.removeatend();
    ll.addatpos(3,2);
    ll.addatpos(4,3);
    ll.delatpos(4);
    ll.delatpos(1);
    ll.display();
    return 0;
}