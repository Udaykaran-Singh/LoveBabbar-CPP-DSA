#include<iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front;
    int rear;
    int size;

    public:
        // constructor
        CircularQueue(){
            size = 100001;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        // functions
        void enqueue(int value){
            if((front == 0 && rear == size -1) || (front != 0 && rear == (front - 1)&(size - 1))){
                cout<<"Queue is Full"<<endl;
            }else if(front == -1){              // 1st element to push 
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

        int deque(){
            if(front == -1){    // to check queue is empty 
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

};

int main(){

    return 0;
}
