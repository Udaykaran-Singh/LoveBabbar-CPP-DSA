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

Node* getmid(Node* &head){
    Node* fast = head->next;
    Node* slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* merge(Node* &left, Node* &right){

    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* temp_tail = NULL;
    Node* temp_head = NULL;


    while(right != NULL && left != NULL){

        if(left->data < right->data){

            Node* newnode = new Node(left->data);

            if(temp_head == NULL){
                temp_head = temp_tail = newnode;
            }else{
                temp_tail->next = newnode;
                temp_tail = newnode;
            }

            left = left->next;
            
        }
        else{

            Node* newnode = new Node(right->data);

            if(temp_head == NULL){
                temp_head = temp_tail = newnode;
            }else{
                temp_tail->next = newnode;
                temp_tail = temp_tail->next;
            }

            right = right->next;
        }
        
    }

    if(right != NULL){
        temp_tail->next = right;
    }
    if(left != NULL){
        temp_tail->next = left;
    }
    // print(temp_head);


    return temp_head;

}

Node* mergesort(Node* &head, Node* &tail){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp = head;
    Node* mid = NULL;

    mid = getmid(head);

    Node* left_head = head;
    Node* left_tail = mid;
    Node* right_head = mid->next;
    Node* right_tail = tail;
    left_tail->next = NULL;

    Node* left = mergesort(left_head, left_tail);

    Node* right = mergesort(right_head, right_tail);

    Node* ret_head = merge(left, right);

    return ret_head;

}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;

    Node* tail = node1;    


    insertAtTail(tail, head, 2);
    insertAtTail(tail, head, 15);
    insertAtTail(tail, head, 19);
    insertAtTail(tail, head, 14);
    insertAtTail(tail, head, 19);
    insertAtTail(tail, head, -4);
    print(head);

    head = mergesort(head, tail);
    print(head);
    // cout<<tail->data<<endl;

    delete head;


}