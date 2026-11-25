#include<iostream>
using namespace std;

bool check(char game[3][3], int n = 3){
    for (int  i = 0; i < n; i++){
        if(((game[i][0] == 'x') && (game[i][1] == 'x') && (game[i][2]== 'x'))||((game[i][0] == 'o') && (game[i][1] == 'o') && (game[i][2]== 'o'))){
            return true;
        }else if(((game[0][i] == 'x') && (game[1][i] == 'x') && (game[2][i]== 'x'))||((game[0][i] == 'o') && (game[1][i] == 'o') && (game[2][i]== 'o'))){
            return true;
        }else if((((game[0][0] == 'x') && (game[1][1] == 'x') && (game[2][2]== 'x')) || ((game[2][0] == 'x') && (game[1][1] == 'x') && (game[0][2]== 'x')))||(((game[0][0] == 'o') && (game[1][1] == 'o') && (game[2][2]== 'o')) || ((game[2][0] == 'o') && (game[1][1] == 'o') && (game[0][2]== 'o')))){
            return true;
        }
    }
    return false;
    
}

bool checkdraw(char game[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(game[i][j] == '0'){
                return false;
            }
        }   
    }
    return true;
    
    
}

void printboard(char game[3][3]){
    cout<<" "<<game[0][0]<<" | "<<game[0][1]<<" | "<<game[0][2]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<game[1][0]<<" | "<<game[1][1]<<" | "<<game[1][2]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<game[2][0]<<" | "<<game[2][1]<<" | "<<game[2][2]<<" "<<endl;
       
}

int main(){
    char game[3][3] = {[0 ... 2][0 ... 2] = '0'};
    bool won = false;
    char sign = 'x';
    printboard(game);
    while(1){
        cout<<endl<<"Its turn of Player playing "<<sign<<endl;
        cout<<"Enter number b/w 1-9 where you want to put "<< sign<<" :"<<endl;
        int num;
        cin>>num;
        if(num>9 || num<=0){
            cout<<"😅 Enter a valid NUMBER (b/w 1-9)."<<endl;
            continue;
        }
        num = num-1;
        int row = num/3;
        int column = num%3;
        if(game[row][column] != '0'){
            cout<<"🤬 Enter number where space is empty."<<endl;
            continue;
        }
        game[row][column] = sign;
        printboard(game);
        if(check(game)){
            cout<<"Player playing "<<sign<<" won."<<endl;
            break;
        }else if(checkdraw(game)){
            cout<<"🫠 It's a Draw."<<endl;
            break;
        }

        if (sign == 'x'){
            sign = 'o';
        }else{
            sign = 'x';
        }


    }

    return 0;
    
}