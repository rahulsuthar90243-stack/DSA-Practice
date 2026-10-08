#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class graph{
public:    
    int V;
    list<int> *l;

    graph(int v){
    this->V = v;
    l = new list<int> [v];
    }

    void addGraph(int u, int v){
    l[u].push_back(v);  //directed graph
    }

    void DFSTopo(int curr, vector<bool> &Vis, stack<int> &s){

        Vis[curr] = true;

        for(int v: l[curr]){
            if(!Vis[v]){
                DFSTopo(v, Vis, s);
            }
        }

        s.push(curr);
    }

    void isTopological(){
        vector<bool> Vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if(!Vis[i]){
                DFSTopo(i, Vis, s);
            }
        }

        while (s.size() > 0)
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }

};


int main(){
    graph g(6);

    g.addGraph(5, 0);
    g.addGraph(4, 0);
    g.addGraph(5, 2);
    g.addGraph(2, 3);
    g.addGraph(3, 1);
    g.addGraph(4, 1);

    g.isTopological();

}