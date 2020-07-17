/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define V 4
void printgraph(int dist[][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
            cout<<" INF ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floydwarshall(int graph[][V])
{
    int dist[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }
    
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    
    printgraph(dist);
}
int main()
{  

    int graph[V][V]={ {0,5,INF,10},
                      {INF,0,3,INF},
                      {INF,INF,0,1},
                      {INF,INF,INF,0}
                    };
    floydwarshall(graph);                

    return 0;
}

