#include<iostream>
#include<stack>
using namespace std;

bool wellbar(string br, stack<char> &bracket){
    int index = 0;
    while(br[index] != '\0'){

        // pushing opening brackets
        if(br[index] == '[' || br[index] == '{' || br[index] == '('){
            bracket.push(br[index]);
        }

        // poping if opening bracket at top pairs with closing brackets encountered else returning false
        if(br[index] == ']' && !bracket.empty() && bracket.top() == '['){
            bracket.pop();
        }else if (br[index] == ']' && (bracket.empty() || bracket.top() != '[')){
            return false;
        }

        if(br[index] == '}' && !bracket.empty() && bracket.top() == '{'){
            bracket.pop();
        }else if(br[index] == '}' && (bracket.empty() || bracket.top() != '{')){
            return false;
        }

        if(br[index] == ')' && !bracket.empty() && bracket.top() == '('){
            bracket.pop();
        }else if(br[index] == ')' && (bracket.empty() || bracket.top() != '(')){
            return false;
        }

        // increasing index
        index++;
    }

    // if no false has return till end of string it means it is well balanced
    return true;
}

int main(){
    stack<char> bracket;
    string br = "][{()}{}()[]]";
    
    if(wellbar(br, bracket)){
        cout<<"Brackets in "<<br<<" are well set."<<endl;
    }
    else{
        cout<<"Brackets in "<<br<<" are not well set."<<endl;
    }
    

}