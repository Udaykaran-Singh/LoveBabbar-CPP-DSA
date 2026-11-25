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

int main(){

    /* Link List :          (Dynamic Data  Structure)

       Advantage :
       i)  Insertion and deletion is easy.
       ii) No shifting needed.
       
       Types Of Link List :
       1. Singly LL.
       2. Doubly LL.
       3. Circular LL.
       4. Circular Doubly LL. */


    Node* node1 = new Node(10);
    cout<<node1 -> data<<endl;
    cout<<node1 -> next<<endl;

    delete node1;

}