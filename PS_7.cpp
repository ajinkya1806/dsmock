// Beginning with an empty binary search tree. Construct the binary search tree by inserting
// the values in given order. After constructing binary search tree perform following
// operations 1) Find numbers of node in longest path 2) Minimum and maximum data value
// found in tree 3) Change a tree so that the roles of the left and right pointers are swapped at
// every node. 4) Display in level order.


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int d){
         this->data = d;
         this->left = NULL;
         this->right = NULL;
    }
};


class BinarySearchTree{
    public:
    Node* root;

    BinarySearchTree(){
        root = NULL;

    }

    Node* Insert(Node* root , int d){
         if(root == NULL){
            return new Node(d);
         }

         if(root->data < d){
            root->right = Insert(root->right, d);
         }
         else if(root->data > d){
            root->left = Insert(root->left, d);
         }

         return root;
    }


   /// Traverse data in decending order


    // void Inorder(Node* root){
    //      if(root == NULL){
    //         cout<<"Empty"<<endl;
    //       }

    //       stack<Node*> st;

    //       st.push(root);

    //       Node* node = root;

    //       while(!st.empty()){
            
    //         while(node){
    //             st.push(node);
    //             node = node->right;

    //         }

    //         node = st.top();
    //         st.pop();
    //         cout<<node->data<<" ";
    //         node= node->left;
    //       }

    // }

    // int SearchElement(Node* root, int key, int &comp){
    //     if(root == NULL){
            
    //         return comp;
    //     }
    //     comp++;

    //     if(key == root->data){

    //         return comp;
    //     }
    //     else if(key < root->data){
    //         SearchElement(root->left , key, comp);
    //     }
    //     else if(key > root->data){
    //         SearchElement(root->right , key, comp);
    //     }

    //     return comp;
    // }


    Node * minValue(Node* root){
        if(root == NULL){
            return NULL;
        }

        while(root && root->left ){
            root = root->left;
        }

        return root;
    }

    Node * maxValue(Node* root){
        if(root == NULL){
            return NULL;
        }

        while(root && root->right ){
            root = root->right;
        }

        return root;
    }

    void SwapElement(Node* root){
        if(root == NULL){
            return;
        }

        SwapElement(root->left);
        SwapElement(root->right);

        Node* temp= root->left;
        root->left = root->right;
        root->right = temp;
    }

    void LevelOrder(Node* root){
        if(root){
            cout<<root->data<<" ";
            LevelOrder(root->left);
            LevelOrder(root->right);
        }cout<<endl;
    }


    int NumberofNodes_in_Longest_Path(Node* root){
        if(root == NULL){
            return 0;
        }

        int lt = NumberofNodes_in_Longest_Path(root->left);
        int rt = NumberofNodes_in_Longest_Path(root->right);

        return max(lt , rt) + 2;


    }


};


int main(){

    BinarySearchTree obj;


return 0;
}

