#include<iostream>
#include<vector>
#include<list>
using namespace std;

class graph{
    int V;
    list<int> *l;

public:
    graph(int val){
        this->V = val;
        l = new list<int> [val];

    }

    void addGraph(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
    }

    void adjacency(){
        for(int i = 0; i < V; i++){
            cout<<i<<": ";
            for(int neigh: l[i]){
                cout<<neigh;
            }
            cout<<endl;
        }
    }


    bool isCycleGraph(int src, int par, vector<bool> &Vis){
        Vis[src] = true;

        for(int neigh: l[src]){
            if(!Vis[neigh]){
                if(isCycleGraph(neigh, src, Vis)) return true;
            }else if(neigh != par) return true;
        }

        return false;
    }

    bool isCycle(){
        vector<bool> Vis(V, false);

        for(int i =0; i < V; i++){
            if(!Vis[i]){
                if(isCycleGraph(i, -1, Vis)) return true;
            }
        }
        return false;
    }

};

int main(){

    graph g(5);
    g.addGraph(0, 1);
    g.addGraph(1, 2);
    g.addGraph(2, 0);
    g.addGraph(0, 3);
    g.addGraph(3, 4);

    g.adjacency();

    cout<<endl;

    if(g.isCycle()){
        cout<<"Cycle graph"<<endl;
    }else{
        cout<<"Not a Cycle graph";
    }

}