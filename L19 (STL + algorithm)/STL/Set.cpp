#include<iostream>
#include<set>

using namespace std;
int main(){     // sorted  {accending order}

    set<int> uday;

    // .insert(element)
    uday.insert(5);
    uday.insert(4);
    uday.insert(5);
    uday.insert(1);
    uday.insert(5);
    uday.insert(5);
    uday.insert(0);

    for(int i:uday){ 
        cout<<i<<" ";
    }cout<<endl<<endl;

    // .erase()
    set<int>::iterator it = uday.begin();
    it++;
    uday.erase(it);
    for(int i:uday){ 
        cout<<i<<" ";
    }cout<<endl<<endl;

    // .count(element)
    cout<<"count no. of 5 present : "<<uday.count(5)<<endl<<endl;


    // .find                  // if element exist it return iterator of that element   (refrence of that element)
    set<int>::iterator finditer = uday.find(4);
    cout<<"value present at finditer : "<<*finditer<<endl<<endl;

    for(auto it=finditer; it!=uday.end(); it++){
        cout<<*it<<" ";
    }cout<<endl<<endl;


}