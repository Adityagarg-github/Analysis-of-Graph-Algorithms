#include <bits/stdc++.h>
using namespace std;
//creating new class to store edges with their weights and their end points
class edge{
    public:
    int w;
    int s;
    int d;
};
//creating a function to sort edges according to weights
bool compare(edge e1,edge e2){
    return e1.w<e2.w;
}
int main() {
    int n,e;
    cin>>n>>e;
    //Here n denotes the number of vertices and e denotes the number of edges
    edge* E=new edge[e];
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        E[i].s=x;
        E[i].d=y;
        E[i].w=z;
    }
    int c=0;
    int i=0;
    //The minimum spanning tree wil contain n-1 edges 
    edge* ans=new edge[n-1];
    //parent array will help us determine whether a cycle is forming or not
    int* parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    sort(E,E+e,compare);
    while(c<n-1){
        edge a=E[i];
        int x=a.s,y=a.d;
        if(parent[x]!=parent[y]);{
            ans[c].s=min(x,y);
            ans[c].d=max(y,x);
            ans[c].w=a.w;
            parent[x]=min(parent[x],parent[y]);
            parent[y]=min(parent[x],parent[y]);
            c++;
        }
        i++;
    }
    cout<<endl;
    for(int j=0;j<n-1;j++){
        edge x=ans[j];
        cout<<x.s<<" "<<x.d<<" "<<x.w<<endl;
    }
    return 0;
}