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

// construct tree
void createMapping(int in[], map<int, int> & nodeToIndex, int n){
    for(int i = 0; i < n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd,int n, map<int, int> &nodeToIndex){
    // base case
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    // create a root node for element
    int element = post[index--];
    Node* root = new Node(element);

    // find element's index in inorder
    int position = nodeToIndex[element];

    // recursive call
    root->right_child = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex);

    root->left_child = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);

    return root;

}

Node* buildTree(int in[], int post[], int n){
    int postOrderIndex = n-1;
    map<int, int> nodeToIndex;

    // create nodes to index mapping
    createMapping(in, nodeToIndex, n);

    Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);

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

    int n = 8;
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    // creating a Tree using inorder and preorder
    root = buildTree(in, post, n);


    // level order printing
    levelOrderTraversal(root);


}