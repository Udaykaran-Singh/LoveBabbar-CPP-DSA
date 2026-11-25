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

Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
    Node* res = NULL;

    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){

        Node* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }

        if(front->left_child){
            nodeToParent[front->left_child] = front;
            q.push(front->left_child);
        }

        if(front->right_child){
            nodeToParent[front->right_child] = front;
            q.push(front->right_child);
        }
        
    }

    return res;
}

int burnTree(Node* targetNode, map<Node*, Node*> &nodeToParent){
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(targetNode);
    visited[targetNode] = true;

    int ans = 0;

    while(!q.empty()){

        bool flag = 0;
        int size = q.size();

        for (int i = 0; i < size; i++){
            // process neighbouring nodes
            Node* front = q.front();
            q.pop();

            if(front->left_child && !visited[front->left_child]){
                flag = 1;
                q.push(front->left_child);
                visited[front->left_child] = 1;
            }
            
            if(front->right_child && !visited[front->right_child]){
                flag = 1;
                q.push(front->right_child);
                visited[front->right_child] = 1;
            }

            if(nodeToParent[front] && ! visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }

        }

        if(flag == 1){
            ans++;
        }
        
    }

    return ans;

}

int minTime(Node* root, int target){
    
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);


    return burnTree(targetNode, nodeToParent);;

}

int main(){

    Node* root = NULL;
    // 1 2 3 4 5 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1 -1
    build_from_level_order(root);

    levelOrderTraversal(root);
    cout<<endl;

    int target = 8;
    int ans = minTime(root, target);

    cout<<"Min. time to burn : "<<ans<<endl;


}