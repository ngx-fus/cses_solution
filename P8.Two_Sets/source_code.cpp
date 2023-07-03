#include <bits/stdc++.h>
#define int long long
using namespace std;
 
bool check(int const n, int &total){
    total=(n*(n+1)/2LL);
    if(total%2LL==0)return true;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=7;
    int total=0;
    vector<int> s1,s2;
    cin>>n;
    if(check(n,total)){
        total/=2LL;
        cout<<"YES\n";
        while(n){
            if(total-n>=0){
                s1.push_back(n);
                total-=n;
            }else{
                s2.push_back(n);
            }
            n--;
        }
        cout<<s1.size()<<"\n";
        for(auto &p:s1)cout<<p<<" ";
        cout<<endl;
        cout<<s2.size()<<"\n";
        for(auto &p:s2)cout<<p<<" ";
        cout<<endl;
    }else{
        cout<<"NO\n";
    }
}