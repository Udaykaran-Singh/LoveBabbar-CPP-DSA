#include<iostream>
#include<string>

using namespace std;
int main(){
    char uday1[100] = "hello how are";
    char uday2[9] = "are you?";
    char uday3[10] = "hello how";

    // strlen(char array)
    int a = strlen(uday1);
    cout<<"length of char uday1 : "<<a<<endl<<endl;

    // strcmp(string_1, string_2)                       // 0 means both strings are equal
    cout<<"comparing uday1 and uday2 : "<<strcmp(uday1,uday2)<<endl;
    cout<<"comparing uday1 and uday3 : "<<strcmp(uday1,uday3)<<endl<<endl;

    // strcpy(string_1, string_2)                       // string_2 get copied into string_1
    strcpy(uday1, uday2);
    cout<<"copied uday2 in uday1 : "<<uday1<<endl<<endl;


}