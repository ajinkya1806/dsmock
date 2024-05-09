// Construct binary search tree. Provide facility for adding new entries, deleting any
// element. Provide facility to display whole data sorted in ascending order using nonrecursive traversal.
// Search an element present in a tree and display number of
// comparisons required to search.

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

    Node* DeleteNode(Node* root , int d){
        if(root == NULL){
            return NULL;
        }

        if(root->data > d){
            root->left = DeleteNode(root->left , d);
        }
        else if(root -> data < d){
            root->right = DeleteNode(root->right, d);
        }
        else{
            if(root->left==NULL and root->right==NULL)
                return NULL;

            else if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right ==NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else{
                  Node* temp = root->left;
                  while(temp->right ){
                    temp = temp->right;
                  }

                  temp -> right = root->right;
                  Node* newnode = root->left;
                  delete root;
                  return newnode;
            }
        }
    }

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
                node = node->left;

            }

            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node= node->right;
          }

    }

    int SearchElement(Node* root, int key, int &comp){
        if(root == NULL){
            cout<<"Tree is empty: "<<endl;
            return comp;
        }
        comp++;

        if(key == root->data){
            cout<<"Key found "<<endl;
            return comp;
        }
        else if(key < root->data){
            SearchElement(root->left , key, comp);
        }
        else if(key > root->data){
            SearchElement(root->right , key, comp);
        }

        cout<<"Key Not Present"<<endl;
        return comp;
    }


};


int main(){

    BinarySearchTree obj;

    obj.Insert()


return 0;
}

