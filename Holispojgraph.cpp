/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Graph{
 int V;
 list<pair<int,int>> *l;
 public:
 Graph (int v)
 {
     V=v;
     l=new list<pair<int,int>>[V];
 }
 void addedge(int u,int v,int cost)
 {
     l[u].push_back(make_pair(v,cost));
     l[v].push_back(make_pair(u,cost));
 }
 int dfshelper(int node,bool *visited,int *count,int &ans)
 {
   visited[node]=true;
   count[node]=1;
   for(auto neighbour : l[node])
   {
       int v=neighbour.first;
       if(!visited[v])
       {
           count[node]+=dfshelper(v,visited,count,ans);
           int s=count[v];
           ans+=2*min(s,V-s)*neighbour.second;
       }
   }
   return count[node];
 }
 
 int dfs()
 {
    bool *visited=new bool[V]{0};
    int *count=new int[V]{0};
    int ans=0;
    dfshelper(0,visited,count,ans);
    /*for(int i=0;i<V;i++)
    cout<<count[i]<<" ";*/
    return ans;
 }
};

int main()
{
    Graph g(4);
    g.addedge(0,1,3);
    g.addedge(1,2,2);
    g.addedge(2,3,2);
    cout<<g.dfs();

    return 0;
}

