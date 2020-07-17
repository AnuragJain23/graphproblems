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
 bool isbipartite(int s)
 {
     queue<int> q;
     q.push(s);
     int *colors=new int[V];
     for(int i=0;i<V;i++)
     colors[i]=-1;
     
     colors[s]=0;
     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         for(auto neighbour :l[u])
         {
             if(colors[neighbour]==-1)
             {
                 colors[neighbour]=1-colors[u];
                 q.push(neighbour);
             }
             else if(colors[neighbour]==colors[u])
             {
                 return false;
             }
             
         }
     }
     return true;
 }

};

int main()
{
    Graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,0);
    g.addedge(0,2);
    if(g.isbipartite(0))
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;

    return 0;
}

