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

// construct tree
int findPosition(int in[], int element, int n){
    for (int i = 0; i < n; i++)
    {
        if(in[i] == element)
            return i;
    }

    return -1;
    
}

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd,int n){
    // base case
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }

    int element = pre[index++];
    Node* root = new Node(element);
    int position = findPosition(in, element, n);

    // recursive call
    root->left_child = solve(in, pre, index, inorderStart, position - 1, n);
    
    root->right_child = solve(in, pre, index, position + 1, inorderEnd, n);

    return root;

}

Node* buildTree(int in[], int pre[], int n){
    int preOrderIndex = 0;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);

    return ans;
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

int main(){

    Node* root = NULL;

    int n = 6;
    int in[6] = {3, 1, 4, 0, 5, 2};
    int pre[6] = {0, 1, 3, 4, 2, 5};

    // creating a Tree using inorder and preorder
    root = buildTree(in, pre, n);


    // level order printing
    levelOrderTraversal(root);


}