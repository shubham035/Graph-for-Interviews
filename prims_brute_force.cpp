#include <bits/stdc++.h>
using namespace std;

// prims algorithm
// greedy algorithm:
// implementation:


int main() {
    // naive approach:
    int n,m,a,b,wt;
    cin>>n>>m;
    // adjacencey list;

    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    int parent[n+1];
    bool mst[n+1];
    int key[n+1];

    // inistialise the array :
    for(int i=0;i<n;i++){
        parent[i]=-1;
        mst[i]=false;
        key[i]=INT_MAX;
    }
    // starting node is 0:
    key[0]=0;
    parent[0]=-1;

// n-1 edges 
    for(int count=0;count<n-1;count++){

        int mini=INT_MAX-1;
        int u;
    // find a  minimal value that is not in mst:
    // O(n^2) complexity: minimum not an  efficient approach
    // space complexity: 
        for(int v=0;v<n;v++){
            if(mst[v]==false && key[v]<mini){
                mini=key[v];
                u=v;
            }
        }

        mst[u]=true;

        for(auto it:adj[u]){

            int v=it.first;
            int weight=it.second;

            if(mst[v]==false && weight<key[v]){
                key[v]=weight;
                parent[v]=u;
            }
        }
    }

    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-"<<i<<"\n";
    }


    return 0;

}
