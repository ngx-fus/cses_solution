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
    ll n;   get n;
    ll res=0,temp=5;
    while (temp<=n)
    {
        res+=n/temp;
        temp*=5;
    }
    cout<<res<<"\n";
return 0;
}
