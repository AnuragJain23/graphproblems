#include <bits/stdc++.h>
using namespace std;

struct dsu {

vector<int> par,sz;    
int total_comp;

 void init(int n)
 {
     par.resize(n);
     sz.resize(n);
     for(int i=0;i<n;i++)
     par[i]=i;
     for(int i=0;i<n;i++)
     sz[i]=1;
     int total_comp=n;
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
     int super_parent_x=getsuperparent(x);
     int super_parent_y=getsuperparent(y);
     if(super_parent_y!=super_parent_x)
     {
         par[super_parent_x]=super_parent_y;
         sz[super_parent_y]+=sz[super_parent_x];
         sz[super_parent_x]=0;
         total_comp--;
     }
 }
 
    
}G;

int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    
    G.init(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        G.unite(x,y);
    }
    for(int i=0;i<n;i++)
    {
        int super_parent_i=G.getsuperparent(i);   
        ans+=(n-G.sz[super_parent_i]);
    }
    
    cout<<ans/2<<endl;
}
