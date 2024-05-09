#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;


    node(int d)
    {
        data = d;

        left = nullptr;

        right = nullptr;

    }
};

node* createTree(node* root)
{
    int val;
    cout << "Enter any value : \n";
    cin >> val;
    root = new node(val);
    
    if(val==-1)
    {
        return nullptr;
    }

    
    cout << " give data for left of "<<val<<" : ";
        root -> left = createTree(root -> left);

    cout << " give data for right of "<<val<<" : ";
        root -> right = createTree(root -> right);

    return root;
}

void inorder(node* root)
{
    if(root == nullptr) return;

    inorder(root->left);
    
    cout<<root -> data<<" ";
    
    inorder(root -> right);
}

void preorder(node* root)
{
    if(root == nullptr) return;

    cout<<root -> data<<" ";

    preorder(root->left);
    
    preorder(root -> right);
}

void postorder(node* root)
{
    if(root == nullptr) return;

    postorder(root->left);
    
    postorder(root -> right);

    cout<<root -> data<<" ";
}

void levelOrderTraversal (node *root)
{
    queue <node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == nullptr)
        {
            cout<<endl;
            
            if(!q.empty()) q.push(nullptr);

        }

        else
        {
            cout << temp -> data <<" ";

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

}

void inorderIterative(node* root)
{
    stack<node *> st;
    while( root!=nullptr|| !st.empty())
    {
        while (root!=nullptr)
        {
            st.push(root);
            root = root -> left;
        }
        cout<<st.top()->data<<" ";
        root = st.top() -> right;
        st.pop();
    }
}

//  void inorderIterative(Node* root){
//         stack<Node*> st;
//         while( root!=nullptr || !st.empty() ){
//             while(root != nullptr ){
//                 st.push(root);
//                 root = root->left;
//             }
//             cout<<st.top()->data<<" ";
//             root = st.top()->right;
//             st.pop();
//         }
//     }

void preorderIterative(node* root){
        stack<node*> st;
        while( root!=nullptr || !st.empty() ){
            while(root!=nullptr){
                cout<<root->data<<" ";
                st.push(root);
                root = root->left;
            }
            root = st.top()->right;
            st.pop();
        }
    }

void postorderItr(node *root)
    {
        if (root == NULL)
            return;
        stack<node *> s1, s2;
        node *temp = root;
        s1.push(root);
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    int height(node* root){
        if(root==nullptr){
            return 0;
        }

        int left=height(root->left);
        int right=height(root->right);

        return max(left,right)+1;
    }

    int leafNodes(node* root){
        
        if(root==nullptr){
            return 0;
        }

        else if(root->left==nullptr && root->left==nullptr){
            return 1;
        }

        return leafNodes(root->left)+leafNodes(root->right);
    }

    int internalNodes(node *root){

        if (root == nullptr || (root->left == nullptr && root->right == nullptr)){

            return 0;
        }
        
        return 1 + internalNodes(root->left) + internalNodes(root->right);
    }

    node *SwapTree(node *root){

        if (root == nullptr){
            return nullptr;
        }
        node *newRoot = new node(root->data);

        newRoot->left = SwapTree(root->right);

        newRoot->right = SwapTree(root->left);

        return newRoot;

    }




int main()
{
    node* root;
    root = createTree(root);

    cout<<endl;
    inorder(root);

    cout<<endl;
    preorder(root);

    cout<<endl;
    postorder(root);

    cout<<endl;
    levelOrderTraversal(root);

    preorderIterative(root);
    cout<<endl;
    inorderIterative(root);
    cout<<endl;
    postorderItr(root);

    levelOrderTraversal(root);

    node *swap = SwapTree(root);

    levelOrderTraversal(swap);
    
    return 0;
}
// 12 17 8 11 -1 -1 -1 4 25 -1 -1 1 -1 -1 18 9 -1 10 -1 -1 -1 