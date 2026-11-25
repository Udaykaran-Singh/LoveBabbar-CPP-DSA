#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main(){
    string uday = "hello how are you";
    stack<char> words;
    stack<char> ans;
    
    int i = 0;

    int n = uday.length();

    // From :- "hello how are you"
    // To :- "you are how hello"

    while (i < n) {
        while(uday[i]!=' ' && i < n){
            char a =uday[i];
            words.push(a);
            i++;
        }
        while(!words.empty()){
            char a = words.top();
            ans.push(a);
            words.pop();
        }
        ans.push(' ');
        i++;
        
    }
    while (!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
    }

}
        