#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOR_(i,a,b) for(int i=a;i>=b;i--)
 
void res_(unsigned long long const &n){
    if(n==1){cout<<0<<"\n"; return;}
    unsigned long long double_res=(n*n)*(n*n-1)-4*2;//trừ đi 2 vị trí ở 4 gốc
    if(n==2) double_res+=4*2;
    if(n==3) double_res-=(4*2) ; 
    //nếu bàn cờ 3*3 thì bỏ đi 4 vị trí tương tự vị trí đặt knight_1 ở (2-2) sẽ chỉ có 2 vị trí attack knight_2
    if(n>3) double_res+= ( 
                            -(4*2)*3//đặt ở (1-2) và (2-1) và có 4 gốc
                            -4*(n-4)*4 //có n-4 cách đặt knight_1 (từ ô(1,1+2)->ô(1,n-2) ) sẽ có 4 vị trí attack knight_2 nhân với 4
                            -4*4 //có 4 vị trí đặt knight_1 giống ô(2,2)
                            -4*(n-4)*6 //có n-4 cách đặt knight_1 (từ ô(2,1+2)->ô(2,n-2) )sẽ có 6 vị trí attack knight_2 nhân với 4
                            -(n-4)*(n-4)*8 //lập phương (n-2)(n-2) bên trong cùng có sẽ mấy 8 vị trí mà knight_2 attack
                         );
    cout<<double_res/2<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k;cin>>k;
    for(unsigned long long n=1; n<=k; n++) {
        res_(n);
    }
return 0;
}