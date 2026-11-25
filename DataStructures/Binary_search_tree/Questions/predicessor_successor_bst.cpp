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


Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

pair<Node*, Node*> val(Node* root, int key){
    if(root == NULL || root->right == NULL && root->left == NULL){
        pair<Node*, Node*>  p = make_pair(root, root);
        return p;
    }

    Node* temp = root;
    pair<Node*, Node*> ans;

    while(temp != NULL){
        if(temp->data < key){
            temp = temp->right;
        }
        else if(temp->data > key){
            temp = temp->left;
        }
        else{
            ans.first = maxVal(temp->left);
            ans.second = minVal(temp->right);
            break;
        }
    }

    return ans;

}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create binary search tree :"<<endl;
    takeInput(root);

    levelOrderTraversal(root);

    int key = 2;

    pair<Node*, Node*> ans = val(root, key);

    cout<<"Predecessor : "<<ans.first->data<<endl;
    cout<<"Successor : "<<ans.second->data<<endl;

}