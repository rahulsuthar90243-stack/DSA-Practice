#include<iostream>
#include<vector>

using namespace std;

class Edges{
 public:
    int v;
    int wt;

    Edges(int v, int wt){
        this-> v = v;
        this->wt = wt;
    }
};

void bellamFord(int src, vector<vector<Edges>> g, int V){
    vector<int> dis(V, INT8_MAX);
    dis[src] = 0;

    for (int i = 0; i < V-1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for(Edges e: g[u]){
                if(dis[e.v] > dis[u] + e.wt){
                    dis[e.v] = dis[u] + e.wt;
                }
            }
        }
        
    }

    for (int i = 0; i < V; i++)
    {
        cout<<dis[i] << " ";
    }
    cout<<endl;
}

int main(){
int V = 5;
vector<vector<Edges>> g(V);

g[0].push_back(Edges(1, 2));
g[0].push_back(Edges(2, 4));

g[1].push_back(Edges(2, -4));
g[1].push_back(Edges(4, -1));

g[2].push_back(Edges(3, 2));
g[3].push_back(Edges(4, 4));

bellamFord(0, g, V);

}