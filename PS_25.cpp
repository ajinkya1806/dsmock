#include <bits/stdc++.h>
using namespace std;

class MinimumSpanning{
private:
    vector<vector<pair<int,int>>> adj;

public:
    MinimumSpanning(int n){
        adj.resize(n);
    }

    void adjacencyList(int u, int wt , int v){
        adj[u].push_back({v,wt});
        adj[v].push_back({u, wt});
    }

    int minimum_spanning_Tree(int n) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n, 0);
        
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second; 
            int wt = it.first;

            if (visited[node] == 1) {
                continue;
            }

            visited[node] = 1;
            sum += wt;

            for (auto it : adj[node]) {
                int one = it.first;
                int two= it.second;
                if (visited[one] == 0) {
                    pq.push({two, one});
                }
            }
        }

        return sum; 
    }
};

int main() {
    int n = 6; 
    MinimumSpanning g(n);
        g.adjacencyList(0, 2, 1);
        g.adjacencyList(0,1,2);
    g.adjacencyList(1, 3, 2);
    g.adjacencyList(2, 4, 3);
    g.adjacencyList(3, 5, 4);
    g.adjacencyList(4, 6, 5);

    int mstWeight = g.minimum_spanning_Tree(n);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;

    return 0;
}
