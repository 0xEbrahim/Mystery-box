#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
#include <utility>
#include <string>
#define ld long double
#define int64 long long
#define all(v) ((v).begin()), ((v).end())
//#define sz(v) ((int)(v).size())
#define ON(n , k) ((n) | (1<<k))
#define vll vector<long long>
#define uint unsigned long long
#define pb push_back
#define OFF(n , k) ((n) & ~(1<<k))
#define isON(n , k) (((n)>>(k))&1)
#define FLIP(n , k) ((n)^(1<<k))
#define EPS (-1e18)
#define INF (1e18)
#define output(v) for(auto&it:v){cout<<it<<" ";}cout<<"\n"
#define input(v) for(auto&it:v){cin>>it;}
#define ll long long
#define clr(x, val) memset((x), (val), sizeof(x))
#define ull unsigned long long
#define endl '\n'
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(), (a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(), (a).real()))
#define normalize(a) (a)/length(a)
#define dot(a,b) ((conj(a) * (b)).real())
#define cros(a,b) ((conj(a) * (b)).imag())
#define same(p1,p2) (dot(vec(p1,p2),vec(p1,p2)) < EPS)
#define gmx(x, y) x = max(x, y)
#define gmn(x, y) x = min(x, y)
const double PI = 3.14159;
 
using namespace std;
 
//------------------------ TEMPLATES ---------------------------------------
 
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
 
// ---------------------------------------------------------
// ----------------------- policy based data structures --------------------------------------------------------------------
 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define ordered_set tree< int , null_type, greater_equal<>, rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_set1 tree< int , null_type, greater<>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
//#define findd find_by_order
//#define orderr order_of_key
//using namespace __gnu_pbds;
//typedef tree<int, null_type,less_equal<>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//void myerase(ordered_set &t, int v){
//    int rank = t.order_of_key(v);                      //Number of elements that are less than v in t
//    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
//    t.erase(it);
//}
 
//----------------------------------------------------------------------------
 
 
 
 
 
void NARUTO_UZUMAKI(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void UCHIHA_SASUKI(void) {
#ifndef ONLINE_JUDGE
    freopen("D:\\Personal\\No\\CP\\input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
 
#endif
}
int mod = 1000000007;
 
 
 
 
 
/*
  When I wrote this, only Allah and I understood what I was doing
  Now, only Allah knows
*/
 
 
void preCalc() {
 
}
int n ;
vector<vector<int>>dp;
vector<vector<int>>grid;
bool valid(int i , int j){
    return i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0;
}
int go(int i , int j){
    if(!valid(i , j))
        return 0;
    if(i == n - 1 && j == n - 1)
        return 1;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    ret = 0;
    ret += go(i + 1, j) % mod;
    ret += go(i , j + 1) % mod;
    return ret % mod;
}
void Still_Up() {
    cin >> n ;
    dp.resize(n + 1, vector<int>(n + 1, -1));
    grid.resize(n + 1 , vector<int>(n + 1));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)
        {
            char x;
            cin >> x;
            grid[i][j] = (x == '.' ? 0 : 1);
        }
    }
    cout << go(0,0)<<endl;
}
 
signed main()
{
    NARUTO_UZUMAKI();
    UCHIHA_SASUKI();
    preCalc();
    // freopen("input.txt", "r", stdin);
    ////freopen("output.txt", "w", stdout);
    int t = 1 ;
    //cin >> t;
    while(t--) {
        Still_Up();
        //if(t > 0){ cout << endl; }
    }
 
//   for(int i = 1 ; i <= t ; i++){
//       cout << "Case "<< i<<": ";
//       Still_Up();
//   }
 
}
