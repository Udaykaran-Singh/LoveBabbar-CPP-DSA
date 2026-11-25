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



bool detectLoop(Node* &head){

    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;
    while(temp!= NULL){
        if(visited[temp->next] == true){
            cout<<"Loop present between element "<<temp->data<<" and "<<temp->next->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node* floydCycleDetection(Node* &head){

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast!= NULL){

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;
        if (slow == fast){
            return slow; 
        }
    }
    
    return NULL;
}

Node* firsrElement_floydCycle(Node* &head){
    if (head == NULL){
        return NULL;
    }

    Node* intersection = floydCycleDetection(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;

}

void plane_floydCycle(Node* &Loop_starts_at, Node* &head){

    if(head == NULL){
        return;
    }

    Node* temp = Loop_starts_at;

    while(temp->next != Loop_starts_at){
        temp = temp->next;
    }
    temp->next = NULL;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;

    Node* tail = node1;    


    insertAtTail(tail, head, 12);
    insertAtTail(tail, head, 15);
    insertAtTail(tail, head, 16);
    insertAtTail(tail, head, 17);
    insertAtTail(tail, head, 12);
    insertAtTail(tail, head, 19);
    cout<<"Elements :"<<endl;
    print(head);

    tail->next = head->next->next;


    // is loop present ?
    if( floydCycleDetection(head) != NULL     /* detectLoop(head) */){
        cout<<"Loop Present : "<<endl;


        // loop starts at
        Node* loop_start_at = firsrElement_floydCycle(head);
        cout<<"starts at "<<loop_start_at->data<<endl<<endl;
        
        
        // removing loop
        plane_floydCycle(loop_start_at, head);
        cout<<"List after removing loop :"<<endl;
        print(head);
    }
    else{
        cout<<"Loop is not present."<<endl;
    }



    // print(head);
}