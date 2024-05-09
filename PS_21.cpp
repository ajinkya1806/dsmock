#include <bits/stdc++.h>
using namespace std;


class Heap{
     public:

     void insert(vector<int> &A, int n){
        int i=n;
       int  temp = A[i];

        while(i>1 && temp > A[i/2] ){
            A[i] = A[i/2];
            i=i/2;
        }

        A[i] = temp;
     }


     void create(vector<int> &A, int n){
          for(int i=2; i<=n; i++){
            insert(A, i);
          }
     }

     void Delete(vector<int> &A, int n){
        int i,j,x;
        x=A[1];
        A[1] = A[n];

        i=1;
        j= 2*i;

        while(j<=n-1){
            if(A[j+1] > A[j]){
                j = j+1;
            }

            if(A[i] < A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i=j;
                j = 2*j;
            }
            else{
                break;
            }
        }
        A[n] = x;

     }
};

int main(){

    Heap h;
    vector<int> v{0,10,20,30,25,5,40,35};

    h.create(v, v.size()-1);

    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;



    for(int i=v.size()-1; i>1; i-- ){
           h.Delete(v,i);
    }

    for(int i=1; i<=7; i++){
        cout<<v[i]<<" ";
    }cout<<endl;


return 0;
}