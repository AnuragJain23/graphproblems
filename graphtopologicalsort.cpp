/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
  map<T,list<T>> l;
  public:
  void addedge(T x,T y)
  {
      l[x].push_back(y);
  }
  void dfshelper(T src,map<T,bool> &visited,list<T> & ordering)
  {
      visited[src]=true;
      for(auto nbr:l[src])
      {
          if(!visited[nbr])
          dfshelper(nbr,visited,ordering);
      }
      
      ordering.push_front(src);
      return;
  }
  void dfs()
  {
      map<T,bool> visited;
      list<T> ordering;
      
      for(auto p:l)
      {
          T node=p.first;
          visited[node]=false;
      }
      for(auto p:l)
      {
          T node=p.first;
          if(!visited[node])
          {
              dfshelper(node,visited,ordering);
          }
      }
      
      for(auto mem:ordering)
      {
          cout<<mem<<endl;
      }
  }
};
int main()
{
    graph<string> g;
    g.addedge("python","pytorch");
    g.addedge("python","datapreprocessing");
    g.addedge("python","mlbasics");
    g.addedge("datapreprocessing","mlbasics");
    g.addedge("pytorch","deeplearning");
    g.addedge("mlbasics","deeplearning");
    g.addedge("deeplearning","facerecognition");
    g.addedge("dataset","facerecognition");
    
    g.dfs();
    return 0;
}

