#include<iostream>
#include<queue>
#include<map>
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

// counting number of nodes present in tree
int countNode(Node* root){
    if(root == NULL) return 0;

    int ans = 1 + countNode(root->left_child) + countNode(root->right_child);
    return ans;
}

// checking if arr is tightly filled no space b/w two numbers
bool is_CBT(Node* root, int i, int node_count){
    if(root == NULL) return true;

    if(i > node_count) return false;
    else {
        bool left = is_CBT(root->left_child, 2*i , node_count);
        bool right = is_CBT(root->right_child, 2*i + 1, node_count);

        return left&&right;
    }
}

// checking parent greater than children
bool is_max_order(Node* root){
    
    // leaf node
    if(root->left_child == NULL && root->right_child == NULL){
        return true;
    }

    if(root->right_child == NULL){
        return root->data > root->left_child->data;
    } 
    else{
        bool left = is_max_order(root->left_child);
        bool right = is_max_order(root->right_child);

        return left && right && (root->data > root->left_child->data && root->data > root->right_child->data);
    }
}

bool solve(Node* root){
    int index = 1;
    int total_count = countNode(root);
    return is_CBT(root, 1, total_count) && is_max_order(root);
}

int main(){

    Node* root = NULL;
    build_from_level_order(root);

    levelOrderTraversal(root);
    cout<<endl;

    cout<<"is heap : "<<solve(root)<<endl;;

}