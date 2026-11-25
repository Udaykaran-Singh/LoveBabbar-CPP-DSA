#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

    public:
        Queue(){
            size = 100001;
            arr = new int[size];
            qfront = 0;
            rear = 0;
        }

        bool isEmpty(){
            if(qfront == rear){
                return true;
            }else{
                return false;
            }
        }

        void enqueue(int data){
            if(rear == size){
                cout<<"Queue is Full"<<endl;
            }else{
                arr[rear] = data;
                rear++;
            }
        }

        int deque(){
            if(qfront == rear){
                return -1;
            }else{
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;
                if(qfront == rear){
                    qfront = 0;
                    rear = 0;
                }
                return ans; 
            }
        }

        int front(){
            if(qfront == rear){
                return -1;
            }
            else{
                return arr[qfront];
            }
        }
};

int main(){
    Queue chan;
    cout<<"front : "<<chan.front()<<endl; 
    cout<<"empty : "<<chan.isEmpty()<<endl<<endl;


    chan.enqueue(2);
    cout<<"front : "<<chan.front()<<endl;
    cout<<"empty : "<<chan.isEmpty()<<endl<<endl;


    chan.deque();
    cout<<"front : "<<chan.front()<<endl;
    cout<<"empty : "<<chan.isEmpty()<<endl<<endl;


    chan.enqueue(2);
    chan.enqueue(100);
    chan.deque();
    cout<<"front : "<<chan.front()<<endl;
    cout<<"empty : "<<chan.isEmpty()<<endl<<endl;


}