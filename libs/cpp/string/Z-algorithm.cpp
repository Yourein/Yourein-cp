#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Yourein{
    vector<int> z_algorithm(string s){
        vector<int> res(s.length(), 0);
        res[0] = (int)s.length();
        
        for (int i = 1, l = 0, r = 0; i < (int)s.length(); i++) {
            if (res[i-l] < r-i) {
                res[i] = res[i-l];
            }
            else {
                r = max(r, i);
                while (r < (int)s.length() && s[r] == s[r-i]) r++;
                res[i] = r-i;
                l = i;
            }
        }

        return res;
    }
}
