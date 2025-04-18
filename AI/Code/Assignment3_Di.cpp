#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;
int main(){

    int v=0, e=0;

    cout<<"Enter no of Vertices : ";
    cin>>v;
    cout<<"Enter no of Edges : ";
    cin>>e;

    vector<vector<pair<int,int>>> adj(v);

    for (int i = 0; i < e; i++)
    {
        int s,d,w;
        cout<<"Enter source, Destination and weight : ";
        cin>>s>>d>>w;
        adj[s].push_back(make_pair(d, w));
        adj[d].push_back(make_pair(s,w));

    }


    vector<int> dist(v);
    for (int i = 0; i < v; i++)
    {
        dist[i]=INT_MAX;
    }
    
    set<pair<int,int>> st;

    dist[0]=0;
    st.insert(make_pair(0,0));

    while (!st.empty())
    {
        pair<int,int> topNode = *st.begin(); 
        int distance=topNode.first;
        int node=topNode.second;
        st.erase(st.begin());

        for (auto neighbor : adj[topNode.second])
        {
            if(distance+neighbor.second<dist[neighbor.first]){
                auto record=st.find(make_pair(dist[neighbor.first],neighbor.first));
                if(record!=st.end()){
                    st.erase(record);
                }
                dist[neighbor.first]=distance+neighbor.second;
                st.insert(make_pair(dist[neighbor.first],neighbor.first));
            }
        }
        



    }
    
    for (int i = 0; i < v; i++)
    {
        cout<<dist[i]<<"  ";
    }
    cout<<endl;
    
    


    return 0;
}