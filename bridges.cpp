#include<bits/stdc++.h>
using namespace std;
// back edges can never be bridges 

vector<int> g[100001];
int vis[100001];
int in_time[100001];
int low[100001];
int timer;

void dfs(int node, int par){
    vis[node]=1;
    in_time[node]=low[node]=timer;
    timer++;
    for(int child:g[node]){

        if(child==par) continue;

        if(vis[child]==1){
            // edge node->child is back edge 

            low[node]=min(low[node],in_time[child]);
        }
        else{
            // forawrd edge
            dfs(child,node);
        // it means that child is not connected to any ancesstor of node 
            // ie. if the if condition is false :: even if we remove this node then it is connected with a ancesstor of the currnode: and hence removing this node will not affected  no of connected component so no bridfe if condition fails
            if(low[child]>in_time[node]){
                // here we can have cnt as counter to count no of brides:

                cout<<node<<" "<<child<<" "<<" is a bridge \n";

            }
              low[node]=min(low[node],low[child]);
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    while(m--){
        int x,y;
        cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
    }

    dfs(1,-1);
    return 0;
}
