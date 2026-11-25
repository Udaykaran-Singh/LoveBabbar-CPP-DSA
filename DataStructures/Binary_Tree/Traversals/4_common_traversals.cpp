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


        // data of left child
        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left_child = new Node(leftData);
            q.push(temp->left_child);
        }


        // data of right child
        cout<<"Enter right node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right_child = new Node(rightData);
            q.push(temp->right_child);
        }

    }

}



/* Methods of Transversal in Binary  Tree */

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

void preorder(Node* root){        // N L R
    // base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left_child);
    preorder(root->right_child);
}

void inorder(Node* root){         // L N R
    // base case
    if(root == NULL){
        return;
    }

    inorder(root->left_child);
    cout<<root->data<<" ";
    inorder(root->right_child);
}

void postorder(Node* root){       // L R N
    // base case
    if(root == NULL){
        return;
    }

    postorder(root->left_child);
    postorder(root->right_child);
    cout<<root->data<<" ";
}



int main(){

    Node* root = NULL;

    // creating a Tree
    build_from_level_order(root);




    // level order printing
    levelOrderTraversal(root);


    // Preorder transversal
    cout<<endl<<"Preorder transversal is :"<<endl;
    preorder(root);


    // Inorder transversal
    cout<<endl<<"Inorder transversal is :"<<endl;
    inorder(root);


    // Postorder transversal
    cout<<endl<<"Postorder transversal is :"<<endl;
    postorder(root);

    return 0;
}