#include<bits/stdc++.h>
using namespace std;
#define cmd(i) cout << (i) << "\n";
#define even 1
#define odd 0
 
int main(){
    int64_t n; 
    cin>>n;
    cout<<n<<' ';
    while(n!=1){
        if (n%2==0)
            n/=2;
        else
            n=n*3+1;
        cout<<n<<' '; 
    }
return 0;
}