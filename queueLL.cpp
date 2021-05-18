#include<bits/stdc++.h>

using namespace std;

class Queue;

class Node{                             // node class
    int value;                          // node value
    Node* next;                         // pointer to next node
    public:                             
    Node(int v){value = v; next = NULL;} // constructor
    friend class Queue;     // friend class          
};

class Queue{                             // queue class
     Node *head, *tail;                   // pointers to head and tail
public:
     Queue(){
            head = tail = NULL;
        }                                 // constructor
        ~Queue(){};                       // destructor
     
     void append(int val){                 // definition of function append which appends at tail
        Node* n = new Node(val);
        if(head == NULL && tail == NULL){
            head = tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
     }

     int get(){                            // definition of function get, which returns value at head
        return head->value;
     }
    
};

int main(){
    
    Queue q;
    q.append(1);
    q.append(2);
    cout<<q.get()<<endl;

    return 0;
}