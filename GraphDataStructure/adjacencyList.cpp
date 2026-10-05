#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class graph{
    int v;
    list<int> *l;

public:
    graph(int V){
        this->v = V;
        l = new list<int> [V+1];
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

    void BFS(){
        queue<int> Q;
        vector<bool> Vir(v+1, false);

        Q.push(1);
        Vir[1] = true;

        while (Q.size() > 0)
        {
            int u = Q.front();
            Q.pop();

            cout << u << " ";
            for(int src: l[u]){
                if(!Vir[src]){
                    Vir[src] = true;
                    Q.push(src);
                }
            }
            // cout << endl;
        }
        
    }

    void dfsHelper(int u, vector<bool> &Vis){
        cout<<u<<" ";
        Vis[u] = true;

        for(int src: l[u]){
            if(!Vis[src]){
                dfsHelper(src, Vis);
            }
        }
    }

    void DFS(){
        int src = 1;
        vector<bool> Vis(v+1, false);

        dfsHelper(src, Vis);
    }

};

int main(){

    graph g(6);
    g.addGraph(1, 2);
    g.addGraph(1, 3);
    g.addGraph(2, 4);
    g.addGraph(4, 3);
    g.addGraph(3, 5);
    g.addGraph(5, 6);

    g.BFS();
    cout<<endl;
    g.DFS();

    // g.adjacency();


    // g.addGraph(0, 1);
    // g.addGraph(1, 2);
    // g.addGraph(1, 3);
    // g.addGraph(2, 3);
    // g.addGraph(2, 4);
    
    // g.addGraph(0, 1);
    // g.addGraph(1, 2);
    // g.addGraph(1, 3);
    // g.addGraph(2, 4);

    // cout<<"BFS: ";
    // g.BFS();

    // cout<<endl;

    // cout<<"DFS: ";
    // g.DFS();
    // g.adjacency();
}


