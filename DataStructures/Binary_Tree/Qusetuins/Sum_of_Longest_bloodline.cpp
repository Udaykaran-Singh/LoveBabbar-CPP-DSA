#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

class Node {

    public:
        // properties
        // Node* parent;
        int data;
        Node* left_child;
        Node* right_child;


        Node(int d){
            // this->parent = NULL;
            this->data = d;
            this->left_child = NULL;
            this->right_child = NULL;
        }

};

void build_from_level_order(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root :"<<endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left_child = new Node(leftData);
            q.push(temp->left_child);
        }

        cout<<"Enter right node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right_child = new Node(rightData);
            q.push(temp->right_child);
        }

    }

}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);

    // seperator (root node)
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // seperator
        if(temp == NULL){
            // purana level completely traverse ho chuka ha
            cout<<endl;
            if(!q.empty()){
                // q still have some chile nodes we enter NULL to make next level 
                q.push(NULL);
            }
        }
        else{

            cout<<temp->data<<" ";
            
            if(temp->left_child){
                q.push(temp->left_child);
            }

            if(temp->right_child){
                q.push(temp->right_child);
            }

        }

    }

}

void sum_of_longest_path(Node* &root, pair<int, int> sum, pair<int, int> &maxi){  // NLR

    // base case
    if(root == NULL ){
        if(sum.second > maxi.second){
            maxi.second = sum.second;
            maxi.first = sum.first;
        }
        else if(sum.second == maxi.second){
            maxi.first = max(sum.first, maxi.first);
        }
        return;
    }

    // sum, length
    sum.first = sum.first + root->data;
    sum.second = sum.second + 1;


    sum_of_longest_path(root->left_child, sum, maxi);
    sum_of_longest_path(root->right_child, sum, maxi);
    
}

int main(){
    // A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

    Node* root = NULL;
    build_from_level_order(root);

    levelOrderTraversal(root);
    cout<<endl;

    // sum, level
    pair<int, int> sum = make_pair(0, 0);
    pair<int, int> maxi = make_pair(0, 0);

    sum_of_longest_path(root, sum, maxi);
    cout<<"sum : "<<maxi.first<<endl;

    // 1 2 3 4 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 -1

}