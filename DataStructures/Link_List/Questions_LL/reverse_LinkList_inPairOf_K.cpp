#include<iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* next;

        // constructor
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        // destructor
        ~Node(){
            int value = this->data;
            // memory free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"memory is free for node with data "<<value<<endl;
        }
};

void insertAtTail(Node* &tail, Node* &head, int d) {

    if(tail == NULL){
        // if there is no node existing
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        // new node created
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }

}

void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl<<endl;

}

Node* revByK(Node* &head, int k){

    // base case
    if(head == NULL){
        return NULL;
    }

    // step 1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2: recursion dekhlega aage ka
    if(next!= NULL){
        head->next = revByK(next, k);
    }

    // step 3: return head
    return prev;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;

    Node* tail = node1;    


    insertAtTail(tail, head, 12);
    insertAtTail(tail, head, 15);
    insertAtTail(tail, head, 19);
    insertAtTail(tail, head, 21);
    insertAtTail(tail, head, 115);
    insertAtTail(tail, head, 199);
    print(head);

    head = revByK(head, 4);
    print(head);

}