#include<iostream>
using namespace std;
int main()
{
    // // 1st pattern
    // // for (int i = 0; i < 4; i++)
    // // {
    // //     for (int j = 0; j < 5; j++)
    // //     {
    // //         cout<<"*  ";
    // //     }
    // //     cout<<endl;
    // // }
    // int i=0;
    // while (i<4)
    // {
    //     int j=0;
    //     while (j<5)
    //     {
    //         cout<<"*  ";
    //         j+=1;
    //     }
    //     i+=1;
    //     cout<<endl;
    // }
    

    // // 2nd pattern
    // // for (int i = 1; i <= 5; i++)
    // // {
    // //     for (int j = 0; j < i; j++)
    // //     {
    // //         cout<<"* ";
    // //     }
    // //     cout<<"\n";
    // // }
    // // cout<<"\n\n";
    // int i=0;
    // while (i<=4)
    // {
    //     int j=4;
    //     while (j>=i)
    //     {
    //         cout<<"* ";
    //         j-=1;
    //     }
    //     i+=1;
    //     cout<<endl;  
    // }

    
    // 3rd pattern
    // for (int i = 0; i <=4; i++)
    // {
    //     for (int j = 0; j <= 4; j++)
    //     {
    //         cout<<(j+1)<<" ";
    //     }
    //     cout<<endl;
    // }
    

    // // 4th pattern
    // int i=1, k=1;
    // while (i<4)
    // {
    //     int j=1;
    //     while (j<4)
    //     {
    //         cout<<k <<" ";
    //         k++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;  
    // }
    

    // // 5th pattern
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j <=i; j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl; 
    // }


    // // 6th pattern
    // int i=1, k=1;
    // while (i<5)
    // {
    //     int j=1;
    //     while (j<=i)
    //     {
    //         cout<<k <<" ";
    //         k++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }


    // // 7th pattern
    // // for (int i = 1; i <= 4; i++)
    // // {
    // //     for (int j = i; j!=0 ; j--)
    // //     {
    // //         cout<<j<<" ";
    // //     }
    // //     cout<<endl;
    // // }
    // int i=0;
    // while (i<4)
    // {
    //     int k = 1+i;
    //     int j=0;
    //     while (j<=i)
    //     {
    //         cout<<k<<" ";
    //         k--;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }


    // // 8th pattern
    // for (int i = int('A'); i <= int('C'); i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout<<char(i)<<" ";
    //     }
    //     cout<<endl;
    // }


    // // 9th pattern
    // int i =1;
    // while (i<=3)
    // {
    //     int k = 65+i-1;
    //     int j=1;
    //     while (j<=3)
    //     {
    //         cout<<char(k) <<" ",
    //         k++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }


    // // 10th pattern
    // int i=0;
    // while (i<4)
    // {
    //     int k=65+i;
    //     int j=0;
    //     while (j<=i)
    //     {
    //         cout<<char(k)<<" ";
    //         k++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }
    

    // // 11th pattern
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 68 - i ; j <= 68; j++)
    //     {
    //         cout<<char(j);
    //     }
    //     cout<<endl;
    // }
    

    // // 12th pattern
    // int i = 1;
    // while (i!=5)
    // {
    //     int j = 5-i;
    //     while (j!=0)
    //     {
    //         cout<<" ";
    //         j--;
    //     }
    //     j = 1;
    //     while (j<= i)
    //     {
    //         cout<<i;
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }


    // // 13th pattern
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<" ";
    //     }
    //     for (int j = i; j <= 4; j++)
    //     {
    //         cout<<j;
    //     }
    //     cout<<endl;  
    // }
    

    // // 14th pattern
    // int k = 1;
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4-i; j++)
    //     {
    //         cout<<" ";
    //     }
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<k;
    //         k++;
    //     }
    //     cout<<endl;
    // }
    

    // // 15th pattern
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = i; j <= 4; j++)
    //     {
    //         cout<<" ";
    //     }
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<j;
    //     }
    //     for (int j = i-1; j >= 1; j--)
    //     {
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }
    

    // // 16th pattern
    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 1; j <= 6-i; j++)
    //     {
    //         cout<<j;
    //     }
    //     for (int j = 1; j <= i-1; j++)
    //     {
    //         cout<<"*";
    //     }
    //     for (int j = 1; j <= i-1; j++)
    //     {
    //         cout<<"*";
    //     }
    //     for (int j = 6-i; j >= 1; j--)
    //     {
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }
    

}