#include <bits/stdc++.h>
#include<vector>
using namespace std;
//Creating new data storage unit for storing edge data
class DSU{
    int n;
    int* parent;
    int *rank;
    public:
    //The number of vertices is passed with the constructor 
    DSU(int x){
        n=x;
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    //find function helps us to determine the parent of the vertex so as to detect the presence of cycle
    int find(int x){
        if(parent[x]==-1){
            return x;
        }
        return find(parent[x]);
    }
    //unite function helps in changing the parent of the vertices and updating which edge has been used
    void unite(int x,int y){
        int p1=find(x);
        int p2=find(y);
        if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        }
        else if(rank[p2]<rank[p1]){
            parent[p2]=p1;
        }
        else{
            parent[p2]=p1;
            rank[p1]++;
        }
    }

};
//creating a function to sort edges according to weights
bool compare(vector<int> x,vector<int> y){
    if(y[2]>x[2]){
        return true;
    }
    return false;
}
class graph{
    vector<vector<int>> list;
    int n;
    public:
        graph(int n){
            this->n=n;
        }
        void add_edge(int s,int d,int w){
            list.push_back({s,d,w});
        }
        void solve(){
            DSU a(n);
            //sorting the edges according to their weights
            sort(list.begin(),list.end(),compare);
            int c=0;
            for(int i=0;i<list.size() && c<n-1;i++){
                int x=list[i][0];
                int y=list[i][1];
                int w=list[i][2];
                if(a.find(x)!=a.find(y)){
                    a.unite(x,y);
                    cout<<x<<" "<<y<<" "<<w<<endl;
                    c++;
                }
            }
        }
};

int main() {
    int n,e;
    cin>>n>>e;
    //Here n denotes the number of vertices and e denotes the number of edges
    graph g(n);
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g.add_edge(x,y,z);
    }
    cout<<endl;
    //solve is the function called for getting the minimum spanning tree
    g.solve();
    return 0;
}