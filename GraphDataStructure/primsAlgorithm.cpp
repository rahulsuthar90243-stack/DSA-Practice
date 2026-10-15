#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int primMST(int V, vector<vector<pair<int, int>> > adj){
    vector<bool> inMST(V, false);
    int minCost = 0;

    // min heap
    priority_queue<pair < int, int >, vector<pair<int, int >>, greater<pair<int, int >>> pq;

    pq.push({0, 0});

    while (pq.size() > 0)
    {
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;
        pq.pop();

        if(!inMST[u]){
            inMST[u] = true;
            minCost += wt;

            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                int wt = adj[u][i].second;

                if(!inMST[v]) pq.push({wt, v});
            }
            
        }
    }

    return minCost;
}


int main(){
    int V = 4;

    vector<vector<pair< int, int >>> adj(V);

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});

    adj[0].push_back({2, 15});
    adj[2].push_back({0, 15});

    adj[1].push_back({3, 40});
    adj[3].push_back({1, 40});

    adj[2].push_back({3, 50});
    adj[3].push_back({2, 50});

    cout<<"Minimum cost is:" <<primMST(V, adj);

}