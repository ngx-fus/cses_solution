#include <iostream>
using namespace std;
 string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int res=1;
    int temp=1;
    for(int i=0; i<=s.length();i++){
        if(s[i]==s[i-1])temp++;else{
            res=max(res,temp);
            temp=1;
        }
    }
    cout<<res<<'\n';
    return 0;
}