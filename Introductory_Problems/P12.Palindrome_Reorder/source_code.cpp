#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------
#define FOR(a,b,c) for(int a=b; a<=c; a++)
#define FOR_(a,b,c) for(int a=b; a>=c; a--)
#define get cin>>
#define donot_sync ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
//-----------------------------------------------
    int f[27];//'A'=65 'Z'=90 - 26 characters
inline void dequy(int const i,int const & fi, int &mid, string &res){
    if(fi!=0){
        if(fi%2 != 0 ){
            if(mid != 0){
                cout<<"NO SOLUTION\n";
                exit(0);
            }else{
                mid=i;
            }
        }
        FOR(t,1,int(fi/2)) res.push_back(char(i+64));
        if(i+1<=26) {
            dequy(i+1,f[i+1],mid,res);
        }else{
            if(mid!=0)res.push_back(char(mid+64));
        }
        FOR(t,1,int(fi/2)) res.push_back(char(i+64));
    }else{
        if(i+1<=26) {
            dequy(i+1,f[i+1],mid,res);
        }else{
            if(mid!=0)res.push_back(char(mid+64));
        }
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    donot_sync;
    string source,res=""; get source;
    int mid=0;
    for(auto const &char_:source){
        int i=int(char_)-64;
        f[i]++;
    }
    int i=1,fi=f[i];
    dequy(i,fi,mid,res);
    cout<<res<<"\n";
return 0;
}