///1st problem solved by art point
#include <bits/stdc++.h>
using namespace std;
int start[100000+10];
int finish[100000+10];
int low[100000+10];
int parent[100000+10];
vector<int>Graph[100000+10];
set<int>articulationpoint;
int Time=0,Achild=0;
void DFS(int src)
{
    start[src]=low[src]=++Time;
    for(int i=0; i<Graph[src].size(); i++)
    {
        if(start[Graph[src][i]]==0)
        {
            parent[Graph[src][i]]=src;
            if(src==1)
            {
                Achild++;
            }
            DFS(Graph[src][i]);
        }
        else
        {
            if(parent[Graph[src][i]]!=src)
            {
                low[src]=min(start[Graph[src][i]],low[src]);
            }
        }
    }
    finish[src]=++Time;
    low[parent[src]]=min(low[parent[src]],low[src]);
    if(start[parent[src]]<=low[src] && parent[src]!=1)
    {
        articulationpoint.insert(parent[src]);
    }

}
int main()
{
    int node=1,edge=1;
    while(node!=0 && edge!=0)
    {
        cin>>node>>edge;
        if(node==0 && edge==0)
        {
            break;
        }
        articulationpoint.clear();
        start[0]=low[0]=finish[0]=parent[0]=10e7;
        Achild=0;
        Time=0;
        int n,m;
        for(int i=1;i<=node;i++)
        {
            start[i]=low[i]=finish[i]=parent[i]=0;
            Graph[i].clear();
        }
        for(int i=0; i<edge; i++)
        {
            cin>>n>>m;
            Graph[n].push_back(m);
            Graph[m].push_back(n);
        }
        DFS(1);
        if(Achild>=2)
        {
            articulationpoint.insert(1);
        }
        cout<<articulationpoint.size()<<endl;
    }
    return 0;
}
