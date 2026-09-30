#include<iostream>
#include<list>
using namespace std;

class graph{
    int v;
    list<int> *l;

public:
    graph(int V){
        this->v = V;
        l = new list<int> [V];
    }

    void addGraph(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void adjacency(){
        for(int i = 0; i < v; i++){
            cout<<i<<": ";
            for(int neigh: l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){

    graph g(5);

    g.addGraph(0, 1);
    g.addGraph(1, 2);
    g.addGraph(1, 3);
    g.addGraph(2, 3);
    g.addGraph(2, 4);

    g.adjacency();
}


