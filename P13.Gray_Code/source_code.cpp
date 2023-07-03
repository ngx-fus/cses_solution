#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------
#define FOR(a,b,c) for(int a=b; a<=c; a++)
#define FOR_(a,b,c) for(int a=b; a>=c; a--)
#define get cin>>
#define donot_sync ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
//-----------------------------------------------
string to_binary(int const & lenght_of_bin,int const & num, string s=""){
    FOR_(i, lenght_of_bin-1, 0){
        s.push_back( char(48+bool(num&(1<<i))) );
    }
return s;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    donot_sync;
    int n; get n;
    FOR(num,0,(1<<n)-1){
        //cout<<"bin: "<<to_binary(n+1,num)<<"\t>\t";
        FOR_(i,n-1,0){
            cout<<bool( bool(num&(1<<i)) xor bool(num&(1<<(i+1))) );
        }
        cout<<endl;
    }
}