#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main(){
    string str = "abcaabccaz";
    queue<char> que;

    // initialising arr for a to z marking all of them 0.
    int arr[26] = {[0 ... 25] = 0};
    int i = 0;
    int temp = i;

    // triversing string
    while (str[i] != '\0'){

        // increase count of index corresponding to alphabet
        arr[str[i] - 'a']++;

        // alphabet at position temp appeared only 1 time
        if(arr[str[temp] - 'a'] <= 1){
            que.push(str[temp]);
        }else{
            // increase temp till either our alphabet at index temp has now appeared once or we reach where i is on string
            while(arr[str[temp] - 'a'] > 1 && temp < i){
                temp++;
            }


            if(arr[str[temp] - 'a'] > 1){
                // if still we cannot find alphabet who has appeared only once
                que.push('#');
            }
            else{
                // we find alphabet that appeared once
                que.push(str[temp]);
            }
        }

        i++;
    }
    

    while(!que.empty()){
        cout<<que.front();
        que.pop();
    }cout<<endl;





    // by sir
    unordered_map<char,int> count;
    string ans = "";
    i = 0;

    while (str[i] != '\0'){
        char ch = str[i];

        // increase count
        count[ch]++;

        // queue me push kr lo
        que.push(ch);

        while(!que.empty()){
            if(count[que.front()] > 1){
                // repeating char.
                que.pop();
            }
            else{
                ans.push_back(que.front());
                break;
            }
        }

        if(que.empty()){
            ans.push_back('#');
        }

        i++;
    }

    cout<<ans;
    

    

}