#include<iostream>
using namespace std;

class Node {
    public:
        // properties
        int data;
        Node* next;

        // behaviour
        Node(int d){
            this->data = d;
            this->next = NULL;
        }

        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

void setAtHead(Node* &head, int n){
    if(head == NULL){
        head = new Node(n);
    }
    else{
        Node* temp = new Node(n);
        temp->next = head;
        head = temp;
    }
}

class Stack {
    public:
        // properties
        Node* head ;

        
        // behaviour
        Stack(){
            this->head = NULL;
        }

        // push
        void push(int a){
            setAtHead(head, a);
        }

        // pop
        void pop(){
            if(head == NULL){
                cout<<"underflow"<<endl;
            }else{
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp; 
            }
        }

        int top(){
            if(head == NULL){
                return -1;
            }else{
                return head->data;
            }
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }else{
                return false;
            }
        }
};

int main(){

    Stack ham;
    cout<<"is empty : "<<ham.isEmpty()<<endl;
    ham.push(2);
    cout<<"peek : "<<ham.top()<<endl;
    ham.push(3);
    // cout<<ham.head->next->data<<endl;
    cout<<"peek : "<<ham.top()<<endl;
    ham.pop();
    cout<<"peek : "<<ham.top()<<endl;
    cout<<"is empty : "<<ham.isEmpty()<<endl;
    // cout<<ham.head->data<<endl;

}