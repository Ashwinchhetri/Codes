#include<bits/stdc++.h>
using namespace std;
void kahnsAlgo(vector<int> adj[],int N){
    vector<int> indegree(N,0);
    for(int i=0;i<N;i++){
        for(auto it : adj[i])
        indegree[it]++;
    }
    queue<int> q;
    for(int i=0;i<N;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            if(indegree[it]==0)
            q.push(it);
            indegree[it]--;
        }
    }
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

    kahnsAlgo(adj,m);
    return 0;
}