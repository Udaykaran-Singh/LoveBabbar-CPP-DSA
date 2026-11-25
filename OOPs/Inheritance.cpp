#include<iostream>
using namespace std;

// creating parent class :
class Human {
    public:
        int height;
        int weight;
        int age;
    
    public:
        int getAge(){
            return this->age;
        }
        void setWeight(int w){
            this->weight = w;
        }
};


// creating child class :
class male: public Human{                   // class name:access_modifier parent_1 (,access_modifier parent_2 )
    public:
        string colour = "skin";
        void sleep(){
            cout<<"Male Sleeping"<<endl;
        }
};


int main(){
    // inheritance is from Parent class to Child class.
    // i.e. from Super class (Base class) to Sub class.


    /* HOW ACCESS MODIFIER WORK (Patent to Child) :
       1. public to anything (public, protected, private) :  same as anything.
       2. protected to any_of_These (public, protected) : protected.
          protected to private : private.
       3. private to any (public, protected, private) : not accessable */


    /* Type Of Inheritance :

       1. Single : class B inherited class A.
          eg. male inherited human.
        
       2. Multi-Level : class C inherited class B which inherited class A ....
          eg. male inherited human which inherited living organism ....
        
       3. Multiple : C inherited B and A , where A and B are not related. (2 parents 1 child)
          eg. girl inherited beauty and royality.
         
       4. Hierarchical : 1. C and B inherited A ; (1 parent 2 or more children)
                         2(a). E and F and G inherited B ;2(b). H and I inherited C.
       
       5. Hybrid : uses more than 1 type of inheritance. */


    male object1;
    cout<<"age :"<<object1.age<<endl;
    cout<<"weight :"<<object1.weight<<endl;
    cout<<"height :"<<object1.height<<endl;

    cout<<"colour :"<<object1.colour<<endl;
    object1.sleep();

    object1.setWeight(45);
    cout<<"weight :"<<object1.weight<<endl;
    object1.sleep();


    /* Inheritance Ambiguity :
       1. suppose class A have function func(),
       2. class B also have same function func(),
       3. class C inherited both class A and class B,
       4. we want to call function func() of class B in class C,
       5. then how can we do it ?
       
       Ans -> To solve this ambiguity we have scope resolution operator '::',
              1. To use func() of class A use -> 'object1.A::func()' 
              2. To use func() of class B use -> 'object1.B::func()'*/

}