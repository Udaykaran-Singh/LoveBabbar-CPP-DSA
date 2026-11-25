#include<iostream>
#include<map>
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

    int count = 1;
    
    while(count < 22 && temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
        count++;
    }
    cout<<endl<<endl;

}



Node* revLL(Node* &head){

    if(head == NULL){
        return NULL;
    }

    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(current != NULL){

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;

}

Node* add_LL( Node* &head1, Node* &head2, int carry){

    if(head1 == NULL && head2 == NULL && carry == 0){
        return NULL;
    }

    int sum = carry;
    if (head1 != NULL) {
        sum += head1->data;
        head1 = head1->next;
    }
    if (head2 != NULL) {
        sum += head2->data;
        head2 = head2->next;
    }

    Node* result = new Node(sum % 10);
    result->next = add_LL(head1, head2, sum / 10);
    
    return result;

}

Node* sum_no(Node* head1, Node* head2){

    int sum, carry = 0;
    Node* LL = NULL;
    Node* tail = NULL;
    
    while(head1 != NULL || head2 != NULL || carry != 0){
        sum = carry;
        if(head1 != NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        if (LL == NULL) {
            LL = newNode;
            tail = LL;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return LL;


}

int main(){
    Node* node1 = new Node(9);
    Node* node2 = new Node(3);

    Node* head1 = node1;
    Node* tail1 = node1;    

    Node* head2 = node2;
    Node* tail2 = node2;  


    // insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 9);


    // insertAtTail(tail2, head2, 3);
    insertAtTail(tail2, head2, 7);
    cout<<"Elements :"<<endl;
    print(head1);
    print(head2);

    // reversing both numbers
    head1 = revLL(head1);
    head2 = revLL(head2);

    // print(head1);
    // print(head2);

    // // node that represent the sum (in reverse)
    Node* sum = add_LL( head1, head2, 0);
    // Node *sum = sum_no(head1, head2);

    // // reversing the digits to get real ans
    sum = revLL(sum);

    print(sum);

}