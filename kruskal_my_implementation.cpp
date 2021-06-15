#include <bits/stdc++.h>
using namespace std;

// kruskal's algorithm
// greedy algorithm:
// implementation:
// it is implemented easily via disjoint set union 

struct edge{
    int a;
    int b;
    int wt;
};

int par[10001];
edge arr[10001];


bool cmp(edge a ,edge b){

    return a.wt<b.wt;
}

int findPar(int node){

    if(par[node]<0) return node;

    return par[node]=findPar(par[node]);
}

void union_(int a, int b){

    par[b]=a;
}

int main() {
    // naive approach:
    int n,m,a,b,wt;
    cin>>n>>m;
    // adjacencey list;

    for(int i=1;i<=n;i++){
        par[i]=-1;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        arr[i].a=a;
        arr[i].b=b;
        arr[i].wt=wt;
    }

    sort(arr ,arr+m, cmp);

    int sum=0;

    for(int i=0;i<m;i++){
        int x=arr[i].a;
        int y=arr[i].b;
        x=findPar(x);
        y=findPar(y);

        if(x!=y){
            sum+=arr[i].wt;
            union_(x,y);
            cout<<x<<" "<<y<<endl;
        }
    }
  
    cout<<sum<<endl;


    return 0;

}
