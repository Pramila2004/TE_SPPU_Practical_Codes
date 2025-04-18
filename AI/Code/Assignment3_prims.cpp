
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int v=0, e=0;

    cout<<"Enter no of Vertices : ";
    cin>>v;
    cout<<"Enter no of Edges : ";
    cin>>e;

    vector<vector<pair<int,int>>> adj(v);

    for (int i = 0; i < e; i++){
        int s,d,w;
        cout<<"Enter source, Destination and weight : ";
        cin>>s>>d>>w;
        adj[s].push_back(make_pair(d, w));
        adj[d].push_back(make_pair(s,w));

    }

    vector<int> key(v);
    vector<bool> mst(v);
    vector<int> parent(v);

    for (int  i = 0; i < v; i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;

    }

    key[0]=0;
    parent[0]=-1;


    for (int i = 0; i < v; i++){

        //find minimum from key
        int mini=INT_MAX;
        int u;
        for (int j = 0; j < v; j++){
            if(mst[j]==false && key[j]<mini){
                mini=key[j];
                u=j;
            }
        }

        //set mst[u]=true 

        mst[u]=true;


        //explore adjacent nodes 

        for (auto it: adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                key[v]=w;
                parent[v]=u;
            }
        }
        
        
    }
    
    cout << "Edges in MST:\n";
    for (int i = 1; i < v; i++) {
        cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }

    int minCost = 0;

    for (int i = 0; i < v; i++) {
        if (key[i] != INT_MAX)
            minCost += key[i];
    }

    cout << "Minimum Spanning Tree Cost: " << minCost << endl;

    return 0;
}