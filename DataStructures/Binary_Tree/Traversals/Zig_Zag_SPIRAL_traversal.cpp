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

vector<int> Zig_Zag_traversal(Node* &root){

    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool LeftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        // level process
        for (int i = 0; i < size; i++){
            Node* frontnode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = LeftToRight ? (i) : (size - i - 1);
            ans[index] = frontnode->data;

            if(frontnode->left_child)
                q.push(frontnode->left_child);

            if(frontnode->right_child)
                q.push(frontnode->right_child);
        }

        // direction change
        LeftToRight = !LeftToRight;
        

        for(int i:ans){
            result.push_back(i);
        }
    }

    return result;
}

int main(){
    
    Node* root = NULL;
    build_from_level_order(root);

    vector<int> result = Zig_Zag_traversal(root);

    int size  = result.size();

    levelOrderTraversal(root);
    cout<<endl;

    for (int i = 0; i < size; i++)
    {
        cout<<result[i]<<" ";
    }cout<<endl; 
    
}