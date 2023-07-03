#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------
#define FOR(a,b,c) for(int a=b; a<=c; a++)
#define FOR_(a,b,c) for(int a=b; a>=c; a--)
#define get cin>>
#define donot_sync ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
//-----------------------------------------------
int const a=1,b=2,c=3;
inline void move_(int const & count_, int const & from, int const & aux, int const & to){//2: 1-3-2
    if(count_==1){
        //cout<<count_<<": ";
        cout<<from<<" "<<to<<"\n";
    }else{
        move_(count_-1,from,to,aux);
        //cout<<count_<<": ";
        cout<<from<<" "<<to<<"\n";
        move_(count_-1,aux,from,to);
 
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    donot_sync;
    int n=1000000; get n;
    cout<<(1<<(n))-1<<'\n';
    move_(n,a,b,c);
return 0;
}