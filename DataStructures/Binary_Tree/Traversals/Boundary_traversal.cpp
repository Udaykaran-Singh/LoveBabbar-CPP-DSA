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

void traverseLeft(Node* root, vector<int> &ans){

    // base case
    if(root == NULL || (root->left_child == NULL && root->right_child == NULL))
        return;

    ans.push_back(root->data);
    if(root->left_child)
        traverseLeft(root->left_child, ans);
    else
        traverseLeft(root->right_child, ans);
}

void traverseLeaf(Node* &root, vector<int> &ans){

    // base case
    if(root == NULL){
        return;
    }

    if(root->left_child == NULL && root->right_child == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left_child, ans);
    traverseLeaf(root->right_child, ans);

}

void traverseRight(Node* &root, vector<int> &ans){

    // base case
    if(root == NULL || (root->left_child == NULL && root->right_child == NULL)){
        return;
    }
    
    if(root->right_child){
        traverseRight(root->right_child, ans);
    }
    else{
        traverseRight(root->left_child, ans);
    }

    // wapas aagye
    ans.push_back(root->data);

}

vector<int> boundary(Node* root){

    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);
    
    // left part store
    traverseLeft(root->left_child, ans);

    // traverse leaf node
        // left subtree
        traverseLeaf(root->left_child, ans);
        // right subtree
        traverseLeaf(root->right_child, ans);
    
    // traverse right part
    traverseRight(root->right_child, ans);


    return ans;

}

int main(){
    
    Node* root = NULL;
    build_from_level_order(root);

    levelOrderTraversal(root);
    cout<<endl;

    vector<int> ans = boundary(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    

}