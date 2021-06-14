
#include<bits/stdc++.h>
using namespace std;

// cycle check using 2 dfs :

bool checkCycle(int node , vector<int> adj[],int vis[],int dfs_vis[]){
    vis[i]=1;
    dfs_vis[i]=1;

    for(auto child:adj[node]){
        if(vis[child]==0){
            // check if for child cycle check is true or not: 
            if(checkCycle(child,adj,vis,dfs_vis)==true) return true;
        } // now if dfs_vis is also 1 it means both are visited simulatneously which mean detect a cycle
        else if(dfs_vis[child]==1) return true;
    }

    dfs_vis[node]=0;
    return false;
}

bool isCyclic(int n , vector<int> adj[]){

    // vis keep track of all vis node 
    int vis[n+1];
    // dfs vis keep track of evry node visited in that recursion call
    int dfs_vis[n+1];
    memset(vis,0,sizeof(vis));
    memset(dfs_vis,0,sizeof(vis));

    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(checkCycle(i,adj,vis,dfs_vis))
                return true;
        }
    }
    return false;

}

int main(){

    cout<<isCyclic(n,adj);
}
    