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

Node* kth_ancestor(Node* &root, int n, int &k){
    
    // base case 
    if(root == NULL ){
        return NULL;
    }

    if(root->data == n){
        return root;
    }

    Node* left = kth_ancestor(root->left_child, n, k);
    Node* right = kth_ancestor(root->right_child, n, k);



    if(left != NULL && right == NULL ){
        k--;
        if(k == 0){
            return root;
        }
        return  left;
    }

    if(left == NULL && right != NULL ){
        k--;
        if(k == 0){
            return root;
        }
        return right;
    }

    return NULL;
}

int main(){
    Node* root = NULL;
    build_from_level_order(root);

    levelOrderTraversal(root);
    cout<<endl;

    int n = 4, k = 2;

    Node* ans = kth_ancestor(root, n, k);

    cout<<"ans : "<<ans->data<<endl;
    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1

}