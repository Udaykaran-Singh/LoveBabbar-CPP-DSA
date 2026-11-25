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

pair<bool, int> sum_fast(Node* &root){

    // base case
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if(root->left_child == NULL && root->right_child == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = sum_fast(root->left_child);
    pair<bool, int> rightAns = sum_fast(root->right_child);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condn = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if(left && right && condn){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first= false; 
    }
    return ans;

}

bool sum_tree(Node* &root){

    // sum of left subtree and right subtree are equal to parent node for every node.
    return sum_fast(root).first;

}

int main(){
    // A tree is height balanced if difference between heights of left and right subtrees is not more than on for all nodes of tree.

    Node* root = NULL;
    build_from_level_order(root);
    
    bool s = sum_tree(root);

    levelOrderTraversal(root);
    cout<<endl;

    cout<<"is a Sum tree? : "<<s<<endl;

}