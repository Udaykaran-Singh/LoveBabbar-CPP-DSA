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


pair<bool, int> balance_fast(Node* &root){
    // base case
    if(root == NULL){
        pair<bool, int> p;
        p.first = true;
        p.second = 0;
        return p;
    }

    pair<bool, int> left = balance_fast(root->left_child);
    pair<bool, int> right = balance_fast(root->right_child); 

    bool leftans = left.first;
    bool rightans = right.first;

    // makes time comlexity O(n^2)
    bool diff = left.second - right.second <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftans && rightans && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }

    return ans;

}

bool is_balance(Node* root){

    return balance_fast(root).first;

    /* // base case
    if(root == NULL){
        return true;
    }

    bool left = is_balance(root->left_child);
    bool right = is_balance(root->right_child);

    // makes timr comlexity O(n^2)
    bool diff = height_of_binary_tree(root->left_child) - height_of_binary_tree(root->right_child) <= 1;

    if(left && right && diff){
        return true;
    }else{
        return false;
    }*/

}

int main(){
    // A tree is height balanced if difference between heights of left and right subtrees is not more than on for all nodes of tree.

    Node* root = NULL;
    build_from_level_order(root);

    bool bal = is_balance(root);

    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Balanced : "<<bal<<endl;


    return 0;
}