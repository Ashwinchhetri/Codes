#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    bool detect_cycle_dfs(int node,int par,vector<int> adj[],vector<int> &vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(detect_cycle_dfs(it,node,adj,vis))
                return true;
            }
            else if(it!=par)
            return true;
        }
        return false;
    }
    bool is_cycle(vector<int> adj[],int V){
        vector<int> vis(V+1,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect_cycle_dfs(i,-1,adj,vis))
                return true;
            }
        }
        return false;
    }
};
void addEdge(int u,int v,vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    graph g;
    int V=5;
    vector<int> adj[V];
    addEdge(0,1,adj);
    addEdge(1,2,adj);
    addEdge(1,4,adj);
    addEdge(4,3,adj);
    addEdge(2,3,adj);

    if(g.is_cycle(adj,V))
    cout<<"Cycle is Present."<<endl;
    else
    cout<<"Cycle Not Present."<<endl;
    return 0;
}
// #include<bits/stdc++.h>

// using namespace std;

// class Solution {

//   public:
//     bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
//       vis[node] = 1;
//       for (auto it: adj[node]) {
//         if (!vis[it]) {
//           if (checkForCycle(it, node, vis, adj))
//             return true;
//         } else if (it != parent)
//           return true;
//       }

//       return false;
//     }
//   public:
//     bool isCycle(int V, vector < int > adj[]) {
//       vector < int > vis(V + 1, 0);
//       for (int i = 0; i < V; i++) {
//         if (!vis[i]) {
//           if (checkForCycle(i, -1, vis, adj)) return true;
//         }
//       }

//       return false;
//     }
// };
// void addEdge(int u,int v,vector<int> adj[]){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// // { Driver Code Starts.
// int main() {

//   int V = 5;
//   int E = 5;
//   vector < int > adj[V];

//   addEdge(0,1,adj);
//     addEdge(1,2,adj);
//     addEdge(1,4,adj);
//     addEdge(4,3,adj);
//     addEdge(2,3,adj);

//   Solution obj;
//   bool ans = obj.isCycle(V, adj);
//   if (ans) {
//     cout << "Cycle Detected";
//   } else cout << "No Cycle Detected";

//   return 0;
// }