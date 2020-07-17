/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

class Graph{
    public:
    int v;
    list<pair<int,int>> *adj;
    Graph (int v)
    {
        this -> v =v;
        adj=new list<pair<int,int>>[v];
    }
    
    void addedge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int findminindex(int *weight,bool *visited,int v)
    {
        int minindex=-1;
        for(int i=0;i<v;i++)
        {
            if(!visited[i] and (minindex==-1 or weight[i]<weight[minindex]))
            {
                minindex=i;
            }
        }
        return minindex;
    }
    void prims()
    {
        
        bool *visited=new bool[v];
        int *parent=new int[v];
        int *weight=new int[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
            weight[i]=inf;
        }
        parent[0]=-1;
        weight[0]=0;
        for(int i=0;i<v;i++)
        {
            int minindex=findminindex(weight,visited,v);
            visited[minindex]=true;
            for(auto neighbour:adj[minindex])
            {
                if(!visited[neighbour.first])
                {
                    if(weight[neighbour.first]>neighbour.second)
                    {
                        parent[neighbour.first]=minindex;
                        weight[neighbour.first]=neighbour.second;
                    }
                }
                
            }
        }
       for(int i=1;i<v;i++)
       {
           cout<<i<<" -- "<<parent[i]<<" with weight "<<weight[i]<<endl;
       }
    }
};

int main()
{
    int v,e;
    cin>>v>>e;
    Graph g(v);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w);
    }
    g.prims();

    return 0;
}

