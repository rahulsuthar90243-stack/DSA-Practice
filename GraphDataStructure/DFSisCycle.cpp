#include<iostream>
#include<vector>
#include<list>

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
    }

    bool DfSisCycle(int curr, vector<bool> &Vis, vector<bool> &recPath){
        Vis[curr] = true;
        recPath[curr] = true;

        for(int neighb : l[curr]){
            if(!Vis[neighb]){
               if( DfSisCycle(neighb, Vis, recPath)) return true;
            }
            else if(recPath[neighb]) return true;
        }

        recPath[curr] = false;

        return false;
    }

    bool isCycle(){
        vector<bool> Vis(v, false);
        vector<bool> recPath(v, false);

        for (int i = 0; i < v; i++)
        {
            if(!Vis[i]){
                if(DfSisCycle(i, Vis, recPath)) return true;
            }
        }
        return false;
    }

};

int main(){

    graph g(5);

    g.addGraph(1, 0);
    g.addGraph(0, 2);
    g.addGraph(2, 3);
    // g.addGraph(3, 0);

    if(g.isCycle()) cout<<"Cycle is exist"<<endl;
    else cout<<"Cycle don't exist";


}