/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
  map<T,list<T>> adjlst;
  public:
  graph(){
      
  }
  void addedge(T u,T v,bool bidir=true)
  {
      adjlst[u].push_back(v);
      if(bidir)
      {
          adjlst[v].push_back(u);
      }
  }
  void print(){
      for(auto i:adjlst)
      {
          cout<<i.first<<"->";
          for(auto edge:i.second)
          {
              cout<<edge<<",";
          }
          cout<<endl;
      }
  }
  void bfs(T src)
  {
      queue<T> q;
      q.push(src);
      map<T,bool> visited;
      visited[src]=true;
      while(!q.empty())
      {
          T node=q.front();
          cout<<node<<",";
          q.pop();
          for(auto i:adjlst[node])
          {
              if(!visited[i])
              {
                  q.push(i);
                  visited[i]=true;
              }
          }
      }
  }
  void dfshelper(T node,map<T,bool> &visited)
  {
      visited[node]=true;
      cout<<node<<",";
      for(auto i:adjlst[node])
      {
          if(!visited[i])
          {
              dfshelper(i,visited);
          }
      }
  }
  void dfs(T src)
  {
  	map<T,bool> visited;
  	dfshelper(src,visited);
  }
  void dfsforcalculatingconnectedcomponents(T src)
  {
      map<T,bool> visited;
      int component=1;
      dfshelper(src,visited);
      cout<<endl;
      for(auto i:adjlst)
      {
          T city=i.first;
          if(!visited[city])
          {
              dfshelper(city,visited);
              component++;
          }
      }
      
      cout<<endl;
      cout<<"The graph has "<<component<<" components"<<endl;
  }
  void dfshelpertopological(T node, map<T,bool> &visited,list<T> &ordering)
    {
        visited[node]=true;
        for(auto i : adjlst[node])
        {
            if(!visited[i])
            {
                dfshelpertopological(i,visited,ordering);
            }
        }
        ordering.push_front(node);
        
    }
    void dfstopologicalsort()
    {
        map<T,bool> visited;
        list<T> ordering;
       for(auto i:adjlst)
       {
           T node=i.first;
        if(!visited[node])
        {
            dfshelpertopological(node,visited,ordering);
        }
       }
        for(T element:ordering)
        {
            cout<<element<<"->";
        }
    }
    void bfstopologicalsort()
    {
        queue<T> q;
        map<T,bool> visited;
        map<T,int> indegree;
        
        for(auto i:adjlst)
        {
            T node=i.first;
            visited[node]=false;
            indegree[node]=0;
        }
        
        for(auto i:adjlst)
        {
            T u=i.first;
            for(auto v:adjlst[u])
            {
                indegree[v]++;
            }
        }
        for(auto i:adjlst)
        {
            T node=i.first;
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<"->";
            for(auto i:adjlst[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        
    }
    bool iscyclicundirectedbfs(T src){
        map<T,bool> visited;
        map<T,int> parent;
        queue<T> q;
        visited[src]=true;
        q.push(src);
        parent[src]=src;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(auto neighbour:adjlst[node])
            {
                if(visited[neighbour]==true && parent[node]!=neighbour)
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    q.push(neighbour);
                    parent[neighbour]=node;
                }
            }
        }
        return false;
    }
    bool iscyclichelperdirecteddfs(T node,map<T,bool>visited,map<T,bool>instack)
    {
        visited[node]=true;
        instack[node]=true;
        for(auto neighbour:adjlst[node])
        {
            if(!visited[neighbour]&&iscyclichelperdirecteddfs(neighbour,visited,instack)||instack[neighbour])
            return true;
        }
        instack[node]=false;
        return false;
    }
    bool iscyclicdirecteddfs(){
        map<T,bool>visited;
        map<T,bool>instack;
        for(auto i:adjlst)
        {
            T node=i.first;
            if(!visited[node])
            {
               bool cycle= iscyclichelperdirecteddfs(node,visited,instack);
                if(cycle)
                return true;
            }
        }
        return false;
    }
    bool iscyclichelperundirecteddfs(T node,map<T,bool>&visited,T parent)
    {
        visited[node]=true;
        for(auto neighbour:adjlst[node])
        {
            if(!visited[neighbour])
            {
                bool cycledetected=iscyclichelperundirecteddfs(neighbour,visited,node);
                if(cycledetected)
                return true;
            }
            else if(neighbour!=parent)
            {
                return true;
            }
        }
        return false;
        
    }
    bool iscyclicundirecteddfs(){
        map<T,bool>visited;
        for(auto i:adjlst)
        {
            T node=i.first;
            if(!visited[node])
            {
               bool cycle= iscyclichelperundirecteddfs(node,visited,node);
                if(cycle)
                return true;
            }
        }
        return false;
    }
};

int main()
{
   graph<string> g;
   g.addedge("putin","trump",false);
   g.addedge("putin","modi",false);
   g.addedge("putin","pope",false);
   g.addedge("modi","trump",true);
   g.addedge("modi","yogi",true);
   g.addedge("yogi","prabhu",false);
   g.addedge("prabhu","modi",false);
   g.print();
   /*graph<string> g;
    g.addedge("english","pl",false);
    g.addedge("math","pl",false);
    g.addedge("pl","html",false);
    g.addedge("pl","python",false);
    g.addedge("pl","java",false);
    g.addedge("pl","js",false);
    g.addedge("python","web",false);
    g.addedge("html","css",false);
    g.addedge("css","js",false);
    g.addedge("js","web",false);
    g.addedge("java","web",false);
    g.addedge("python","web",false);
    g.bfstopologicalsort();
*/
/*
graph<int> g;
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(4,3);
    if(g.iscyclicundirectedbfs(1))
    cout<<"yes";
    else
    cout<<"no";*/
    /*
    graph<int> g;
   g.addedge(0,2,false);
   g.addedge(0,1,false);
   g.addedge(2,3,false);
   g.addedge(2,4,false);
   g.addedge(3,0,false);
   g.addedge(4,5,false);
   g.addedge(1,5,false);
   if(g.iscyclicdirecetddfs())
   cout<<"YES";
   else
   cout<<"No";*/
   /*
    graph<int> g;
   g.addedge(1,4);
   g.addedge(1,2);
   g.addedge(2,3);
   g.addedge(3,4);
   if(g.iscyclic())
   cout<<"YES";
   else
   cout<<"No";
   */
    return 0;
}

