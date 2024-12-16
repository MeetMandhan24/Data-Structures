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
        next = NULL ;
        prev = NULL ;
    }
};

class DoublyLL {
    public : 
    int count ;
    Node* head;
    Node* tail;
    
    DoublyLL (){
        count = 0;
        head = NULL;
        tail = NULL;
    }

    int addatbegin (int val ){
        Node* n = new Node (val);
        count ++;

        if (head == NULL ){
            head = n ;
            tail = n;
            return 0;
        }

        n -> next = head;
        head -> prev = n;
        head = n;
        return 0;
    }

    int addatend (int val){
        Node* n = new Node (val);
        count ++;
        if (head == NULL){
            head = n;
            tail = n;
            return 0;
        }

        tail -> next = n;
        n -> prev = tail ;
        tail = n;
        return 0;
    }

    int removeatstart (){
        if (head == NULL ){
            cout << "empty" << endl;
            return -1;
        }

        if (head == tail){
            delete head;
            head = NULL;
            tail = NULL;
            count --;
            return 0;
        }

        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
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
        tail -> next = NULL;
        delete temp;
        count --;
        return 0;
        
    }
    
    int addatpos (int val, int pos ){
        if (pos > count + 1 || pos < 1 ){
            cout << "invalid" <<endl;
            return -1;
        } 
        if (pos == 1){
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
        Node* n = new Node (val);
        n -> next = temp -> next -> next;
        temp -> next -> next -> prev = n;
        temp -> next = n;
        n -> prev = temp;
        count ++;
        return 0;
    }
    
    int delatpos (int pos ){
        if (pos > count || pos < 1){
            cout << "List Empty " << endl;
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
    
    bool search (int target ){
        if (head == NULL ){
            return false;
        }

        Node* temp = head;
        while (temp != NULL ){
            if (temp -> data == target){
                return true;
            }

            temp = temp -> next;
        }

        return false;
    }

    void display (){

        if (head == NULL){
            cout << "Empty" << endl;
            return ;
        }
        Node* temp = head ;
        while (temp != NULL ){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }


};

int main()
{
    DoublyLL ll;
    ll.addatbegin(1);
    ll.addatend(2);
    ll.addatend(3);
    ll.removeatstart();
    ll.removeatstart();
    ll.removeatend();
    ll.addatpos(1,1);
    ll.addatpos(2,1);
    ll.addatpos(4,2);
    ll.delatpos(3);
    ll.display();
    return 0;
}