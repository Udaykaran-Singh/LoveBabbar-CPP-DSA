#include<iostream>
using namespace std;

class Stack {

    public:
        // properties
        int *arr;
        int top;
        int size;

        // behaviour         (functions)
        Stack(int size) {
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element){
            if(size - top > 1){
                top++;
                arr[top] = element;
            }
            else{
                cout<<"Stack overflow element "<<element<<" is not included in Stack."<<endl;
            }
        }

        void pop(){
            if(top >= 0){
                top--;
            }
            else{
                cout<<"Stack underflow"<<endl;
            }
        }

        int peek(){
            if(top >= 0){
                return arr[top];
            }
            else{
                cout<<"stack is Empty"<<endl;
                return -1;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }



};

int main(){
    Stack st(5);

    st.push(19);
    st.push(4);
    st.push(2);
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(1);

    cout<<"Top : "<<st.peek()<<endl;

    cout<<"isEmpty : "<<st.isEmpty()<<endl;

}