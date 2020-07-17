/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list<int> *l;
    
    public:
    graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
    }
    bool cycle_helper(int node,bool *visited,bool *stack)
    {
        visited[node]=true;
        stack[node]=true;
        
        for(auto nbr:l[node])
        {
            if(stack[nbr]==true)
            return true;
            else if(visited[nbr]==false)
            {
                bool cycle_mila=cycle_helper(nbr,visited,stack);
                if(cycle_mila==true)
                {
                    return true;
                }
            }
        }
        
        stack[node]=false;
        return false;
    }
    bool cyclecontain(){
       bool *visited=new bool[V];
       bool *stack=new bool[V] ;
       
       for(int i=0;i<V;i++)
       {
           visited[i]=stack[i]=0;
       }
       return cycle_helper(0,visited,stack);
    }
};
int main()
{
    graph g(7);
    
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.addedge(1,5);
    g.addedge(5,6);
    g.addedge(4,2);
    
    if(g.cyclecontain())
    {
        cout<<"Contain cycle"<<endl;
    }
    else
    cout<<"No cycle"<<endl;

    return 0;
}
