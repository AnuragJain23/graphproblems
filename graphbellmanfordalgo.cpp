/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
class Edge{
  public:
  int src,dest,weight;
};
class Graph{
    public:
    int v,e;
    Edge *edge;
    Graph (int v,int e)
    {
        this -> v =v;
        this -> e=e;
        edge = new Edge[e];
    }
    
    void addedge(int u,int v,int w,int count)
    {
        edge[count].src=u;
        edge[count].dest=v;
        edge[count].weight=w;
    }
    void bellmanford(int src)
    {
        int distance[v];
        for(int i=0;i<v;i++)
        {
            if(i==src)
            distance[i]=0;
            else
            distance[i]=inf;
        }
        for(int i=1;i<v;i++)
        {
            for(int j=0;j<e;j++)
            {
                int src=edge[j].src;
                int dest=edge[j].dest;
                int wt=edge[j].weight;
                
                if(distance[src]!=inf and distance[dest]>distance[src]+wt)
                {
                    distance[dest]=distance[src]+wt;
                }
            }
        }
        
        for(int j=0;j<e;j++)
        {
                 int src=edge[j].src;
                    int dest=edge[j].dest;
                    int wt=edge[j].weight;
                    
                    if(distance[src]!=inf and distance[dest]>distance[src]+wt)
                    {
                       cout<<"graph contain -ve weighted cycle"<<endl;
                       return;
                    }
        }
        
        for(int i=0;i<v;i++)
        {
            cout<<i<<" - "<<distance[i]<<endl;
        }
    }
};

int main()
{
    int v,e;
    cin>>v>>e;
    Graph g(v,e);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w,i);
    }
    g.bellmanford(0);

    return 0;
}

