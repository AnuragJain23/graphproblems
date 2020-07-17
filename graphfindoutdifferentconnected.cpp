/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Graph{
 int V;
 list<int> *l;
 public:
 Graph (int v)
 {
     V=v;
     l=new list<int>[V];
 }
 void addedge(int u,int v)
 {
     l[u].push_back(v);
     l[v].push_back(u);
 }
 void dfshelper(int i,bool visited[],int &country)
 {
     visited[i]=true;
     country++;
     for(auto neighbour : l[i])
     {
         if(visited[neighbour]==false)
         {
             dfshelper(neighbour,visited,country);
         }
     }
 }
 
 int dfsMoon()
 {
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    int n=V;
    int totalways=(n)*(n-1)/2;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            int country=0;
            dfshelper(i,visited,country);
            totalways-=(country)*(country-1)/2;
            //totalways++;
        }
    }
    return totalways;
 }
};

int main()
{
    Graph g(5);
    g.addedge(0,1);
    g.addedge(2,3);
    g.addedge(0,4);
    cout<<g.dfsMoon()<<endl;

    return 0;
}

