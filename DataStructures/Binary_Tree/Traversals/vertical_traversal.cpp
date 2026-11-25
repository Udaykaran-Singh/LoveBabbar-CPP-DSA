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

vector<int> verticalOrder(Node* &root){

    // MAP CREATED : 
    // {horizontal level -> (depth -> list of nodes)}
    map<int, map<int, vector<int> > > nodes;

    // {Node* -> (horizontal level , depth)}
    queue< pair<Node*, pair<int, int> > > q;

    // ans that we want to return.
    vector<int> ans;

    // setting root at (0,0)
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()){

        pair<Node*, pair<int, int> > temp = q.front();
        q.pop();

        // getting all information out.
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        // to node we are at make an entry in MAP corresponding to that
        nodes[hd][lvl].push_back(frontNode->data);

        
        if(frontNode->left_child)
            q.push(make_pair(frontNode->left_child, make_pair(hd - 1, lvl + 1)));

        if(frontNode->right_child)
            q.push(make_pair(frontNode->right_child, make_pair(hd + 1, lvl + 1))); 

    }

    for(auto i:nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;

}

int main(){
    
    Node* root = NULL;
    build_from_level_order(root);

    levelOrderTraversal(root);
    cout<<endl;

    vector<int> ans = verticalOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;

}