#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;

    Node(string k, string m){
        this->keyword = k;
        this->meaning = m;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }


};

class AVLTree{
    public:
    Node* root;

     AVLTree(){
        root = NULL;
     }

     int maxHeight(Node* root){
        if(root == NULL){
            return 0;
        }

        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right);

        return 1 + max(lh,rh);
     }

     int BalanceFactor(Node* root){
        if(root == NULL){
            return 0;
        }

        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right);

        return (lh-rh);
     }


     Node* Insert(Node* &root, string key, string mean){
        if(!root){
            return new Node(key, mean);
        }
        if(key < root->keyword){
            root->left = Insert(root->left, key, mean);
        }
        else if(key > root->keyword){
            root->right = Insert(root->right, key, mean);
        }
        
        root->height = maxHeight(root);

      if(BalanceFactor(root) >= 2 && BalanceFactor(root->left) ==1){
         return LLrotation(root);
      } 
      else if(BalanceFactor(root) >= 2 && BalanceFactor(root->left) == -1){
           return LRrotation(root);
      }
      else if(BalanceFactor(root) <= -2 && BalanceFactor(root->right) == 1){
        return RRrotation(root);
      }
      else if(BalanceFactor(root) <= -2 && BalanceFactor(root->right) == -1){
        return RRrotation(root);
      }
      

      return root;

     }



     Node*  LLrotation(Node* node){

        Node* nl = node->left;
        Node* nlr = nl->right;


        nl->right = node;
        node->left = nlr;

        node->height = maxHeight(node);
        nl->height = maxHeight(nl);

        if(root == node){
            root = nl;
        }

        return nl;

     }
     
     Node*  LRrotation(Node* node){

        Node* nl = node->left;
        Node* nlr = nl->right;


        nl->right = nlr->left;
        node->left = nlr->right;

        

        nlr ->left = nl;
        nlr->right = node;


        node->height = maxHeight(node);
        nlr->height = maxHeight(nlr);
        nl->height = maxHeight(nl);

        if(root == node){
            root = nlr;
        }

        return nlr;

     }
    

    Node*  RRrotation(Node* node){

        Node* nr = node->right;
        Node* nrl = nr->left;


        nr->left = node;
        node->right = nrl;

        node->height = maxHeight(node);
        nr->height = maxHeight(nr);

        if(root == node){
            root = nr;
        }

        return nr;

     }

     Node* RLrotation(Node* node){
        Node* nr = node->right;
        Node* nrl = nr->left;

        nr->left = nrl->right;
        node->right = nrl->left;

        nrl->left = node;
        nrl->right = nr;

        node->height = maxHeight(node);
        nr->height = maxHeight(nr);
        nrl->height = maxHeight(nrl);

        if(root == node){
            root = nrl;
        }

        return nrl;
     }

     

   void inOrderTraversal(Node* node) {
    if (node == nullptr)
        return;
    
    inOrderTraversal(node->left);
    int balanceFactor = BalanceFactor(node);
    cout << node->keyword << ": " << node->meaning << " (Balance Factor: " << balanceFactor << ")" << endl;
    inOrderTraversal(node->right);
}

   void reverseOrderTraversal(Node* node) {
    if (node == nullptr)
        return;
    
    reverseOrderTraversal(node->right);
    int balanceFactor = BalanceFactor(node);
    cout << node->keyword << ": " << node->meaning << " (Balance Factor: " << balanceFactor << ")" << endl;
    reverseOrderTraversal(node->left);
}



    Node* findNode(Node* root, string key, int &comparison){
        if(root == NULL){
            return NULL;
        }

        comparison ++;

        if(root->keyword == key){
            return root;
        }
        else if(root->keyword > key){
            return findNode(root->left, key, comparison);
        }
        else if(root->keyword < key){
            return findNode(root->right, key, comparison);
        }
        else{
            return root;
        }
    }

    

     


     


};


int main(){

    AVLTree obj;

    for(int i=0; i<4; i++){
        string s1 ;
        cout<<"Enter: ";
        cin>>s1;
        cout<<endl;
        string s2 ;
        cout<<"Enter: ";
        cin>>s2;
        cout<<endl;
      obj.root =  obj.Insert(obj.root, s1, s2 );
    }


    cout<<"Acending Order: ";
    obj.inOrderTraversal(obj.root);

    cout<<"Decending order: ";
    obj.reverseOrderTraversal(obj.root);


    cout<<"Enter the string to be search"<<endl;
    string str;
    cin>>str;
    int cmp;
    obj.root = obj.findNode(obj.root, str, cmp);

    cout<<cmp<<endl;

   



return 0;
}