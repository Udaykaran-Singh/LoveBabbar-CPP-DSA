#include<iostream>
#include<deque>
using namespace std;

int main(){
    int row , column, count=0;
    cout<<"Enter no. of rows and no. of columns you want respectively : ";
    cin>>row>>column;
    int arr[row][column];
    for (int q = 0; q < row; q++){
        for (int i = 0; i < column; i++){
            arr[q][i] = ++count;
        }
    }
    for (int q = 0; q < row; q++){
        for (int i = 0; i < column; i++){
            cout<<arr[q][i]<<" "; 
        }cout<<endl;
    }cout<<endl;


    // // up down in array
    // int i = 0 , j = 0 , flag = 0;
    // while(flag < row*column){
    //     if(j%2 == 0){
    //         while(i<row){
    //             cout<<arr[i][j]<<" ";
    //             i++;
    //             flag++;
    //         }
    //         i = row-1;
    //         j++;
    //     }else{
    //         while(i>=0){
    //             cout<<arr[i][j]<<" ";
    //             i--;
    //             flag++;
    //         }
    //         i = 0;
    //         j++;
    //     }
    // }


    // // spiral in array
    // int i = 0, j = 0, strrow = 0, strcol = 0, endr = row - 1, endc = column - 1;
    // int flag = 0;
    // while(flag < row*column){
    //     while(j <= endc && flag < row*column){
    //         cout<<arr[i][j]<<" ";
    //         j++;
    //         flag++;
    //     }
    //     j--;
    //     i++;
    //     strrow++;
    //     while(i <= endr && flag < row*column){
    //         cout<<arr[i][j]<<" ";
    //         i++;
    //         flag++;
    //     }
    //     i--;
    //     j--;
    //     endc--;
    //     while(j>=strcol && flag < row*column){
    //         cout<<arr[i][j]<<" ";
    //         j--;
    //         flag++;
    //     }
    //     j++;
    //     i--;
    //     endr--;
    //     while(i>=strrow && flag < row*column){
    //         cout<<arr[i][j]<<" ";
    //         i--;
    //         flag++;
    //     }
    //     j++; 
    //     i++;
    //     strcol++;
    // }


    // // rotate by 90 degree
    // int i = 0, j = 0, strrow = 0, strcol = 0, endr = row - 1, endc = column - 1;
    // int flag = 0;
    // deque<int> uday;
    // while(flag < row*column){
    //     while(j <= endc && flag < row*column){
    //         uday.push_back(arr[i][j]);
    //         // cout<<uday.back()<<" ";
    //         j++;
    //         flag++;
    //     }
    //     j--;
    //     i++;
    //     strrow++;
    //     while(i <= endr && flag < row*column){
    //         uday.push_back(arr[i][j]);
    //         // cout<<uday.back()<<" ";
    //         i++;
    //         flag++;
    //     }
    //     i--;
    //     j--;
    //     endc--;
    //     while(j>=strcol && flag < row*column){
    //         uday.push_back(arr[i][j]);
    //         // cout<<uday.back()<<" ";
    //         j--;
    //         flag++;
    //     }
    //     j++;
    //     i--;
    //     endr--;
    //     while(i>=strrow && flag < row*column){
    //         uday.push_back(arr[i][j]);
    //         // cout<<uday.back()<<" ";
    //         i--;
    //         flag++;
    //     }
    //     j++; 
    //     i++;
    //     strcol++;
    // }
    // int arr2[column][row];
    // i = 0, j = row - 1, strrow = 0, strcol = 0, endr = column - 1, endc = row - 1;
    // flag = 0;
    // while(flag < row*column){
    //     while(i <= endr && flag < row*column){
    //         arr2[i][j] = uday.front();
    //         // cout<<i<<" "<<j<<" "<<uday.front()<<endl;
    //         uday.pop_front();
    //         i++;
    //         flag++;
    //     }
    //     i--;
    //     j--;
    //     endc--;
    //     while(j>=strcol && flag < row*column){
    //         arr2[i][j] = uday.front();
    //         // cout<<i<<" "<<j<<" "<<uday.front()<<endl;
    //         uday.pop_front();
    //         j--;
    //         flag++;
    //     }
    //     j++;
    //     i--;
    //     endr--;
    //     while(i>=strrow && flag < row*column){
    //         arr2[i][j] = uday.front();
    //         // cout<<i<<" "<<j<<" "<<uday.front()<<endl;
    //         uday.pop_front();
    //         i--;
    //         flag++;
    //     }
    //     j++;
    //     i++;
    //     strcol++;
    //     while(j <= endc && flag < row*column){
    //         arr2[i][j] = uday.front();
    //         // cout<<i<<" "<<j<<" "<<uday.front()<<endl;
    //         uday.pop_front();
    //         j++;
    //         flag++;
    //     }
    //     j--;
    //     i++;
    //     strrow++;
    // }


    // // printing
    // for (int q = 0; q < column; q++){
    //     for (int i = 0; i < row; i++){
    //         cout<<arr2[q][i]<<" "; 
    //     }cout<<endl;
    // }

    


    return 0;
}