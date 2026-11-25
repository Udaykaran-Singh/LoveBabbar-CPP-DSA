// // dangling pointer
// 
// #include<iostream>
// using namespace std;
// int * fun() {
//     int x = 10;
//     return &x;
// }
// int main() {
//     int * p = fun();
//     // p points to something which is not 
//     // valid anymore 
//     cout << * p;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main() {
//     int * ptr = 0;
//     // ..... //any code statements
//     {   int ch = 10;
//         ptr = & ch;
//     }
//     cout<<*ptr;
//     // ....
//     // Here ptr is dangling pointer
// }

// // Wild pointer

// 1.
// int *ptr; //wild pointer
// *ptr = 5;

// 2.
// int * p;            /* wild pointer */
// int a = 10;
// p = & a;            /* p is not a wild pointer now*/
// * p = 12;           /* This is fine. Value of a is changed */

// // Void pointer
// 
// #include <iostream>
// using namespace std;
// int main() {
//  /* 1. void pointers cannot be dereferenced. It can, however, be done using typecasting the void pointer.
//     2. Pointer arithmetic is not possible on pointers of void due to lack of concrete value and size.     */
// 
//     void * ptr;
//     int i = 10;
//     // assign int address to void
//     ptr = & i;
//     cout << "Address of variable i " << & i << endl;
//     cout << "Address where the void pointer is pointing " << ptr <<  endl;
//     return 0;
// }

// // null pointer

// // double pointer