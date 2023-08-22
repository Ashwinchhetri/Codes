#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int, list<int> > adj ;
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void print() {
        for(auto it : adj){
            cout<<it.first<<"-> ";
            for(auto j : it.second)
            cout<<j<<" , ";
            cout<<endl;
        }
    }
};
int main() {
    graph g;
    int m,u,v;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;
    
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.print();
    return 0;
}