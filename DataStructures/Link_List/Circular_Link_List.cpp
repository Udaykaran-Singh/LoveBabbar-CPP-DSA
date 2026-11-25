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


void insertNode(Node* &head, int element, int d){

    // Empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        temp->next = temp;
    }
    else{
        // Non-empty list
        // assuming that the element is present in the list

        Node* curr = head;

        while(curr->data != element){
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node*temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &head, int value){
    // empty list
    if(head == NULL){
        cout<<"List is empty, Please check again. "<<endl;
        return;
    }
    else{
        // assuming that "value" is present in the Linked list.
        Node* prev = head;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = prev->next;              // curr;
            curr = curr->next;
        }

        // nodes = 1
        if(curr == prev){
            head = NULL;
        }

        // nodes > 2
        if(head == curr){
            head = head->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


void print(Node* &head){

    Node* temp = head;

    // empty list
    if(head == NULL){
        cout<<"List is empty. "<<endl;
        return;
    }

    do{
        cout<<head->data<<" ";
        head = head->next;
    }while(head!= temp);
    cout<<endl<<endl;
}

int main(){

    Node* head = NULL;

    // Node* node1 = new Node(10);
    // head = node1;

    // inserting in empty list
    insertNode(head, 10, 10);
    insertNode(head, 10, 100);
    insertNode(head, 10, 15);
    insertNode(head, 15, 50);

    print(head);

    deleteNode(head, 10);
    print(head);


    return 0;
}