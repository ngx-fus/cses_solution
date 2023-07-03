#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE int(2E5+4)
#define N n-1 /* N = n-1, SL phan tu mang da nhap*/
 
int n, f[MAXSIZE], num;
 
int main(){
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        cin >> num;
        f[num]++;
    }
    for(num = 1; num <= n; num++)
        if(f[num]==0) {
            cout << num << endl;
            break;
        } 
return 0;
}