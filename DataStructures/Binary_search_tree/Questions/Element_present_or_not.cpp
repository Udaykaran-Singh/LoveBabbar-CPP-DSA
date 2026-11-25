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

bool check_presence(Node* &root, int d){

    Node* temp = root;
    while(temp != NULL && temp->data != d){
        if(d < temp->data){
            temp = temp->left;
            continue;
        }
        if(d > temp->data){
            temp = temp->right;
            continue;
        }
    }

   return temp != NULL && temp->data == d; 

}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create binary search tree :"<<endl;
    takeInput(root);

    levelOrderTraversal(root);

    int d = 4;
    bool ans = check_presence(root, d);
    cout<<"present : "<<ans<<endl;


}