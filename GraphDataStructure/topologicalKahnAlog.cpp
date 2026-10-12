#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class graph
{
public:
    int V;
    list<int> *l;

    graph(int val)
    {
        this->V = val;
        l = new list<int> [val];
    }

    void addGraph(int u, int v)
    {
        l[u].push_back(v);
    }

    void topoSort()
    {
        vector<int> indeg(V, 0);
        vector<int> res;

        for (int u = 0; u < V; u++)
        {
            for (int v : l[u])
            {
                indeg[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0){
                q.push(i);
            }
        }

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int v : l[curr])
            {
                indeg[v]--;
                if (indeg[v] == 0){
                    q.push(v);
                }
                    
            }
        }

        for (int v : res)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main()
{

    graph g(6);
    g.addGraph(4, 0);
    g.addGraph(4, 1);
    g.addGraph(5, 0);
    g.addGraph(5, 2);
    g.addGraph(2, 3);
    g.addGraph(3, 1);

    g.topoSort();

    return 0;
}