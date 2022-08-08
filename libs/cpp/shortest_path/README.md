# Shortest Path

## Dijkstra

ある頂点$\hspace{0.2em} s \hspace{0.2em}$から他の全頂点に対して、最短距離配列と最短パスの最後の辺情報を返します。

```cpp
std::pair<std::vector<long long>, std::vector<long long>> dijkstra(const std::vector<std::vector<Yourein::edge>> &g, int start)
```

この関数は隣接リスト表現で表現されたグラフを受け取ります。

## Warshall-Floyd

任意の頂点から任意の頂点への最短距離を求めます。また、ある頂点からある頂点への最短パスの最後のパス番号をそれぞれ行列として返します。

```cpp
std::pair<std::vector<std::vector<long long>>, std::vector<std::vector<long long>>> warshall_floyd(cosnt std::vector<std::vector<long long>> &g)
```

この関数は隣接行列表現で表現されたグラフを受け取ります。