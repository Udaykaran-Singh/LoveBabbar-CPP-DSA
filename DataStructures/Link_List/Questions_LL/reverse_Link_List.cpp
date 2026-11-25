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



void reversell(Node* &head){

    if (head == NULL || head->next == NULL){
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;

    while(current != NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;

    }

    head = prev;
}

void recrevLL(Node* &head, Node* &current , Node* &prev){   
                        
                        // recursive function

    // base case
    if(current == NULL){
        head = prev;
        return;
    }

    // recursive call
    recrevLL(head, current->next, current);
    current->next = prev;
}


Node* reverse1(Node* &head){

    // base case
    if(head == NULL ||head->next == NULL){
        return head;
    }

    // recursion
    Node* chotaHead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

   return chotaHead;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;

    Node* tail = node1;    


    insertAtTail(tail, head, 12);
    insertAtTail(tail, head, 15);
    insertAtTail(tail, head, 19);
    print(head);

    // // iteration
    // reversell(head);
    // print(head);
    // cout<<"Head :"<<head->data<<endl<<endl;

    // // recursively
    // Node* curr = head;
    // Node* prev = NULL;
    // recrevLL(head, curr, prev);
    // print(head);
    // cout<<"Head :"<<head->data<<endl<<endl;

    // recursion by node method
    head = reverse1(head);
    print(head);
    cout<<"Head :"<<head->data<<endl;

}