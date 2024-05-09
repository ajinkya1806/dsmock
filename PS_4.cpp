// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform non-recursive inorder traversal, recursive postorder
// • Level wise printing
// • Display and count leaf nodes
// • Display and count internal nodes


// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform post order recursive traversal
// • Inorder, Preorder non-recursive traversal
// • Find the height of tree


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



     void Reccursive_postorder(Node* root){
           if(root != NULL){
             Reccursive_postorder(root->left);
             Reccursive_postorder(root->right);
             cout<<root->data<<" ";
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
    
    /// LEVEL WISE TRAVERSAL
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


    int countLeaves(Node* root, vector<int> &v){
        if(root == NULL){
            return 0;
        }

        else if(root->left == NULL && root->right == NULL){
            v.push_back(root->data);
            return 1;
        }

        return countLeaves(root->left, v) +  countLeaves(root->right, v);
    }

    int count_nodes(Node* root){
           if(root == NULL){
            return 0;
        }

        int lh = count_nodes(root->left);
        int rh = count_nodes(root->right);

        return 1 + lh + rh;
    }
    

    int internal_nodes(Node* root, vector<int> &v){
        return count_nodes(root) - countLeaves(root, v);
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

     cout<<"Iterative preorder: ";
    vector<int> v2;
    v2 =  obj.Iterative_Preorder(obj.root);
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }cout<<endl;


     cout<<"recurrsive post: ";
    obj.Reccursive_postorder(obj.root);
    cout<<endl;


    vector<int> v;
     int ans =  obj.countLeaves(obj.root, v);
    cout<< " The height of the Tree is: "<<ans<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";                                                                                                  
    }
    cout<<endl;

    vector<int> v1;
    int count = obj.internal_nodes(obj.root , v1);
    cout<<"Count of internal nodes"<<count<<" ";


   




return 0;
}