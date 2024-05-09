#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
    vector<vector<int>> adjList;

    public:

    Graph(int size){
        adjList.resize(size);
    }

    void adjustancyList(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void BFS_traversal(int vertex){
           vector<int> visited (adjList.size(), 0);
           queue<int> q;
           visited[vertex] = 1;

           q.push(vertex);

           while(!q.empty()){
             int node = q.front();        //// SPACE COMPLEXITY -->> 1 queue 1 visited array and 1 vector for storing ans so O(3N)
             q.pop();                    ////  TIME COMPLEXITY ->> O(N)           +      O(E)
             cout<<node<<" ";                                  //   |                     |
                                                              //  size of queue     number of degree of each vertices
             for(auto it: adjList[node]){
                if(visited[it] == 0){
                    visited[it] = 1;
                    q.push(it);
                }
             }
           }
           cout<<endl;
    }


    void DFS_helper(int vertex, vector<int> &visited){
        visited[vertex] = true;
        cout<<vertex<<" ";

        for(auto it : adjList[vertex]){
            if(visited[it] == 0){
                 DFS_helper(it , visited);
            }
        }
    }

    void DFS_traversal(int vertex){
         vector<int> visited (adjList.size(), 0);     ////  SPACE complexity O(N);
         DFS_helper(vertex , visited);                ///   Time Complexity  O(N) + O(2xE);
         cout<<endl;
    }


 void DFS_Non_Recursive(int vertex) {
    vector<int> visited(adjList.size(), 0);
    stack<int> st;

    st.push(vertex);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        // if (visited[node] == 0) {
            visited[node] = 1;
            cout << node << " ";

            for (auto it : adjList[node]) {
                if (visited[it] == 0) {
                    st.push(it);
                }
            }
        // }
    }
    cout << endl;
}


void count_Degree() {
    for (int i = 1; i < adjList.size(); ++i) {  // Start from vertex 1
        cout << "The degree at vertex " << i << " ---> " << adjList[i].size() << endl;
    }
}


};



int main(){

Graph g(10);

g.adjustancyList(8,5);
g.adjustancyList(5,6);
g.adjustancyList(6,9);
g.adjustancyList(9,5);
g.adjustancyList(5,7);
g.adjustancyList(7,8);


cout << "BFS Traversal:" << endl;
g.BFS_traversal(5);
g.DFS_traversal(4);
g.DFS_Non_Recursive(3);
g.count_Degree();

return 0;
}