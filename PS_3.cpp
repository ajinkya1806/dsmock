// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform inorder, recursive traversal
// • Preorder, post-order non-recursive traversal
// • Find mirror image of a tree 


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



     void Reccursive_inorder(Node* root){
           if(root != NULL){
             Reccursive_inorder(root->left);
              cout<<root->data<<" ";
             Reccursive_inorder(root->right);
            
           }
    }


    vector<int> Iterative_Preorder(Node * root){
        vector<int> preorder;

        if(root == NULL){
            return preorder;
        }

        stack<Node*> st;
        st.push(root);

        Node* node = root;

        while(!st.empty()){
            node = st.top();
            st.pop();

            if(node->right){
                st.push(node->right);
            }

            if(node ->left){
                st.push(node->left);
            }

            preorder.push_back(node->data);
        }

        return preorder;

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


    

   void mirror( Node* node)
{
    if (node == NULL)
        return;
    else {
        Node* temp;
 
        
        mirror(node->left);
        mirror(node->right);
 
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}



};


int main(){

     BinaryTree obj;


     obj.createTree();

       cout<<"Iterative Preorder : ";
    vector<int> v1;
    v1=  obj.Iterative_Preorder(obj.root);
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }cout<<endl;

     cout<<"Iterative Postorder: ";
    vector<int> v2;
    v2 =  obj.Iterative_postorder(obj.root);
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }cout<<endl;


     cout<<"recurrsive post: ";
    obj.Reccursive_inorder(obj.root);
    cout<<endl;


    obj.mirror(obj.root);
     
   




return 0;
}