#include<iostream>
#include<queue>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }

};

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
            
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }

        }

    }

}

Node* insertIntoBST(Node* &root, int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        // right side me insert krna ha
        root->right = insertIntoBST(root->right, d);
    }
    else{
        // left me insert kro
        root->left = insertIntoBST(root->left, d);
    }

    return root;

}

void takeInput(Node* &root){

    int data;
    cin>> data;

    while(data != -1){
        insertIntoBST(root, data);
        cin>>data;
    }
}

void K_element(Node* &root, int k, int &i, int &ans){

    if(root == NULL){
        return ;
    }

    K_element(root->left, k, i, ans);
    i++;
    // cout<<root->data<<" "<<i<<" "<<k<<endl;
    if(i > k){
        return;
    }
    if(i == k){
        ans = root->data;
        return;
    }
    K_element(root->right, k, i, ans);


}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create binary search tree :"<<endl;
    takeInput(root);

    levelOrderTraversal(root);

    int k = 3 , i = 0;
    int ans = -1;

    K_element(root, k, i, ans);

    cout<<"kth smallest element is : "<<ans<<endl;

}