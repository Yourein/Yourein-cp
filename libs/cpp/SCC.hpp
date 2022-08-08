#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

namespace Yourein{
    struct SCC{
        public:
            SCC(int n) : _n(n), ids(n, 0) {}

            int size() {return _n;}
            void push_edge(int s, int t){
                if ((s < 0 || s >= _n) && (t < 0 || t >= _n)) throw std::invalid_argument("Node selectors out of bound: s, t");
                if (s < 0 || s >= _n) throw std::invalid_argument("Node selector out of bound: s");
                if (t < 0 || s >= _n) throw std::invalid_argument("Node selector out of bound: t");
                g_edges.push_back({s, {t}});
            }

            std::pair<int, std::vector<int>> scc_ids() {
                Sparse_table g = Sparse_table(_n, g_edges);
                int now_ord = 0, group_num = 0;
                std::vector<int> explored, low(_n), ord(_n, -1);
                
                explored.reserve(_n);

                auto dfs = [&](auto self, int v) -> void {
                    low[v] = ord[v] = now_ord++;
                    explored.push_back(v);

                    for (int i = g.start[v]; i < g.start[v+1]; i++){
                        int to = g.elist[i].t;
                        if (ord[to] == -1){
                            self(self, to);
                            low[v] = std::min(low[v], low[to]);
                        }
                        else{
                            low[v] = std::min(low[v], ord[to]);
                        }
                    }

                    if (low[v] == ord[v]) {
                        while(1){
                            int u = explored.back();
                            explored.pop_back();
                            ord[u] = _n;
                            ids[u] = group_num;
                            if (u == v) break;
                        }
                        group_num++;
                    }
                };
                for (int i = 0; i < _n; i++) if (ord[i] == -1) dfs(dfs, i);
                for (auto &x : ids) x = group_num - 1 - x;

                return {group_num, ids};
            }

            std::vector<std::vector<int>> init_scc(){
                std::pair<int, std::vector<int>> ids = scc_ids();
                int group_num = ids.first;
                counts.assign(group_num, 0);
                for (auto x : ids.second) counts[x]++;
                scc_res.resize(group_num);
                for (int i = 0; i < group_num; i++) scc_res[i].reserve(counts[i]);
                for (int i = 0; i < _n; i++) scc_res[ids.second[i]].push_back(i);

                return scc_res;
            }

            std::vector<int> get_id_list(){
                return ids;
            }
        private:
            int _n;

            struct edge{
                int t;
            };
            std::vector<std::pair<int, edge>> g_edges;

            std::vector<std::vector<int>> scc_res;
            std::vector<int> ids;
            std::vector<int> counts;

            struct Sparse_table{
                std::vector<int> start;
                std::vector<edge> elist;

                Sparse_table(int nodes, std::vector<std::pair<int, edge>>& edges) : start(nodes+1), elist(edges.size()) {
                    //Fix 0-indexed to 1-indexed to use prefix-sum for edgecount
                    for (auto e : edges) start[e.first + 1]++;
                    for (int i = 1; i <= nodes; i++) start[i] += start[i-1];

                    auto counter = start;
                    for (auto e : edges) {
                        elist[counter[e.first]] = e.second;
                        counter[e.first]++;
                    }
                }
            };
    };
}
