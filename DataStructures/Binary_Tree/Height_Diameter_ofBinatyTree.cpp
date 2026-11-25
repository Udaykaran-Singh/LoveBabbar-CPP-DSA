#include<iostream>
#include<queue>
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


int height_of_binary_tree(Node* &root){

    // base case
    if(root == NULL){
        return 0;
    }

    int left = height_of_binary_tree(root->left_child);
    int right = height_of_binary_tree(root->right_child);

    int ans = max(left, right) + 1;

    return ans;

}


pair<int, int> diameter_fast(Node* root){

    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> present_left = diameter_fast(root->left_child);
    pair<int, int> present_right = diameter_fast(root->right_child);

    // .first -> diameter
    // .second -> height

    int opt1 = present_left.first;
    int opt2 = present_right.first;
    int opt3  = present_left.second + 1 + present_right.second;

    pair<int, int> ans ;
    ans.first = max(max(opt1, opt2), opt3);
    ans.second = max(present_left.second, present_right.second) +1;

    return ans;

}

int Diameter_of_binary_tree(Node* &root){

    return diameter_fast(root).first;

    /* // O(n^2) time complexity , space 0(n)

    if(root == NULL){
        return 0;
    }

    int present_left = Diameter_of_binary_tree(root->left_child);
    int present_right = Diameter_of_binary_tree(root->right_child);

    // // it makes O(n^2) time complexity 
    int left_right = height_of_binary_tree(root->left_child) + 1 +height_of_binary_tree(root->right_child);

    return max(max(present_left, left_right), present_right); */
} 

int main(){
    Node* root = NULL;
    build_from_level_order(root);

    int h = height_of_binary_tree(root);
    cout<<"height : "<<h<<endl;

    int d = Diameter_of_binary_tree(root);
    cout<<"diameter : "<<d<<endl;
}