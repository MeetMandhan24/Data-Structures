#include<iostream>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class singlell {
    public : 
    int count ;
    Node* head;
    Node* tail;

    singlell(){
        count = 0;
        head = NULL;
        tail = NULL;
    }

    int addatbegin (int val){
        count ++;
        Node* n = new Node(val);
        if (head == NULL){
            head = n ;
            tail = n;
            return 0;
        }

        n -> next = head;
        head = n;
        return 0;
    }

    int addatend (int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = n;
            tail = n;
            count ++;
            return 0;
        }

        tail -> next = n;
        tail = n;
        count ++;
        return 0;
    }

    int removeatbegin (){
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

        Node* temp = head;
        head = head -> next;
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

        Node* temp = head; 
        while (temp -> next -> next != NULL){
            temp = temp -> next;
        }
        delete tail;
        tail = temp;
        tail -> next = NULL;
        count --;
        return 0;
    }

    int addatpos (int val, int pos ){
        if (pos > count + 1 || pos < 1){
            cout << "invalid" << endl;
            return -1;
        }
        if (head == NULL || pos == 1){
            addatbegin(val);
            return 0;
        }
        if(pos == count ){
            addatend(val);
            return 0;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i ++){
            temp = temp -> next;
        }

        Node*n = new Node(val);
        n -> next = temp -> next;
        temp -> next = n;
        count ++;
        return 0;  
    }

    int delatpos (int pos ){
        if (pos > count || pos < 1){
            cout << "invalid" << endl;
            return -1;
        }

        if (pos == 1){
            removeatbegin();
            return 0;
        }
        if (pos == count){
            removeatend();
            return 0;
        }

        Node* temp = head ;
        for (int i = 1; i < pos - 1; i ++){
            temp = temp -> next;
        }

        Node* temp2 = temp -> next;
        temp -> next = temp2 -> next;
        delete temp2;
        count --;
        return 0;
    }

    bool search (int target){
        if (head == NULL){
            return false;
        }

        Node* temp = head;
        while (temp != NULL){
            if (temp -> data == target ){
                return true;
            }
            temp = temp -> next;
        }

        return false;
    }

    void display (){
        if(head == NULL){
            cout << "Empty" << endl;
            return ;
        }

        Node* temp = head;
        while (temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    singlell ll;
    ll.addatbegin(1);
    ll.addatend(2);
    ll.addatend(3);
    ll.addatpos(4,3);
    ll.removeatbegin();
    ll.removeatend();
    ll.delatpos(1);
    ll.delatpos(1);
    ll.display();
    return 0;
}