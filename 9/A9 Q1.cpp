#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const ll INF = (1LL<<60);
// Weighted undirected graph adjacency list: adj[u] = vector of (v,weight)
struct Graph {
    int V;
    vector<vector<pair<int,int>>> adj;
    Graph(int V=0){ init(V); }
    void init(int n){ V=n; adj.assign(n, {}); }
    void addEdgeUndirected(int u,int v,int w=1){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    void addEdgeDirected(int u,int v,int w=1){
        adj[u].push_back({v,w});
    }
};
vector<int> BFS(const Graph &G,int src){
    int n=G.V;
    vector<int> vis(n,0), order;
    queue<int>q;
    q.push(src); vis[src]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(auto &pr:G.adj[u]){
            int v=pr.first;
            if(!vis[v]){ vis[v]=1; q.push(v); }
        }
    }
    return order;
}
void dfsRec(const Graph &G,int u,vector<int>&vis,vector<int>&order){
    vis[u]=1; order.push_back(u);
    for(auto &pr:G.adj[u]){
        int v=pr.first;
        if(!vis[v]) dfsRec(G,v,vis,order);
    }
}
vector<int> DFS(const Graph &G,int src){
    vector<int> vis(G.V,0), order;
    dfsRec(G,src,vis,order);
    return order;
}
struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0){ init(n); }
    void init(int n_){ n=n_; p.resize(n); r.assign(n,0); for(int i=0;i<n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) p[a]=b;
        else if(r[b]<r[a]) p[b]=a;
        else{ p[b]=a; r[a]++; }
        return true;
    }
};
struct Edge { int u,v; int w; };
vector<Edge> KruskalMST(const Graph &G){
    vector<Edge> edges;
    int n=G.V;
    // build edge list (undirected -> add only once)
    vector<vector<char>> used(n, vector<char>(n,0)); 
    for(int u=0;u<n;u++){
        for(auto &pr:G.adj[u]){
            int v=pr.first, w=pr.second;
            if(!used[u][v]){
                edges.push_back({u,v,w});
                used[u][v]=used[v][u]=1;
            }
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge&a,const Edge&b){ return a.w < b.w; });
    DSU dsu(n); dsu.init(n);
    vector<Edge> mst;
    for(auto &e: edges){
        if(dsu.unite(e.u,e.v)) mst.push_back(e);
        if((int)mst.size()==n-1) break;
    }
    return mst;
}
pair<vector<Edge>, ll> PrimMST(const Graph &G, int start=0){
    int n=G.V;
    vector<char> vis(n,0);
    // min-heap of (weight, u, parent)
    using T = tuple<int,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0,start,-1});
    vector<Edge> mst;
    ll total=0;
    while(!pq.empty()){
        auto [w,u,par] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        if(par!=-1){
            mst.push_back({par,u,w});
            total += w;
        }
        for(auto &pr:G.adj[u]){
            int v=pr.first, wt=pr.second;
            if(!vis[v]) pq.push({wt,v,u});
        }
    }
    // if graph not connected, mst size < n-1
    return {mst, total};
}
vector<ll> Dijkstra(const Graph &G,int src){
    int n=G.V;
    vector<ll> dist(n, INF);
    dist[src]=0;
    using pli = pair<ll,int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto &pr:G.adj[u]){
            int v=pr.first; int w=pr.second;
            if(dist[v] > d + (ll)w){
                dist[v] = d + (ll)w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
void printOrder(const vector<int>&ord){
    for(size_t i=0;i<ord.size();i++){
        if(i) cout<<" -> ";
        cout<<ord[i];
    }
    cout<<"\n";
}
void printEdges(const vector<Edge>&E){
    for(auto &e:E) cout<<e.u<<" - "<<e.v<<" : "<<e.w<<"\n";
}
int main(){
    Graph G(9);
    G.addEdgeUndirected(0,1,4);
    G.addEdgeUndirected(0,7,8);
    G.addEdgeUndirected(1,7,11);
    G.addEdgeUndirected(1,2,8);
    G.addEdgeUndirected(7,8,7);
    G.addEdgeUndirected(7,6,1);
    G.addEdgeUndirected(2,8,2);
    G.addEdgeUndirected(8,6,6);
    G.addEdgeUndirected(2,3,7);
    G.addEdgeUndirected(2,5,4);
    G.addEdgeUndirected(6,5,2);
    G.addEdgeUndirected(3,5,14);
    G.addEdgeUndirected(3,4,9);
    G.addEdgeUndirected(5,4,10);
    cout<<"Graph adjacency (node : (neighbor,weight) ... )\n";
    for(int u=0;u<G.V;u++){
        cout<<u<<": ";
        for(auto &pr:G.adj[u]) cout<<"("<<pr.first<<","<<pr.second<<") ";
        cout<<"\n";
    }
    cout<<"\n";
    // 1) BFS from node 0
    cout<<"BFS order from node 0:\n";
    auto bfs_order = BFS(G,0);
    printOrder(bfs_order);
    cout<<"\n";
    // 2) DFS from node 0
    cout<<"DFS order from node 0:\n";
    auto dfs_order = DFS(G,0);
    printOrder(dfs_order);
    cout<<"\n";
    // 3) Kruskal's MST
    cout<<"Kruskal's MST edges:\n";
    auto mstK = KruskalMST(G);
    printEdges(mstK);
    ll sumK=0; for(auto &e:mstK) sumK += e.w;
    cout<<"Total weight (Kruskal) = "<<sumK<<"\n\n";
    // 3b) Prim's MST (from node 0)
    cout<<"Prim's MST edges (starting at 0):\n";
    auto [mstP, sumP] = PrimMST(G,0);
    printEdges(mstP);
    cout<<"Total weight (Prim) = "<<sumP<<"\n\n";
    // 4) Dijkstra from node 0
    cout<<"Dijkstra shortest paths from node 0:\n";
    auto dist = Dijkstra(G,0);
    for(int i=0;i<G.V;i++){
        cout<<"0 -> "<<i<<" = ";
        if(dist[i]>=INF) cout<<"INF\n"; else cout<<dist[i]<<"\n";
    }
    cout<<"\n";
    return 0;
}
