// Construct binary search tree. Provide facility for adding new entries. Provide facility to
// display whole data sorted in descending order using non-recursive traversal.
// Find Minimum and maximum data value in tree. Also find how many maximum
// comparisons may require for finding any keyword.


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


    void Inorder(Node* root){
         if(root == NULL){
            cout<<"Empty"<<endl;
          }

          stack<Node*> st;

          st.push(root);

          Node* node = root;

          while(!st.empty()){
            
            while(node){
                st.push(node);
                node = node->right;

            }

            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node= node->left;
          }

    }

    int SearchElement(Node* root, int key, int &comp){
        if(root == NULL){
            
            return comp;
        }
        comp++;

        if(key == root->data){

            return comp;
        }
        else if(key < root->data){
            SearchElement(root->left , key, comp);
        }
        else if(key > root->data){
            SearchElement(root->right , key, comp);
        }

        return comp;
    }


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


};


int main(){

    BinarySearchTree obj;

    obj.Insert()


return 0;
}

