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

void solve(Node* &root, vector<int> &ans, int level){
    //  base case
    if(root == NULL){
        return;
    }

    // we entered into a new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right_child, ans, level + 1);
    solve(root->left_child, ans, level + 1);
}

vector<int> leftView(Node* &root){    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    vector<int> ans;
    solve(root, ans, 0);
    return ans;

}

int main(){
    
    Node* root = NULL;
    build_from_level_order(root);

    levelOrderTraversal(root);
    cout<<endl;

    vector<int> ans = leftView(root);   // can also do it bye levelOrderTraversing

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    


}