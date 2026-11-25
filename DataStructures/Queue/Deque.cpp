#include<iostream>
using namespace std;

class Deque {
    int* arr;
    int front;
    int rear;
    int size;

    public:
        Deque(){
            size = 100001;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push_front(int value){
            if(isFull()){
                cout<<"Queue is Full"<<endl;
            }else if(isEmpty()){              // 1st element to push 
                front = rear = 0;
            }else if(front == 0 && rear != size -1){
                front = size-1;
            }else{
                // normal flow
                front--;
            }
            // push inside the queue
            arr[front] = value;
        }

        void push_back(int value){
            if(isFull()){
                cout<<"Queue is Full"<<endl;
            }else if(isEmpty()){              // 1st element to push 
                front = rear = 0;
            }else if(rear == size - 1 && front != 0){
                rear = 0;       // to maintain cyclic nature
                arr[rear] = value;
            }else{
                // normal flow
                rear++;
            }
            // push inside the queue
            arr[rear] = value;
        }

        int pop_front(){
            if(isEmpty()){    // to check queue is empty 
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;
            if(front == rear){  //single element is present
                front = rear = -1;
            }else if(front == size -1){
                front = 0;      // to maintain cyclic nature
            }else{
                front++;
            }
            return ans;
        }

        int pop_rear(){
            if(isEmpty()){    // to check queue is empty 
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int ans = arr[rear];
            arr[rear] = -1;
            if(front == rear){  //single element is present
                front = rear = -1;
            }else if(rear == 0){
                rear = size - 1;      // to maintain cyclic nature
            }else{
                rear--;
            }
            return ans;
        }

        int getFront(){
            if(isEmpty()){
                return -1;
            }
            return arr[front];
        }

        int getRear(){
            if(isEmpty()){
                return -1;
            }
            return arr[rear];
        }

        bool isEmpty(){
            if(front == -1){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            if((front == 0 && rear == size -1) || (front != 0 && rear == (front - 1) % (size-1))){
                return true;
            }else{
                return false;
            }
        }

};

int main(){
    return 0;
}