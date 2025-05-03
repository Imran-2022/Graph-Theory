#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
const int N=1e5+5;
const long long INF=1e18+10;
vector<pair<int,int>>adj[N];
vector<long long> cost(N,INF);
vector<bool>visited(N);
int parent[N];


// Output is the shortest path from node 1 to node n using Dijkstra’s Algorithm.

void dijkstra(int source){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    cost[source]=0;
    pq.push({cost[source],source});

    while(!pq.empty()){
        int u = pq.top().second; // first value for maintaining the pq. 
        visited[u] = true; 
        pq.pop();

        for(pii vpair :adj[u]){
            int v=vpair.first;
            int w=vpair.second;
            if(visited[v])continue;
            if(cost[v]>cost[u]+w){
            //It greedily updates the shortest path cost to every node and ensures the lowest-cost path is always chosen.
                cost[v]=cost[u]+w;
                pq.push({cost[v],v});
                parent[v]=u;
            }
        }
    }

}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src=1;
    dijkstra(1);

    // for(int i=1;i<=n;i++){
    //     cout<<"cost of node : "<< i <<" : ";
    //     cout<<cost[i]<<endl;
    // }

    if(!visited[n]){
        cout<<-1<<endl;
        return 0; 
    }

    int current = n;
    vector<int>paths;
    while(true){
        paths.push_back(current);
        if(current==src)break;
        current=parent[current];
    }

    reverse(paths.begin(),paths.end());
    // cout<<"shortest Path : ";
    for(int i:paths)cout<<i<<" ";
    cout<<endl;

    return 0;
}