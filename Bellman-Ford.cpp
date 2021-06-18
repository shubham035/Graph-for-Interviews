#include <bits/stdc++.h>
using namespace std;

struct edge{

    int u,v,wt;
    edge(int a, int b, int c){
        u=a;
        v=b;
        wt=c;
    }
};



// Time Complexity ;O(n-1)*O(E);
// space complexity : O(n);
int main() {

    int n,m,a,b,wt;
    cin>>n>>m;

    vector<edge> adj;

    // store all the edges in struct called edges  
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj.push_back(edge(a,b,wt));
    }

    int src;
    cin>>src;

    int maxN=1e8;
    vector<int> dist(n+1,maxN);

    dist[src]=0;
   
    // relax all the edges n-1 times:
    // dist[u]+wt<dist[v] then dist[v]=dist[u]+wt;

    for(int i=0;i<n-1;i++){
        for(auto it : adj){
            int x=it.u;
            int y=it.v;
            int w=it.wt;

            if(dist[x]+w<dist[y]){
                dist[y]=dist[x]+w;
            }
        }
    }

// if we get that a value is still reduced then we can safely say that it is -ve cycle 

    bool flag=false;
    // negative cycle check :

    for(auto it :adj){
        int x=it.u;
        int y=it.v;
        int w=it.wt;

        if(dist[x]+w<dist[y]){
            flag=true;
            break;
        }

    }

    if(flag)
        cout<<"-ve cycle \n";
    else{

        for(int i=0;i<n;i++){
            cout<<i<<" ..."<<dist[i]<<" \n";
        }
    }

    /*
    input:
    6 7
0  1 5
1 5-3
1 2 -2
3 2 6
3 4 -2
2 4 3
5 3 1
0

output::
index... distance 
0 ...0 
1 ...5 
2 ...3 
3 ...3 
4 ...1 
5 ...2 
    */

    return 0;
}
