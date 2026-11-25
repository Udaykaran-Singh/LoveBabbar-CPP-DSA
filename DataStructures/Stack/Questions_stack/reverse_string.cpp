#include<iostream>
using namespace std;

class Stack {

    public:
        // properties
        int index;
        int s;
        char *arr;

        // behaviour
        Stack(int size){
            this->s = size;
            arr = new char[s];
            this->index = -1;
        }

        void push(string words){
            while(words[index+1]!='\0'){
                index+=1;
                if(index < s){
                    arr[index] = words[index];
                }
                else{
                    cout<<"Stack Overflow cannnot include character "<<words[index]<<" in Stack"<<endl;
                }
            }
        }

        void pop(){
            if(index >= 0){
                index--;
            }
            else{
                cout<<"Stack Underflow."<<endl;
            }
        }

        char top(){
            if(index >= 0){
                return arr[index];
            }
            else{
                cout<<"Stack is Empty"<<endl;
                return '*';
            }
        }

        bool isEmpty(){
            if(index < 0){
                return true;
            }
            else{
                return false;
            }
        }

        int size(){
            return (index+1);
        }


};

int main(){
    Stack word(50);
    string hel = "hello how are you?";
    // cin>>hel;
    word.push(hel);
    cout<<word.size()<<endl;
    while(!word.isEmpty()){
        cout<<word.top();
        word.pop();
    }cout<<endl;
    cout<<word.size()<<endl;
}