#include<iostream>
#include<queue>
#include<list>
#include<vector>
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


    bool BFSCycle(int src, vector<bool> &Vis){
        queue<pair<int, int>> q;
        q.push({src, -1});
        Vis[src] = true;

        while (q.size() > 0)
        {
            int u = q.front().first;
            int parU = q.front().second;

            q.pop();

            list<int> neighb = l[u];
            for (int val: neighb)
            {
                if(!Vis[val]){
                    q.push({val, u});
                    Vis[val] = true;
                }
                else if(val != parU){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> Vis(v, false);

        for (int i = 0; i < v; i++)
        {
            if(!Vis[i]){   
            if(BFSCycle(i, Vis)) return true;
            }
        }
        return false;
    }
};

int main(){

    graph g(5);

    g.addGraph(0, 1);
    g.addGraph(0, 3);
    g.addGraph(0, 2);
    g.addGraph(1, 2);
    g.addGraph(3, 4);

    if(g.isCycle()){
        cout<<"Cycle is exits";
    }else{
        cout<<"Cycle is not exits";
    }

}