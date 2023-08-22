#include<bits/stdc++.h>
using namespace std;

void print_stack(stack<int> &s) {
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}

void dfs_topological_sort(int node, vector<int> adj[], int vis[],stack<int> &s){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs_topological_sort(it,adj,vis,s);
        }
    }
    s.push(node);
}

void topo_sort(vector<int> adj[],int m){
    int vis[m];
    stack<int> s;
    memset(vis , 0 , sizeof vis);
    for(int i=0;i<m;i++){
        if(!vis[i])
        dfs_topological_sort(i,adj,vis,s);
    }
    print_stack(s);
}

int main() {
    int n,m;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;
    cout<<"\nEnter the number of edges: "<<endl;
    cin>>m;

    vector<int> adj[m];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    topo_sort(adj,m);
    return 0;
}