#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOR_(i,a,b) for(int i=a;i>=b;i--)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int64_t t,x,y;cin>>t;
    while (t--)
    {
        cin>>x>>y;
        int64_t mid=max(x,y);
        int64_t avr=1+(mid-1)*mid;
        if(mid%2) cout<<avr+(y-x)<<"\n";
                else cout<<avr+(x-y)<<"\n";
    }
 
return 0;
}