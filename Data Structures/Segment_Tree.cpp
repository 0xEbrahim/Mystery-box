#include <bits/stdc++.h>
#include <list>
#include <queue>
#include <unordered_set>
#include <utility>
#include <string>
#define int64 long long
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)(v).size())
#define ON(n , k) ((n) | (1<<k))
#define uint unsigned long long
#define pb push_back
#define OFF(n , k) ((n) & ~(1<<k))
#define isON(n , k) (((n)>>(k))&1)
#define FLIP(n , k) ((n)^(1<<k))
#define int long long
#define output(v) for(auto&it:v){cout<<it<<" ";}cout<<"\n"
#define input(v) for(auto&it:v){cin>>it;}
#define ll long long
#define endl '\n'

using namespace std;

//------------------------ TEMPLATES ---------------------------------------

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

// ---------------------------------------------------------


// ----------------------- policy based data structures --------------------------------------------------------------------

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define ordered_set tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define findd find_by_order
////#define orderr order_of_key
//using namespace __gnu_pbds;
//typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
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
    freopen("/home/ebrahimelsayed/Desktop/NEW/input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

#endif
}
void preCalc()
{

}

struct segmenttree{
  vector<int> st;
  int n ;
  void init(int _n ){
      this-> n = _n;
    st.resize(4 * n, 0);
  }

  void build(int start , int end , int node, vector<int>&v) {
       // leaf node
       if(start == end) {
            st[node] = v[start];
           return;
       }
      int mid = start + (end - start)/2;

       // left
      build(start , mid , 2 * node + 1 , v);

      // right
      build(mid + 1 , end , 2 * node + 2 , v);

      // assign values as you want
      st[node] = st[node * 2 + 1] + st[node * 2 + 2];
  }


    int query(int start , int end , int l , int r, int node){
      // non over_lapping
      if(start > r || end < l){
            return 0;
        }

      // complete over_lapping
      if(start >= l && end <= r){
            return st[node];
      }

      // partial over_lapping
      int mid = start + (end - start)/2;
      int q1 = query(start , mid , l , r , 2 * node + 1);
      int q2 = query(mid + 1 , end , l , r , 2 * node + 2);
        return q1 + q2 ;
  }

  void update(int start , int end , int node, int index , int value){
     if(start == end){
         st[node] = value;
         return;
     }
      int mid = start + (end - start)/2;
      if(index <= mid){
          update(start , mid , 2 * node + 1 , index , value);
      }else {
          update(mid + 1, end, 2 * node + 2, index, value);
      }
      st[node] = st[node * 2 + 1] + st[node * 2 + 2];

  }

  void build(vector<int> &v) {
      build(0, n - 1 , 0 , v);
  }

  int query(int l , int r){
      return query(0 , n - 1 , l , r , 0);
  }

  void update(int x ,int y){
    update(0 , n - 1 , 0, x , y);
  }

} ;

void HANMA_BAKI(){
vector<int> v = {1,2,3,4,5,6,7,8};
    segmenttree tree;
    tree.init(sz(v));
    tree.build(v);
   int sum =  tree.query(0,3);
    cout << sum;
}



signed main()
{
    NARUTO_UZUMAKI();
    UCHIHA_SASUKI();
    // freopen("window.in", "r", stdin);
    preCalc();
    int t = 1 ;
    //cin >> t;
    while(t--)
        HANMA_BAKI();

}
