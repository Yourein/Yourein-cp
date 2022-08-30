#pragma once

#include <vector>

template<class T, int maxN = 1>
class Comb {
    std::vector<std::vector<T>> comb;
public:
    Comb() : comb(maxN+1, std::vector<T>(maxN+1, 0)){
        for (int i = 0; i <= maxN; i++) for (int j = 0; j <= i; j++){
            if (j == 0 || j == i) comb[i][j] = 1;
            else comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
        }
    }

    T operator()(int n, int r){return comb[n][r];}
};
