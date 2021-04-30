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

    
    public:
    node*head;
    node*tail;
    //constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insertAthead(int value){
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
        if(head == NULL){
            head = new node(value);
            return;
        }
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
        // check for cycle in the linkedlist
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
    void reverse(){
        // reverses the linkedlist
        node* current = head;
        node* previous = NULL;
        node* next;
        while(current != NULL){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    node* recReverse(node* thead){
        if(thead == NULL || thead->next == NULL){
            return thead;
        }
        node* shead = recReverse(thead->next);
        node* temp = thead->next;
        temp->next = thead;
        thead->next = NULL;
        return shead;
    }
    void recR(){
        head = recReverse(head);
    }
    node* midpoint(){
        if(head == NULL || head->next == NULL){
            return head;
        }
        node* slow = head;
        node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void appendK(int n, int k){
        if(k >= n) return;
        node* curr = head->next;
        node* prev = head;
        node* ftail;
        node* fhead;
        for(int i = 0; i < n-2; i++){
            if(i == n-k-1){
                ftail = prev;
                fhead = curr;
            }
            curr = curr->next;
            prev = prev->next;
        }
        
        ftail->next = NULL;
        curr->next = head;
        head = fhead;
    }
    void evenAfterOdd(){
        // Arranges the numbers even after all odd
        node* even = new node(1);
        node* t = even;
        node* odd = new node(0);
        node* h = odd;
        node* temp = head;
        while(temp != NULL){
            if(temp->data % 2 == 0){
                even->next = new node(temp->data);
                even = even->next;
            }
            else{
                odd->next = new node(temp->data);
                odd = odd->next;
            }
            temp = temp->next;
        }
        node* c = h;
        while(c->next != NULL){
            c = c->next;
        }
        c->next = t->next;
        head = h->next;
    }
};
node* merge(node* a, node* b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    // current new head
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}



int main(){
    
    LinkedList L;
    L.insertAthead(9); // insert a node at the head of the linkedlist
    L.insertAthead(8);
    L.insertAthead(7); 
    
    L.insertAthead(5); // insert a node at the end 
    //L.insertAtKthPosition(2, 100); // which position to insrt at and the value

    L.print(); // prints the elements of the linkedlist
    //L.reverse(); //reverses the list iteratively
   
    //L.recR(); //recursively reverse the list
    
    // check for cycle
    /*if(L.checkCycle()){
        cout<<"Cycle present";
    }
    else cout<<"Cycle not present";*/
    node* mid = L.midpoint();
    cout<<"Mid-element is: "<<mid->data<<endl;

    LinkedList L1;
    L1.insertAtEnd(10);
    L1.insertAtEnd(11);
    L1.insertAtEnd(211);
    L1.insertAtEnd(1022);
    L1.insertAtEnd(1);
    L1.insertAtEnd(2);
    L1.insertAtEnd(3);
    L1.insertAtEnd(4);
    L1.print();
    //L1.head = merge(L1.head, L.head);
    //L1.appendK(8, 4);
    L1.evenAfterOdd();
    L1.print();
    return 0;
}