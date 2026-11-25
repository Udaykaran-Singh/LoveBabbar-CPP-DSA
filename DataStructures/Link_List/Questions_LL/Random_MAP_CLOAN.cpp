#include<iostream>
#include<map>
using namespace std;


class Node {
    public:
        int data;
        Node* next;
        Node* random;

        // constructor
        Node(int d){
            this -> data = d;
            this -> next = NULL;
            this -> random = NULL;
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

    int count = 1;
    
    while(count < 22 && temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
        count++;
    }
    cout<<endl<<endl;

}

void print_ran(Node* &head) {
    Node* temp = head;

    int count = 1;
    
    while(count < 22 && temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->random; 
        count++;
    }
    cout<<endl<<endl;

}


int main(){
    map<Node*, Node*> check_ran;

    // making node in normal fashion
    Node* node = new Node(9);

    Node* head = node;
    Node* tail = node;
    Node* temp = head;


    insertAtTail(tail, head, 1);
    insertAtTail(tail, head, 8);
    insertAtTail(tail, head, 9);
    insertAtTail(tail, head, 131);
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 20);


    // filling randoms
    temp->random = head->next->next;

    temp = temp->next;
    temp->random = temp->next->next;

    temp = temp->next;
    temp->random = tail;

    temp = temp->next;
    temp->random = temp->next;

    temp = temp->next;
    temp->random = temp->next->next;

    temp = temp->next;
    temp->random = head;

    temp = temp->next;
    temp->random = NULL;


    // printing
    cout<<"Normal :"<<endl;
    print(head);
    cout<<"Random :"<<endl;
    print_ran(head);
    print_ran(head->next);


    /*       // with using map           // time -> O(n), spact ->O(n)

    // cloned Link List next columns 
    // maping from original node to cloned node done simultaneously
    Node* clone_head = NULL;
    Node* clone_tail = NULL;
    temp = head;

    while(temp != NULL){
        Node* newnode = new Node(temp->data);
        check_ran[temp] = newnode;
        if(clone_head == NULL){
            clone_head = newnode;
            clone_tail = newnode;
        }else{
            clone_tail->next = newnode;
            clone_tail = newnode;
        }
        
        temp = temp->next;
    }

    // with use of mapping cloning random columns
    temp = head;
    Node *clo_temp = clone_head;

    while(temp != NULL){
        clo_temp->random = check_ran[temp->random];
        temp = temp->next;
        clo_temp = clo_temp->next;
    }


    // printing cloned Link List
    cout<<"Clone Normal :"<<endl;
    print(clone_head);
    cout<<"Clone Random :"<<endl;
    print_ran(clone_head);
    print_ran(clone_head->next);

    */


    // makind list.           // time -> O(n), spact ->O(1)
    temp = head;
    while(temp != NULL){
        Node* newnode = new Node(temp->data);
        newnode->next = temp->next;
        temp->next = newnode;
        temp = temp->next->next; 
    }
    print(head);

    // maping using logic.
    temp = head;
    while(temp != NULL){
        if (temp->random != NULL){
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    // sepration clone and real.
    temp = head;
    Node* Clone_head = temp->next;
    Node* Clone_tail = temp->next;

    while(Clone_tail->next != NULL ){
        temp->next = temp->next->next;
        temp = temp->next;
        Clone_tail->next = temp->next;
        Clone_tail = Clone_tail->next;
    }
    temp->next = NULL;

    // printing cloned Link List.
    cout<<"Clone Normal :"<<endl;
    print(Clone_head);
    cout<<"Clone Random :"<<endl;
    print_ran(Clone_head);
    print_ran(Clone_head->next);

    
   
}