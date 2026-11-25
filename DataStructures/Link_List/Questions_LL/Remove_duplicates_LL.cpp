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



void remove_duplicates_from_sortedLL(Node* &head){

    if(head == NULL){
        return;
    }

    Node* temp = head->next;
    Node* position = head;

    while(temp->next != NULL){

        if(temp->data ==  position->data){
            Node* del = temp;
            temp = del->next;
            del->next = NULL;
            delete del;
        }
        else{
            position->next = temp;
            position = position->next;
            temp = temp->next;
        }
        

    }
    delete temp;

    position->next = NULL;


}

void duplicate_del(Node* &head){
    if(head == NULL){
        return;
    }

    Node* current = head;
    Node* move;
    Node* temp;
    
    while(current != NULL){

        temp = current->next;
        move = current;

        while(temp != NULL){
            if(current->data == temp->data){
                Node* del = temp;
                temp = del->next;
                del->next = NULL;
                delete del;
                move->next = temp;
            }
            else{
                temp = temp->next;
                move = move->next;
            }
            
        }
        current = current->next;
    }
}

void duplicate_by_map(Node* &head){

    map<int, bool> visited;

    Node* temp = head;
    Node* prev = NULL;
    Node* del = NULL;

    while(temp != NULL){
        if(visited[temp->data] == true){
            del = temp;
            temp = temp->next;
            prev->next = temp;
            del->next = NULL;
            delete del;
        }else{
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;

    Node* tail = node1;    


    insertAtTail(tail, head, 1);
    insertAtTail(tail, head, 3);
    insertAtTail(tail, head, 1);
    insertAtTail(tail, head, 2);
    insertAtTail(tail, head, 3);
    insertAtTail(tail, head, 1);
    insertAtTail(tail, head, 3);

    cout<<"Elements :"<<endl;
    print(head);

    // remove_duplicates_from_sortedLL(head);

    // duplicate_del(head);

    duplicate_by_map(head);
    cout<<"After removing duplicates :"<<endl;
    print(head);

}