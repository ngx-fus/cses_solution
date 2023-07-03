#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int temp,cur;
    cin>>n;
    cin>>temp;n--;
    long long res=0;
    while (n--)
    {
        cin>>cur;
        if(cur<temp){
            res+=temp-cur,cur=temp;
            continue;
        }
        temp=cur;
    }
    cout<<res<<"\n";
 
return 0;
}