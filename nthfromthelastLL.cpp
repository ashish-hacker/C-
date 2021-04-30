#include <bits/stdc++.h>

// Finding the nth node from the last of the Linked List

using namespace std;

class node{
    public:
    int data;
    node* next = NULL;
    node(int val){
        data = val;
    }
};
void print(node* head){
    node* n = head;
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}
node* nthlast(node* head, int k){
    int n = 0;
    node* temp = head;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0; i < n-k; i++){
        temp = temp->next;
    }
    return temp;
}

node* recReverse(node*head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* tempHead = recReverse(head->next);
    node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return tempHead;
}


void deleteANodeAtMiddle(node* head){

}


int main(){
    node* head = new node(1);
    node* f = new node(2);
    head->next = f;
    node* s = new node(3);
    f->next = s;
    node* third = new node(4);
    s->next = third;
    print(head);
    node* n = nthlast(head, 2);
    cout<<n->data<<endl;
    print(head);
    head = recReverse(head);
    print(head);
    return 0;
}
