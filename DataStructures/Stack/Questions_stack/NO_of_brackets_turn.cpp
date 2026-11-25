#include<iostream>
#include<stack>

using namespace std;

int turn_min_br(string br, stack<char> &brackets){

    // odd
    if(br.length() % 2 != 0){
        return -1;
    }

    // even
    for(int i = 0; i < br.length(); i++){
        if(br[i] == '{'){
            brackets.push(br[i]);
        }else if(br[i] == '}' && !brackets.empty() && brackets.top() == '{'){
            brackets.pop();
        }else if(br[i] == '}'){
            brackets.push(br[i]);
        }
    }


    // after clearing already well formed brackets count left and right brackets
    int left = 0, right = 0;
    while(!brackets.empty()){

        if(brackets.top() == '{'){
            left++;
        }
        else if(brackets.top() == '}'){
            right++;
        }
        
        brackets.pop();

    }

    // returning no. of turns made
    return (left+1)/2 + (right + 1)/2;


}

int main(){
    stack<char> brackets;
    string br = "}}}{{{";

    int a = turn_min_br(br, brackets);

    if(a != -1){
        cout<<"Min. numbers of brackets turn :"<<a<<endl;
    }else{
        cout<<"cannot make well formed brackets by turning brackets."<<endl;
    }

}