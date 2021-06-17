#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<int> vis(100001);

int n,m;

void dfs(int node){
    vis[node]=1;

    for(auto child:adj[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }
}

bool connectivity(){

    int node=-1;

    // i have to pick a node with degree greater than 0 than dfs through it to cover nodes connected to it
    for(int i=0;i<n;i++){

        if(adj[i].size()>0){
            node=i; // found a node to starts dfs: 
            break;
        }
    }

    // no edge is present in the graph:
    if(node==-1)
        return true;
    
    dfs(node);

    for(int i=0;i<n;i++){

        // we have got edge in multi component:
        if( vis[i]==0 && adj[i].size()>0)
            return false;
    }

    return true;

}

int count(){

    // counting no of odd degree nodes:
    int cnt=0;
    for(int i=0;i<n;i++){
        if(adj[i].size()%2!=0){
            cnt++;
        }
    }

    return cnt;

}


int main() {

     
    cin>>n>>m;

    for(int i=0;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    if(connectivity()){

        int x=count();
        if(x==0){
            cout<<"Euler Graph \n";
        }
        else if (x==2){
            cout<<"SEMI Eulerian graph \n";
        }
        else{
            cout<<"NOT Eulers Graph \n";
        }
    }
    else{
        cout<<"NOT Eulers Graph \n";
    }


    /*
    for euler graph
        1. start==end
        2. every edge must be visited only once 

        these two points can be condensed into :
        1.. All vertices should hav even degree:


    Euler graph is a Euler circuit:

        All edges in a graph must be present in a single component:(with previous two condition)
        All other componenst should not have any edge and hence should be size of 1 vertex only 

        Trivial Case:: Graph with no edge is a euler graph:

    */

    /*
    EULER PATH:
     Euler path is a path that visits every node edge exactly once 

     SEMI EULERIAN GRAPH :
     1. every edge should be visited once 
     2 .start vertex!= End Vertex 

     ie .EULER PATH WHICH IS NOT EULER CIRCUIT 

     1. Exactly two vertices must have odd degree(start and end ) and others have even degree:
        2. all vertices with non zero degree are connected : multi component case 

    */


    /*
    ALGORITHM STEPS:
    1. connectivity check
    2. count odd degree:
        count==0 euler graph
        count==2 semi eulerian graph
        count>2 not eulerian grph 

    TIME COMPLEXITY: O(V+E);

    NO OF VERTICES OF ODD DEGREE IN AN UNDIRECTED GRAPH IS EVEN :
    */

    return 0;
}
