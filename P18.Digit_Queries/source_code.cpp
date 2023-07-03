#include<bits/stdc++.h>
#define int unsigned long long int
 
using namespace std;
//index of smallest number with n digits
int b[22] = {0, 1},
   bnum[22] = {0, 1};
 
int _1E(int n, int ans = 1){
    while (n-->0) ans*=10;
    return ans;
}
 
char process_(int q){
    int n = 1; //digits of number
    while( b[n+1] <= q) n++; //find n
    return to_string(bnum[n]+(q-b[n])/n).at(((q-b[n]))%n);
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    for(int n = 2; n < 19; n++){
        b[n] = b[n-1] + 9*_1E(n-2)*(n-1);
        bnum[n] = _1E(n-1);
    }
    int to, q; cin >> to;
    while(to-- && cin >> q) 
        cout << process_(q) << endl;
return 0;
