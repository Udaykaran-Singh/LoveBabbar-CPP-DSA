#include<iostream>
using namespace std;

class A{                                      // function overloading.                                                   
    public:
        void sayhello(string name){
            cout<<"Hello "<<name<<endl;
        }

        void sayhello(){
            cout<<"Hello "<<endl;
        }

        void sayhello(string name, int n){
            cout<<"Bye "<<endl;
        }

};

class B{                                      // operator overloading.
    public:
        int a, b;

        int add(){
            return a + b;
        }

        void operator+ (B &obj){              // operator overloading.
            int value1 = this -> a;
            int value2 = obj.a;
            cout<<"output : "<<value1-value2<<endl;
        }
};

int main(){
    // Polymorphism 
    // one thing many forms.

    /* 1. Compile Time Polymorphism :      (Static Polymorphism)

            i)  Funtion Overloading :
                Function name is same but parameters in function definition are different either in numbers or type.
            
             
            ii) Operator Overloading :
                Syntax -> return_Type operator<operator> (<input_argument>)
                          Here : a + b ; -> a is current object, -> b is input_argument

                Operators that cannot be overloaded are  ::  .*  .  ?:                                                   */

    /* 2. Run Time Polymorphism :      (Dynamic Polymorphism)
        
          i) Method Overriding :
          -> function in (Method of) parent class and inherited class must have same name.
          -> have same parameter.
          -> Method Overriding can only be done using inheritance only. 
          
          class a -> speak() {"speaking"};
          class b inherited a -> speak() {"bark"};

          int main(){
                b.obj; obj.speak()         -----> it will ans bark        (local is preffered)
                                                  not speaking, this is method overriding.
          } */
    
    A obj1;
    obj1.sayhello();

    B obj22, obj21, obj3, obj4;
    obj21.a = 4;
    obj22.a = 7;

    obj22 + obj21;     // val_1 = 7 -  val_2 = 4

    obj3.a = 9;
    obj4.b = 1;
    cout<<obj3.a+obj4.b<<endl;

}