//https://www.spoj.com/problems/MPOW/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,n) for(ll i=a;i<n;i++)
#define w(_t) ll _t;cin>>_t;while(_t--)
ll md=1000000007;
ll m,n;
struct M{
  ll arr[51][51];
    M(){
        f(i,0,51) f(j,0,51) arr[i][j]=0;
        f(i,0,51) arr[i][i]=1;
    }
    
};
M* mul(M *a,M *b){
        M *tmp=new M();
        f(i,0,m){
           f(j,0,m){
               tmp->arr[i][j]=0;
               f(k,0,m){
                   tmp->arr[i][j]+=(a->arr[i][k]*b->arr[k][j])%md;
                   tmp->arr[i][j]%=md;
               }
           } 
        }
        return tmp;
}
M *pow(M *a,ll n){
    if(n==0) return new M();
    if(n==1) return a;
    if(n%2==0) return pow(mul(a,a),n/2);
    else return mul(a,pow(mul(a,a),n/2));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    w(x){
        cin>>m>>n;
        M *mat=new M();
        f(i,0,m) f(j,0,m) cin>>mat->arr[i][j];
        M *ans=pow(mat,n);
        f(i,0,m){
            f(j,0,m) cout<<ans->arr[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
