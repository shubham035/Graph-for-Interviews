
#include<bits/stdc++.h>
using namespace std;

const int maxN=1e9-1;

int dist[100001];
// int vis[100001];
void shortest_path(int start , int dest, vector<int> adj[], int n){

for(int i=0;i<=n;i++){
    dist[i]=maxN;
    vis[i]=0;
}
dist[start]=0;

queue<int> q;
q.push(start);

// i had done earlier with the help of vis array now we can also do it wrt dis condition
while(!q.empty()){
    int curr=q.front();
    q.pop();
   //  vis[curr]=1;

    for(auto child:adj[curr]){

        // if(vis[child]==0){
        //     dist[child]=1+dist[curr];
        //     q.push(child);
        // }

        if(dist[node]+1<dist[child]){
            dist[child]=dist[node]+1;
            q.push(child);
        }
    }
}

    
}


int main(){

    cout<<dist[dest];
}
    