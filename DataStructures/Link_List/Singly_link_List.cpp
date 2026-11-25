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
                this->next = NULL;
            }
            delete next;
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
        tail = temp;
    }

}

void insertAtPosition (Node* &tail, Node* &head, int position, int d){  

    if(position == 1){
        insertAtHead(tail, head, d); 
        return;
    }
    
    Node* temp = head;
    int cnt =1;
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
    temp -> next = nodeToInsert;

}

void delAtPosition(Node* &tail, Node* &head, int position){

    Node* temp = head;

    if(position == 1){
        head = temp->next;
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
    temp->next = (del)->next;

    del->next = NULL;
    
    delete del;

    if(temp->next == NULL){
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


int main(){

    Node* node1 = new Node(10);

    // head pointer to node_1
    Node* head = node1;

    // insertAtHead(tail, head, 12);
    // insertAtHead(tail, head, 15);

    // Tail pointer to node_1
    Node* tail = node1;    

    // print(head);

    insertAtTail(tail, head, 12);
    insertAtTail(tail, head, 15);
    insertAtTail(tail, head, 19);
    
    insertAtPosition(tail, head, 3, 3);
    // insertAtPosition(tail, head, 1,100);
    // insertAtPosition(tail, head, 6,999);
   
    print(head);

    delAtPosition(tail, head, 5);

    print(head);


    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;

}