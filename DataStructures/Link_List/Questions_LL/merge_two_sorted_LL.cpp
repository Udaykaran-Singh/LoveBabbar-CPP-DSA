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



// Recursive function to merge two sorted linked lists
Node* mergeSortedLists(Node* node1, Node* node2) {
    // Base cases
    if (node1 == NULL) return node2;
    if (node2 == NULL) return node1;

    // Recursive merge
    if (node1->data < node2->data) {
        node1->next = mergeSortedLists(node1->next, node2);
        return node1;
    } else {
        node2->next = mergeSortedLists(node1, node2->next);
        return node2;
    }
}


Node* merge(Node* &head1, Node* &head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    Node* ll1 = head1;
    Node* temp_head = NULL;
    Node* temp_tail = NULL;
    Node* ll2 = head2;

    if(ll1->data < ll2->data){
        temp_head = temp_tail = ll1;
        ll1 = ll1->next;
    }
    else{
        temp_head = temp_tail = ll2;
        ll2 = ll2->next;

    }

    while(ll1 != NULL && ll2 != NULL){
        if(ll1->data < ll2->data){
            temp_tail->next = ll1;
            temp_tail = temp_tail->next;
            ll1 = ll1->next;
        }
        else{
            temp_tail->next = ll2;
            temp_tail = temp_tail->next;
            ll2 = ll2->next;
        }
    }

    if(ll1 != NULL){
        temp_tail->next = ll1; 
    }
    if(ll2 != NULL){
        temp_tail->next = ll2;
    }

    return temp_head;
}

int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(3);

    Node* head1 = node1;
    Node* tail1 = node1;    

    Node* head2 = node2;
    Node* tail2 = node2;  

    insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 9);
    insertAtTail(tail1, head1, 13);
    insertAtTail(tail1, head1, 13);
    insertAtTail(tail1, head1, 13);

    insertAtTail(tail2, head2, 3);
    insertAtTail(tail2, head2, 7);
    insertAtTail(tail2, head2, 9);
    insertAtTail(tail2, head2, 10);
    insertAtTail(tail2, head2, 111);
    insertAtTail(tail2, head2, 113);

    cout<<"Elements :"<<endl;
    print(head1);
    print(head2);

    Node* merHead = merge(head1, head2);
    cout<<"After merging LL_2 and LL_1 :"<<endl;
    print(merHead);
}