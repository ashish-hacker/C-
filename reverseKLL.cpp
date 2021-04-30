#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

node* reverse(node* head, node* tail){
    node* current = head;
    node* n;
    node* previous = tail->next;
    while(current != tail){
        n = current->next;
        current->next = previous;
        previous = current;
        current = n;
    }
    current->next = previous;
    head = current;

    return head;
}
node* forwardk(node* head, int k){
    node* temp = head;
    while(temp != NULL && k != 1){
        temp = temp->next;
        k--;
    }
    return temp;
}

int main(){
    node* head = new node(1);
    node* one = new node(2);
    node* two = new node(3);
    node* three = new node(4);
    head->next = one;
    one->next = two;
    two->next = three;
    node* f = new node(5);
    node* fiv = new node(6);
    node* six = new node(7);
    node* sev = new node(8);
    node* e = new node(9);
    three->next = f;
    f->next = fiv;
    fiv->next = six;
    six->next = sev;
    sev->next = e;
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
    cout<<endl;
    node* currHead = head;
    node* currTail;
    node* nextTail;
    node* tail;
    node* x;
    node* y;
    int n = 9, k = 3;
    int it = n/k;
    for(int i = 0; i < it; i++){
        // get the current tail end of the segment
        currTail = forwardk(currHead, k);
        nextTail = forwardk(currTail->next, k);
        y = currTail->next;
        // store the currHead node addres to a temporary variable
        x = currHead;
        // reverse the segment
        if(i == 0) head = currTail;
        if(i == 3) tail = currHead;
        currHead = reverse(currHead, currTail);
    
        // connect the tail end of next segment to the end of this segment which is the current head node after reversing the segment
        currTail = x;
        currTail->next = nextTail;
        currHead = y;
        
    }
    
    temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}