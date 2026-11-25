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


// by me
pair<Node*, bool> is_BST(Node* &root){
    // base case
    if(root == NULL){
        pair<Node*, bool> p = make_pair(root, true);
        return p;
    }

    pair<Node*, bool> left = is_BST(root->left_child);
    pair<Node*, bool> right = is_BST(root->right_child);

    pair<Node*, bool> ans;

    if((left.first == NULL || left.first->data < root->data) && (right.first == NULL || right.first->data > root->data) && left.second  && right.second  ){
        ans.first = root;
        ans.second = true;

    }
    else{
        ans.first = root;
        ans.second = false;
        
    }

    return ans;

}


// by sir
bool isbst(Node* root, int min, int max){
    
    // base case
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = isbst(root->left_child, min, root->data);
        bool right = isbst(root->right_child, root->data, max);
        return left && right; 
    }
    else{
        return false;
    }

}

bool validbst(Node* root){
    return isbst(root, -100000, 100000);
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create binary search tree :"<<endl;
    build_from_level_order(root);

    levelOrderTraversal(root);

    // bool ans = is_BST(root).second;
    bool ans = validbst(root);

    cout<<"BST is valid : "<<ans;

}