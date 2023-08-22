#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    bool checkforCycle(int node,vector<int> adj[],vector<int> vis){
        queue<pair<int,int>> q;
        vis[node]=true;
        q.push({node,-1});
        while(!q.empty()){
            int s=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it : adj[s]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push({it,s});
                }
                else if(it!=par)
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V,vector<int> adj[]){
        vector<int> vis(V-1,0);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(checkforCycle(i,adj,vis))
                return true;
            }
        }
        return false;
    }
};
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector < int > adj[5];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
   
    graph obj;
    int num=obj.isCycle(5, adj);
    if(num==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
 
    return 0;
}