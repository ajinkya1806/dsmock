// Construct In ordered Threaded binary Search Tree. Perform its inorder traversal. Display
// Smallest and largest value in it. Display lbit and rbit of each node

#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    int rbit;
    int lbit;

    Node(int d){
        this ->data = d;
        this->left = NULL;
        this->right = NULL;
        this->rbit = 0;
        this->lbit = 0;
    }

    friend class TBST;
};

class TBST{
    private:
    Node* root , *head;
   
   public:

   TBST(){
      root = NULL;
      head = NULL;
   }

   Node* get_root(){
    return root;
   }


   void insert(int x){
       if(root == NULL){
        head = new Node(999);
        head->right = head;
        root = new Node(x);
        head->left = root;
        head->lbit=1;
        root->left = head;
        root->right = head;
         return;
       }

       else{
          Node* p = root;
          Node* q = new Node(x);

          while(true){
            if(x == p->data){
                delete q;
                return;
            }
            else if(x < p->data){
                if(p->lbit==1){
                    p=p->left;
                }
                else{
                    q->left = p->left;
                    q->right=p;
                    p->left=q;
                    p->lbit=1;
                    return;
                }
            }
            else{
                if(p->rbit==1){
                    p=p->right;
                }
                else{
                    q->right = p->right;
                    q->left=p;
                    p->right=q;
                    p->rbit=1;
                    return;
                }
            }
          }
       }
   }


   void Inorder(){
      Node* p = root;

      while(p->lbit == 1){
         p = p->left;
      }
      while(p!=head){
        cout<<p->data<<" "<<endl;
        cout<<"The lbit of "<<p->data<<" is : "<<p->lbit<<endl;
        cout<<"The rbit of "<<p->data<<" is : "<<p->rbit<<endl;

        if(p->rbit == 1){
            p = p->right;
            while(p->lbit == 1){
                p = p->left;
            }
        }

        else{
            p = p->right;
        }
      }
      cout<<endl;
   }

   int smallest(){
    Node* p = root;
    while(p->lbit == 1){
        p = p->left;
    }

    return p->data;
   }

    int largest(){
    Node* p = root;
    while(p->rbit == 1){
        p = p->right;
    }

    return p->data;
   }


    
};


int main(){

    TBST tree;

    tree.insert(7);
    tree.insert(8);
    tree.insert(3);
    tree.insert(6);
    tree.insert(10);

    tree.Inorder();


    int sm = tree.smallest();
    int lr = tree.largest();

    cout<<sm<<endl;
    cout<<lr<<endl;


return 0;
}