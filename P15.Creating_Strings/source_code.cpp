#include <bits/stdc++.h>
#define FOR(vi,from,to) for(int vi=from; vi<=to; v++)
#define FOR_(vi,from,to) for(int vi=from; vi>=to; v--)
#define do_not_sync ios_base::sync_with_stdio(false); cin.tie(0);
#define get cin>>
using namespace std;
 
int main(){
    do_not_sync
    string s; get s;
    vector< string > ans;
    sort(s.begin(), s.end());ans.push_back(s);
    while(next_permutation(s.begin(), s.end())){
        ans.push_back(s);
    }
    cout<<ans.size()<<"\n";
    for(auto &p:ans) cout<<p<<"\n";
return 0;
}