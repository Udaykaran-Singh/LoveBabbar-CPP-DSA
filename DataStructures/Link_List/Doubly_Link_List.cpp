#include<iostream>
using namespace std;

class Node {
    public:
        Node* previous;
        int data;
        Node* next;

        // constructor
        Node(int d){
            this->previous = NULL;
            this->data = d;
            this->next = NULL;
        }

        // destructor
        ~Node(){
            int value = this->data;
            // memory free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            if(this->previous != NULL){
                delete previous;
                this->previous= NULL;
            }
            cout<<"memory is free for node with data "<<value<<endl;
        }
};


void insertAtHead(Node* &tail, Node* &head, int d) {

    if(head == NULL){
        // if there is no node existing
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        // new node created
        Node* temp = new Node(d);
        temp -> next = head;
        head->previous = temp;
        head = temp;
    }

}

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
        temp->previous = tail;
        tail = temp;
    }

}

void insertAtPosition (Node* &tail, Node* &head, int position, int d){  

    if(position == 1){
        insertAtHead(tail, head, d); 
        return;
    }
    
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    // Inserting at end
    if(temp->next == NULL){
        insertAtTail(tail, head, d);
        return;
    }

    // creating a node for d
    Node* nodeToInsert = new Node(d);

    // putting at given position
    nodeToInsert -> next = temp -> next;
    (temp->next)->previous = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert->previous = temp;

}

void delAtPosition(Node* &tail, Node* &head, int position){

    Node* temp = head;

    if(position == 1){
        head = temp->next;
        head->previous = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* del;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp-> next;
        cnt++;
    }

    del = temp->next; 
    temp->next = del->next;

    if(temp->next != NULL){
        del->next->previous = temp;
    }

    del->next = NULL;
    del->previous = NULL;
    
    delete del;

    if(temp->next == NULL){
        tail = temp;
    }


}


int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    
    while(temp != NULL){
        len++;
        temp = temp->next; 
    } return len;
}

void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl<<endl;

}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    // Node* node1 = new Node(10);
    // head = tail = node1;

    insertAtHead(tail, head, 9);
    insertAtHead(tail, head, 7);
    insertAtHead(tail, head, 8);

    insertAtTail(tail, head, 11);
    insertAtTail(tail, head, 15);

    insertAtPosition(tail, head, 2, 100);
    insertAtPosition(tail, head, 1, 99);
    insertAtPosition(tail, head, 8, 999);
    
    
    cout<<"Length : "<<getLength(head)<<endl;
    print(head);

    delAtPosition(tail, head, 8);

    cout<<"Length : "<<getLength(head)<<endl;
    print(head);


    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;

    return 0;
}