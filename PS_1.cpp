// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform preorder recursive traversal
// • Postorder, Inorder non-recursive traversal
// • Count number of leaves, number of internal nodes. 


#include <bits/stdc++.h>
using namespace std;

class Node{
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

class BinaryTree{
    public:


    Node* root;

    BinaryTree(){
        root = NULL;
    }

    void createTree(){
    Node *t;
    if(root == NULL){
        cout << "Enter the root to be inserted" << endl;
        int data;
        cin >> data;
        Node* newNode = new Node(data);
        root = newNode;
    }

    queue<Node*> q;
    Node* node = root;
    q.push(root);

    while(!q.empty()){
        node = q.front();
        q.pop();
        
        int leftdata , rightdata;

        if(!node->left){
            cout << "Enter the data to be inserted in leftnode: ";
            cin >> leftdata;
            if(leftdata != -1){
                t = new Node(leftdata);
                t->left = NULL;
                t->right = NULL;
                node->left = t;
                q.push(t);
            }
        }

        if(!node->right){
            cout << "Enter the data to be inserted in rightnode: ";
            cin >> rightdata;
            if(rightdata != -1){
                t = new Node(rightdata);
                t->left = NULL;
                t->right = NULL;
                node->right = t;
                q.push(t);
            }
        }
    }
}



     void Reccursive_preorder(Node* root){
           if(root != NULL){
             cout<<root->data<<" ";
             Reccursive_preorder(root->left);
             Reccursive_preorder(root->right);
           }
    }


    vector<int> Iterative_inorder(Node* root){
          vector<int> inorder;

          if(root == NULL){
            return inorder;
          }

          stack<Node*> st;

          st.push(root);

          Node* node = root;

          while(!st.empty()){
            
            while(node){
                st.push(node);
                node = node->left;

            }

            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node= node->right;
          }

          return inorder;
    }

    vector<int> Iterative_postorder(Node* root ){
         vector<int> postoder;
        if(root == NULL){
            return postoder;
        }

        stack<Node*> st1, st2;

        st1.push(root);

        Node* node = root;

        while(!st1.empty()){
           node = st1.top();
           st1.pop();
           st2.push(node);

           if(node->left){
              st1.push(node->left);
           }
           if(node->right){
            st1.push(node->right);
           }
        }

        while(!st2.empty()){
            postoder.push_back(st2.top()->data);
            st2.pop();
        }

        return postoder;

    }
    

    int countLeaves(Node* root){
        if(root == NULL){
            return 0;
        }

        else if(root->left == NULL && root->right == NULL){
            return 1;
        }

        return countLeaves(root->left) +  countLeaves(root->right);
    }



};


int main(){

     BinaryTree obj;


     obj.createTree();

       cout<<"Iterative Inorder : ";
    vector<int> v1;
    v1=  obj.Iterative_inorder(obj.root);
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }cout<<endl;

     cout<<"Iterative postorder: ";
    vector<int> v2;
    v2 =  obj.Iterative_postorder(obj.root);
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }cout<<endl;


     cout<<"recurrsive pre: ";
    obj.Reccursive_preorder(obj.root);




return 0;
}