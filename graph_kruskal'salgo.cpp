/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

struct dsu{
    vector<int> par;
    void initialise(int n)
    {
       par.resize(n);
       for(int i=0;i<n;i++)
       par[i]=i;
    }
    int getsuperparent(int x)
    {
        if(x==par[x]) 
        return x;
        else
        {
            return par[x]=getsuperparent(par[x]);
        }
    }
    void unite(int x,int y)
    {
        x=getsuperparent(x);
        y=getsuperparent(y);
        if(x!=y)
        {
            par[x]=y;
        }
    }
    
}G;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        edges[i]={w,x,y};
    }
    sort(edges.begin(),edges.end());
    G.initialise(n);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int x=edges[i][1];
        int y=edges[i][2];
        int w=edges[i][0];
        if(G.getsuperparent(x)!=G.getsuperparent(y))
        {
            G.unite(x,y);
            cout<<x<<" "<<y<<" "<<w<<endl;
            ans+=w;
        }
    }
    cout<<ans<<endl;
    return 0;
}

