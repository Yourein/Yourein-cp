#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <cassert>
#include <climits>
#include <limits>

#if __has_include(<boost/range/combine.hpp>)
#include <boost/range/combine.hpp> //Zip function for C++
#endif

#if __has_include(<boost/multiprecision/cpp_int.hpp>)
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using pyint = boost::multiprecision::cpp_int;
using i128 = boost::multiprecision::int128_t;
using i256 = boost::multiprecision::int256_t;
using i512 = boost::multiprecision::int512_t;
using i1024 = boost::multiprecision::int1024_t;
using f50 = boost::multiprecision::cpp_dec_float_50;
using f100 = boost::multiprecision::cpp_dec_float_100;
#endif

//Binary Indexed Tree
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
//Binary Indexed Tree

using i32 = int32_t;
using i64 = int64_t;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

//iostream operator
template <typename T> istream &operator>>(istream &is, vector<T> &x){for (auto &y:x){is >> y;} return is;}
template <typename T> ostream &operator<<(ostream &os, vector<T> &x){for (size_t e = 0; e < x.size(); e++){os << x[e] << (e==x.size()-1?"":" ");} return os;}
template <class T, class S> istream &operator>>(istream &is, pair<T, S> &x){is >> x.first >> x.second; return is;}
template <class T, class S> ostream &operator<<(ostream &os, pair<T, S> &x){os << x.first << " " << x.second; return os;}
//iostream operator

namespace cpio{
    //Debug out
    void dout(){cerr << "\n";}
    template<typename T, typename... Ts> void dout(const T& a, const Ts&... b){cerr << a; (cerr << ... << (cerr << ' ', b)); cerr << "\n";}

    //Yes or No
    void yon(bool yorn, string Y = "Yes", string N = "No"){cout << (yorn?Y:N) << endl;}
}; using namespace cpio;

namespace cpmath{
    //Math library for Competitive-Programming
    constexpr ll mod97 = 1000000007;
    constexpr ll mod99 = 1000000009;
    constexpr ll mod89 = 998244353;
    constexpr double pi = acos(-1);

    const int imax = numeric_limits<int>::max();
    const long long llmax = numeric_limits<long long>::max();

    constexpr int DX4[4] = {1, 0, -1, 0};
    constexpr int DY4[4] = {0, 1, 0, -1};
    constexpr int DX8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    constexpr int DY8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    //Return a!/(b-1)! = a*(a-1)*...*(b+1)*b, O(a)
    ll factorial(ll a, ll b = -1, const ll fmod = -1){
        ll ans = 1;
        if (fmod > 1) {
            if (b == -1) for (ll i = a; i > 1; i--) ans = ((ans%fmod)*(i%fmod))%fmod;
            else for (ll i = a; i >= b; i--) ans = ((ans%fmod)*(i%fmod))%fmod;
        }
        else{
            if (b == -1) for (ll i = a; i > 1; i--) ans = ans*i;
            else for(ll i = a; i >= b; i--) ans = ans*i;
        }
        return ans;
    }

    //Return m^p, O(log p)
    ll fastpow(ll m, ll p){
        if (p == 0) return 1;
        if (p%2 == 0){ll t = fastpow(m, p/2); return t*t;}
        return m*fastpow(m, p-1);
    }

    ll modpow(ll m, ll p, const ll fmod){
        if (p == 0) return 1;
        if (p%2 == 0){ll t = modpow(m, p/2, fmod); return (t*t)%fmod;}
        return (m*modpow(m, p-1, fmod))%fmod;
    }

    ld dtor(const ld deg){return deg*(pi/(ld)180);}

    template<class T> double fmedian(vector<T> a){return (static_cast<double>(a[((int(a.size())+1)/2)-1])+static_cast<double>(a[(int(a.size())/2)]))/2;}
    template<class T> pair<long long, long long> imedian(vector<T> a) {
        return {
            (static_cast<long long>(a[((int(a.size())+1)/2)-1])+static_cast<long long>(a[(int(a.size())/2)]))/2LL,
            (static_cast<long long>(a[((int(a.size())+1)/2)-1])+static_cast<long long>(a[(int(a.size())/2)])+1)/2LL,
        };
    }
    
    long long inversed(ll n, const ll mod){return cpmath::modpow(n, mod-2, mod);}
}

using cpmath::mod89;
using cpmath::mod97;
using cpmath::mod99;
using cpmath::imax;
using cpmath::llmax;

using cpmath::DX4;
using cpmath::DY4;
//using cpmath::DX8;
//using cpmath::DY8;

// using gtree = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    
}
