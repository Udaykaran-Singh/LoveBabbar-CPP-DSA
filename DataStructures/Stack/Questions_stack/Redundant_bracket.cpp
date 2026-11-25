#include<iostream>
#include<stack>
using namespace std;

bool Not_Rebundant_bar(string br, stack<char> &bracket){
    int index = 0;
    while(br[index] != '\0'){

        // pushing opening brackets
        if(br[index] == '+' || br[index] == '-' || br[index] == '*' || br[index] == '/' || br[index] == '('){
            bracket.push(br[index]);
        }

        if(br[index] == ')' && !bracket.empty() && ( bracket.top() == '+' || bracket.top() == '-' || bracket.top() == '*' || bracket.top() == '/' || bracket.top() == '(')){
            while(bracket.top() != '('){
                bracket.pop();
            }
            bracket.pop();
        }
        else if(br[index] == ')' && (bracket.empty() || bracket.top() != '(')){
            return false;
        }

        index++;

    }

    return true;
}

int main(){

    stack<char> bracket;
    string hm = ")(a+((23-1) *6* 29))";

    if(Not_Rebundant_bar(hm, bracket) && bracket.empty()){
        cout<<"Brackets in "<<hm<<" are not Rebundant. (good implemented)"<<endl;
    }
    else{
        cout<<"Brackets in "<<hm<<" are Rebundant. (bad implemented)"<<endl;
    }

}