int vis[252];
int color[252];
/*

if  questions says we have to find is graph is two clique  graph or not 
then take complementary graph and then check for bipartite 
if the converted graph is bipartite then we say that

If complement is Bipartite, then graph can be divided into two sets U and V such that there is no edge connecting to vertices of same set. This means in original graph, 
these sets U and V are completely connected. Hence original graph could be divided in two Cliques.

*/
bool dfs(vector<vector<int>>& graph,int node , int c){
    vis[node]=1;
    color[node]=c;
    for(auto child:graph[node]){

        if(vis[child]==0){
            dfs(graph,child,c^1);
        }
        else{
            if(color[child]==color[node]) return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& graph) {

    memset(vis,0,sizeof(vis));
    memset(color,0,sizeof(color));
    int n=graph.size();

    for(int i=0;i<n;i++){
        if(vis[i]==0){
            bool ans=dfs(graph,i,0);
            if(ans==false) return false;
        }
    }
    return true;

    
}