#include<iostream>
#include<stack>
using namespace std;

class Nstack {
    public:
        int *arr;       // Array to store the elements
        int *top;       // Array to store the top indexes of each stack
        int *next;      // Array to store the next index information


        int n,s;        // n is number of stacks, s is size of array
        int freespot;   // To store the beginning index of the free spots

        // constructor
        Nstack(int N, int S){
            n = N;
            s = S; 
            arr = new int[s];
            top = new int[n];
            next = new int[s];

            // top initialise
            for(int i = 0; i < n; i ++){
                top[i] = -1;
            }

            // next initialise
            for (int i = 0; i < s; i++){
                next[i] = i+1;
            }

            // update last index to -1
            next[s-1] = -1;

            // freespot initialise
            freespot = 0;

        }

        // pushes 'X' into Mth stack. Return true if it get pushed into the stack, and false otherwise
        bool push(int x, int m){
            // check for overflow
            if(freespot == -1){
                return false;
            }

            // find index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // insert element into array
            arr[index] = x;

            // Update next
            next[index] = top[m-1];

            // update top
            top[m-1] = index;

            return true;
        }

        // pops top element from Mth stack. Return -1 if the stack is empty, otherwise return the popped element.
        int pop(int m){
            // check underflow condition
            if(top[m-1] == -1){
                return -1;
            }

            int index = top[m-1];

            top[m-1] = next[index];

            next[index] = freespot;

            freespot = index;

            return arr[index];
        }


        ~Nstack(){
            delete[] arr;
            delete[] top;
            delete[] next;
        }

};

int main(){
        /* let us fit k stack in one array :
       

       for this we need 3 additional thing :

       i)   top[k] : top array having total k spaces, initialized by -1.
                     where index of top element of each stack stored.

       ii)  next[n] : n is total spaces of array, initially have index of next free spaces , last space have -1 in it. 
                      * points to next element after stack top.
                      * points to next free space.
                      * 
       iii) int free_space. */
}