#include <vector>

using namespace std;
using ll = long long;

struct Edge{
    int to;
    ll weight;

    Edge(int t, ll w) : to(t), weight(w) {}
};

class EulerTour{
  private:
    int cnt = 0;
    int dep = 0;

    void calc(int now, const vector<vector<Edge>> &g, ll dist){
        this->et.push_back({this->dep, now});
        this->fa[now] = this->cnt;
        this->dist[now] = dist;

        for (auto x : g[now]){
            if (this->fa[x.to] != -1) continue;

            this->cnt++;
            this->dep++;
            dist += x.weight;
            
            calc(x.to, g, dist);
            
            dist -= x.weight;
            this->cnt++;
            this->dep--;
            this->et.push_back({this->dep, now});
        }
    }
   
  public:
    vector<pair<int, int>> et;
    vector<int> fa;
    vector<ll> dist;

    EulerTour(int b, const vector<vector<Edge>> &g) : fa((int)g.size(), -1), dist((int)g.size(), 0LL){
        calc(b, g, 0);
    }
};
