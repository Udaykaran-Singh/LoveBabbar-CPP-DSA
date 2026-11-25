#include<iostream>
#include<stack>
using namespace std;

void num_get_num(stack<int> num, stack<int> &retur, int temp){

    if(num.empty()){
        retur.push(-1);
        return;
    }

    int peek = num.top();
    num.pop();

    if(peek < temp){
        retur.push(peek);
        return;
    }
    num_get_num(num, retur, temp);

}

void empty_store(stack<int> &num, stack<int> &retur){

    if(num.empty()){
        return;
    }

    int temp = num.top();
    cout<<temp<<" "<<endl;
    num.pop();

    empty_store(num, retur);
    num_get_num(num, retur, temp);

    num.push(temp);


}

int main(){

    stack<int> num;
    stack<int> retur;
    num.push(3);
    num.push(4);
    num.push(1);
    num.push(2);
    num.push(5);
    num.push(2);
    num.push(9);

    cout<<"in stack elements :"<<endl;

    empty_store(num, retur);

    cout<<endl<<endl<<"ans acc. to ques :"<<endl;

    while(!retur.empty()){
        cout<<retur.top()<<" ";
        retur.pop();
    }cout<<endl<<endl<<endl;







    // check stack , made to find min. element just next to current index element
    stack<int> s;
    // if any small no. does not exist
    s.push (-1) ; 

    vector<int> arr;
    arr.push_back(9);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    int n = arr.size();

    // making vector to store ans
    vector<int> ans(n) ;

    cout<<"ans acc to sir :"<<endl;

    // form last element to 1st triversing
    for(int i=n-1; i>=0 ; i--) {

        int curr = arr [i];

        while(s.top() >= curr){
            // removing elements ; which are of no use for next numbers
            // because they are larger than currnet element so they will have no use in future.
            s.pop( );
        }

        //ans is stack ka top
        ans[i] = s.top();

        // storing current element in stack
        s. push (curr);
    }

    for(int i:ans){
        cout<<i<<" ";
    }cout<<endl;

}