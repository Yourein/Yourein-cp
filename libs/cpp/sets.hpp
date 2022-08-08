#pragma once //include guard

//INCLUDE DEPENDINGS
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
//INCLUDE DEPENDINGS END

namespace Yourein{
    namespace sets{

        template<typename T = int>
        std::set<T> nset(std::set<T> *baseset, T rangeL = -1, T rangeR = -1){
            if (rangeL < 0) rangeL = *(baseset.begin());
            if (rangeR < 0) rangeR = *(baseset.rbegin());
            std::set<T> rset;
            for (T i = rangeL; i < rangeR; i++) if (baseset.count(i) == 0) rset.insert(i);

            return rset;
        }

        template<typename T = int>
        std::set<T> aset(std::set<T> *s1, std::set<T> *s2){
            if (s1.size() < s2.size()) swap(s1, s2);            
            std::set<T> rset;
            for (auto x : s1) if (s2.count(x) > 0) rset.insert(x);

            return rset;
        }

        template<typename T> std::vector<std::vector<T>> getsubset(std::vector<T> basevec){
            std::vector<std::vector<T>> rv;

            int vs = basevec.size();
            
            for (int setcounter = 0; setcounter < 1<<vs; setcounter++){
                std::vector<T> rvece;

                for (int elements = 0; elements < vs; elements++){
                    if (setcounter & (1<<elements)){
                        rvece.push_back(basevec[elements]);
                    }
                }
                rv.push_back(rvece);
            }

            return rv;
        }

        template<typename T> std::vector<std::vector<T>> getsubset(std::string basevec){
            std::vector<std::vector<T>> rv;

            int vs = basevec.size();
            
            for (int setcounter = 0; setcounter < 1<<vs; setcounter++){
                std::vector<T> rvece;

                for (int elements = 0; elements < vs; elements++){
                    if (setcounter & (1<<elements)){
                        rvece.push_back(basevec[elements]);
                    }
                }
                rv.push_back(rvece);
            }

            return rv;
        }
    }
}