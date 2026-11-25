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

bool is_identical(Node* &r1, Node* &r2){

    // base cases
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r2 == NULL && r1 != NULL){
        return false;
    }

    bool left = is_identical(r2->left_child, r2->left_child);
    bool right = is_identical(r1->right_child, r2->right_child);

    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }else{
        return false;
    }

}

int main(){
    // A tree is height balanced if difference between heights of left and right subtrees is not more than on for all nodes of tree.

    Node* root1 = NULL;
    build_from_level_order(root1);
    Node* root2 = NULL;
    build_from_level_order(root2);

    bool id = is_identical(root1, root2);

    levelOrderTraversal(root1);
    cout<<endl;
    levelOrderTraversal(root2);
    cout<<endl;


    cout<<"is identical ? :"<<id<<endl;


    return 0;
}