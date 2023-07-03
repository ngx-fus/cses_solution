#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------
#define FOR(a,b,c) for(int a=b; a<=c; a++)
#define FOR_(a,b,c) for(int a=b; a>=c; a--)
#define get cin>>
#define donot_sync ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
//-----------------------------------------------
int main(){
    //freopen("in.txt", "r", stdin); 
    //freopen("out.txt", "w", stdout); 
    donot_sync;
    int t;  get t;
    ll L,R,m,n;   
    while (t--)
    {
        get L; get R;
        //cout<<L<<" "<<R<<"\t :\t";
        if((2*L-R)%3==0 && (2*L-R)/3 >= 0 && L-2*((2*L-R)/3)>=0){
            //n=(2*L-R)/3;
            cout<<"YES\n";
            //cout<<"SOL: n="<<(2*L-R)/3<<" m="<<L-2*((2*L-R)/3)<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    
return 0;
}