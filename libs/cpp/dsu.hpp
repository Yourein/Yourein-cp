#pragma once //Include Gurad

//INCLUDE DEPENDECIES
#include <vector>
//INCLUDE DEPENDECIES

namespace Yourein{
    class dsu{
      private:
        long long node;
        std::vector<long long> parent_or_size;
      public:
        explicit dsu(long long n) : node(n), parent_or_size(node, -1){}

        long long leader(long long x){
            check_range(x);
            if (parent_or_size[x] < 0) return x;
            return parent_or_size[x] = leader(parent_or_size[x]);
        }

        bool is_united(long long x, long long y){
            check_range(x, y);
            return leader(x)==leader(y);
        }
        
        void unite(long long x, long long y){
            check_range(x, y);
            x = leader(x);
            y = leader(y);
            //If x and y already in same union, do nothing.
            if (x == y) return;

            //Swap X and Y if size of x is more greater than y            
            if (-parent_or_size[x] > -parent_or_size[y]) swap(x, y);

            //Unite size, set leader of y = x;
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
        }//unite

        long long union_size(long long x){
            check_range(x);
            return -parent_or_size[leader(x)];
        }

        //Returns a list of leaders. Its size equal to number of disjoint-set
        std::vector<long long> groups(){
            std::vector<long long> leaders;
            for (long long i = 0; i < node; i++) if (parent_or_size[i] < 0) leaders.push_back(i);
            return leaders;
        }
      private:
        void check_range(long long x){
            if (x < 0 || x > node){throw std::invalid_argument("Node selecter out of bounds");}
        }

        void check_range(long long x, long long y){
            if (x < 0 || x > node){throw std::invalid_argument("Node selecter out of bounds : x");}
            if (y < 0 || y > node){throw std::invalid_argument("Node selecter out of bounds : y");}
        }
    }; //dsu
}
