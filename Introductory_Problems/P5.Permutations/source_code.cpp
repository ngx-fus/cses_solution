#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOR_(i,a,b) for(int i=a;i>=b;i--)
inline void print(int t){
    while(t>0){
        cout<<t<<" ";
        t-=2;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int n=4;cin>>n;
    if(n<4 && n>1) {
        cout<<"NO SOLUTION\n";
        return 0;
    }
    int t=n;  
    if(t%2) print(t);else print(t-1);//
    if(t%2) print(t-1);else print(t);//
return 0;
}