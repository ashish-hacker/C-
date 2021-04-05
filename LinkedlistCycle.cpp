#include <bits/stdc++.h>

using namespace std;


class node{
    public:
    int data;
    node*next;

    node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{

    node*head;
    node*tail;
    public:
    //constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insertAtHead(int value){
        if(head == NULL){
            head = new node(value);
            return;
        }
        node* newNode = new node(value);
        newNode->next = head;
        head = newNode;
    }
    void print(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    void insertAtEnd(int value){
        node* newNode = new node(value);
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    void insertAtKthPosition(int k, int value){
        node* newNode = new node(value);
        node * temp = head;
        while(k>1){
            temp = temp->next;
            k--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    bool checkCycle(){
        if(head == NULL) return false;
        node* slow = head;
        node* fast = head->next;
        while(slow != fast){

            if(fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};




int main(){
    
    LinkedList L;
    L.insertAtHead(9);
    L.insertAtHead(8);
    L.insertAtHead(7);
    L.insertAtEnd(6);
    L.insertAtEnd(5);
    L.insertAtKthPosition(2, 0);

    L.print();
    if(L.checkCycle()){
        cout<<"Cycle present";
    }
    else cout<<"Cycle not present";
    return 0;
}