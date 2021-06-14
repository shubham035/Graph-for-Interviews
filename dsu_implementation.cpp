#include <iostream>
using namespace std;

int parent[100001];
int rank[1000001];

// BOTH ARE CORRECT JUST TWO DIFFERENT WAY OF IMPLEMNTING IT;
// approach 1:

// void makeSet(){
//     for(int i=0;i<=100000;i++){
//         parent[i]=i;
//         rank[i]=0;
//     }
// }

// int findPar(int noode){

//     if(node==parent[node]) return node;

//     return parent[node]=findPar(parent[node]);
// }

// void union(int u , int v){

//     u=findPar(u);
//     v=findPar(v);

//     if(rank[u]<rank[v]){
//         parent[u]=v;
//     }
//     else if(rank[u]>rank[v]){
//         parent[v]=u;
//     }
//     else{
//         parent[v]=u;
//         rank[u]++;
//     }
// }

// 2 nd implementation which I prefer Generally :
// COMPLEXITY IS o(4*K) which is almost constant:

void makeSet(){

    for(int i=0;i<=100000;i++){
        parent[i]=-1;
        rank[i]=1;
    }
}


int findPar(int node){

    if(parent[node]<0) return node;
    else parent[node]=findPar(parent[node]);
    // if i don't write above line then comlexity is log(n)

}

void union_by_rank(int u , int v){

    u=findPar(u);
    v=findPar(v);

    // as both of them belong to the same component
    if(u==v) return;
    
    // merge smaller into bigger:
    if(rank[u]<rank[v]){
        parent[u]=v;
        rank[v]+=rank[u];
    }
    else{
        parent[v]=u;
        rank[u]+=rank[v];
    }
}

int main() {

    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        union(u,v);
    }
    
    if(findPar(a)!=findPar(b)){
        cout<<"Different copmponent"<<endl;
    }
    else{
        cout<<"Same Component"<<endl;
    }
}
