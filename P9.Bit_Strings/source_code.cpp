#include <bits/stdc++.h>
using namespace std;
#define FOR(a,b,c) for(int a=b; a<=c; a++)
#define FOR_(a,b,c) for(int a=b; a>=c; a--)
 
#define mod int64_t(1e9+7)
int64_t pow_2_[int( 1e6+2) ];
inline void creat_pow_2_(int n, int64_t pow_2_[int( 1e6+1) ]){
    pow_2_[0]=1;
    FOR(i,1,n){
        pow_2_[i]=( (pow_2_[i-1]%mod) * 2 )%mod;
        //cout<<"2^"<<i<<" = "<<pow_2_[i]<<"\n";
    }
}
 
int main(){
// file---------- --------------------------
    //freopen("in.txt", "r", stdin); 
    //freopen("out.txt", "w", stdout); 
// faster ----------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(0);
// input -----------------------------------
    int n;cin>>n;
// Solve -----------------------------------
    int64_t res=0;
    creat_pow_2_(n,pow_2_);
    FOR(i,0,n-1){
        res=( res + pow_2_[i] )%mod ;
    }
    cout<<res+1<<"\n";
return 0;
}