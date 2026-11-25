#include<iostream>
using namespace std;

int main()
{
    cout << "\nHello World" <<endl<<endl;


    int a=5;
    char b = 'a'; 
    bool c= true; 
    cout << a <<  "\n";
    cout << b<<endl;
    cout << (c)<<endl<<endl;


    // unsigned, signed:
    cout <<"Unsigned, Signed :" <<endl;
    unsigned int uns = -133;
    signed int sig = -133;
    cout << uns <<endl<<sig <<endl<<endl;


    // sizeof()
    cout << "sizeof() :" <<endl;
    cout << sizeof(a) <<endl;
    cout << sizeof(b) <<endl;
    cout << sizeof(c) <<endl<<endl;

    // Ascii
    cout << "Ascii :" <<endl;
    char typecasting = 99;
    cout << typecasting <<"\n";

    int typecasting2= 'a';
    cout << typecasting2<<"\n\n";


    // array
    cout << "array :" <<endl;
    char name[] = "Udaykaran Singh";
    cout << name<<"\n";

    int arr[] = {2,3,4,5};
    cout << *arr<<endl;
    for (int i = 0; i < 4  ; i++)
    {
        cout << arr[i] << ' ';
    }
    
}