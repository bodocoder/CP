#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,n) for(ll i=0;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)
#define range(i,a,n) for(ll i=a;i<n;i++)
#define vll vector<ll>
const int mod = 1e9+7;

class SegmentTree{
    ll size;
    vll st;
    ll func(ll x, ll y){
        if(x == 0) return y;
        return func(y % x, x);
    }
  public  :
    void build(ll x,vll &arr){
        size = x;
        st.assign(4*x,0);
        f(i,size) update(i,arr[i],0,0,size-1);
    }
    void update(ll ind,ll value,ll si,ll ss,ll se){
        if(ind > se || ind < ss) return;
        if(ss == se) st[si] = value;
        else{
            ll mid = (ss+se)/2;
            update(ind,value,2*si+1,ss,mid);
            update(ind,value,2*si+2,mid+1,se);
            st[si] = func(st[2*si+1],st[2*si+2]);
        }
    }
    ll query(ll qs,ll qe,ll si,ll ss,ll se){
        if(qs > se || qe < ss) return 0;
        if(ss >=qs && se <= qe) return st[si];
        ll mid = (ss+se)/2;
        return func(query(qs,qe,2*si+1,ss,mid),query(qs,qe,2*si+2,mid+1,se));
    }
    ll get(ll l,ll r){
        return query(l, r,0,0,size-1);
    }
};

class SparseTable{
    ll size;
    vector<vll> table;
    ll func(ll x, ll y){
        if(x == 0) return y;
        return func(y % x, x);
    }
    public:
    void build(ll x,vll &arr){
        size = x;
        ll m = 1+log2(x);
        table.assign(x,vll(m,0));
        range(pow,0,m){
            ll l = 1 << pow;
            f(i,size-l+1){
                if(l == 1) table[i][pow] = arr[i];
                else table[i][pow] = func(table[i][pow-1],table[i+l/2][pow-1]);
            }
        }
    }
    ll get(ll l, ll r){
        ll range = r - l + 1;
        ll m = log2(range);
        return func(table[l][m],table[r-(1<<m)+1][m]);
    }
};
