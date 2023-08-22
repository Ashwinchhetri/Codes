#include<bits/stdc++.h>
using namespace std;

void shortest_path(vector<int> adj[],int n){
    int dis[n];
    int src=0;
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }
    dis[src]=0;
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(dis[node]+1<dis[it]){
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }
    for(int i = 0;i<n;i++) cout << dis[i] << " "; 
}

void addEdge(int u,int v,int wt,vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main() {
    int n;
    cin>>n;
    vector<int> adj[n];
    addEdge(0, 2, 1,adj);
    addEdge(0, 1, 1,adj);
    addEdge(1, 2, 1,adj);
    addEdge(1, 3, 1,adj);
    addEdge(2, 0, 1,adj);
    addEdge(2, 3, 1,adj);
    addEdge(3, 3, 1,adj);
    shortest_path(adj,n);
    return 0;
}