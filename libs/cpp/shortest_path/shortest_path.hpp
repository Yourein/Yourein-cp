#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

namespace Yourein{
    struct edge{
        int from;
        int to;
        long long cost;
        int id;

        edge(int _from, int _to, long long _cost, int _id) : from(_from), to(_to), cost(_cost), id(_id) {}
    };

    const long long INF = 100100100100100100LL;

    pair<vector<long long>, vector<long long>> dijkstra(const vector<vector<edge>> &g, int start){
        vector<long long> dist(g.size(), INF), epath(g.size(), -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        
        dist[start] = 0;
        epath[start] = 0;

        q.push({dist[start], start});
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int now = p.second;
            if (dist[now] < p.first) continue;

            for (auto &e : g[now]){
                if (dist[e.to] > dist[now] + e.cost){
                    dist[e.to] = dist[now] + e.cost;
                    epath[e.to] = e.id;
                    q.push({dist[e.to], e.to});
                }
            }
        }
        return {dist, epath};
    }

    pair<vector<vector<long long>>, vector<vector<int>>> warshall_floyd(const vector<vector<long long>> &g){
        vector<vector<long long>> dist(g.size(), vector<long long>(g.size(), INF));
        vector<vector<int>> path(g.size(), vector<int>(g.size(), -1));
        int n = g.size();

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (g[i][j] != -1){
                    dist[i][j] = g[i][j];
                    path[i][j] = i+1;
                }
            }
        }

        for (int i = 0; i < n; i++){
            dist[i][i] = 0;
            path[i][i] = 0;
        }

        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (g[i][j] != -1) dist[i][j] = g[i][j];

        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dist[i][j] > dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                        path[i][j] = path[k][j];
                    }
                }
            }
        }
        return {dist, path};
    }
}
