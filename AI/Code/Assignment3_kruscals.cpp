#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}

void makeSet(vector<int> &parent,vector<int> &rank,int v){
    for (int i = 0; i <v ; i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
    
}

int findParent(int node,vector<int> &parent){
    if(parent[node]==node){
        return node;
    }

    return parent[node]=findParent(parent[node],parent);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findParent(u,parent);
    v=findParent(v,parent);

    if(rank[u]>rank[v]){
        parent[v]=u;
    }else if(rank[v]>rank[u]){
        parent[u]=v;
    }else{
        parent[v]=u;
        rank[u]++;
    }

}

int main(){

    int v = 0, e = 0;

    cout << "Enter no of Vertices : ";
    cin >> v;
    cout << "Enter no of Edges : ";
    cin >> e;

    vector<vector<int>> adj;

    for (int i = 0; i < e; i++) {
        int s, d, w;
        cout << "Enter source, Destination and weight : ";
        cin >> s >> d >> w;
        adj.push_back({s, d, w});
    }

    sort(adj.begin(), adj.end(), cmp);

    vector<int> parent(v);
    vector<int> rank(v);

    makeSet(parent, rank, v);

    int minCost = 0;

    for (int i = 0; i < e; i++) {
        int u = adj[i][0];
        int v = adj[i][1];
        int w = adj[i][2];

        if (findParent(u, parent) != findParent(v, parent)) {
            minCost += w;
            unionSet(u, v, parent, rank);
        }
    }

    cout << "Minimum Spanning Tree Cost: " << minCost << endl;


    

    return 0;
}
