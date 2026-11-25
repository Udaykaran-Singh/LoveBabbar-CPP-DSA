#include<iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;
int main(){
    string uday = "hello how are you";
    stack<char> words;
    queue<char> st;

    int i = 0;

    // // how to take input from users
    // char ch;
    // do{
    //     ch = cin.get();
    //     uday[i]=ch;
    //     i++;
    // }
    // while (ch!='\n');
    // uday[i-1] = '\0';

   int n = uday.length();

    // from :- "hello how are you"
    // To :- "olleh woh era uoy"
    
    while (i < n) {
        while(uday[i]!=' ' && i < n){
            char a =uday[i];
            words.push(a);
            i++;
        }
        while(!words.empty()){
            char a = words.top();
            st.push(a);

            words.pop();
        }
        st.push(' ');

        i++;
        
    }

    while (!st.empty())
    {
        cout<<st.front();
        st.pop();
    }
 
}