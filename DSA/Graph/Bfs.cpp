#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    vector<int> bfsofGraph(int V, vector<int> adj[]){
        vector<int> bfs;
        vector<int> vis(V+1,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return bfs;
    }
};
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> &ans) {
    for(auto it : ans)
    cout<<it<<" ";
}
int main() {
    vector < int > adj[5];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    graph g;
    vector<int> answer = g.bfsofGraph(5,adj);
    print(answer);
    return 0;
}