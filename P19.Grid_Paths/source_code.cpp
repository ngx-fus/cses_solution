#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

int A[9][9] = {
                            {-1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1}, // <- row = 0
                            {-1,  0,   0,   0,    0,   0,   0,    0,  -1},
                            {-1,  0,   0,   0,    0,   0,   0,    0,  -1},
                            {-1,  0,   0,   0,    0,   0,   0,    0,  -1},
                            {-1,  0,   0,   0,    0,   0,   0,    0,  -1},
                            {-1,  0,   0,   0,    0,   0,   0,    0,  -1},
                            {-1,  0,   0,   0,    0,   0,   0,    0,  -1},
                            {-1,  0,   0,   0,    0,   0,   0,    0,  -1},
                            {-1, -1, -1,  -1,  -1,  -1,  -1,  -1,  -1} // <- row = 8
                           //^                                              ^
                           //column = 0                              column = 8
                        };
int res = 0;
string S;
int D[49]; // 1: right - 2: up - 3: left - 4: down

#define mark(x,y) A[x][y] = step+1
#define unmark(x,y) A[x][y] = 0
void show(){
    rep(i,0,8){
        rep(j,0,8){
            cout <<A[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

bool try_(int x = 1, int y = 1, int step = 0){
    if( A[x][y] != 0 ) return false;
    if( x==7 && y== 1 )
        if( step == 48)
            return ++res;
        else 
            return false;
    mark(x,y);
    show();

    //right
    if(S[step]=='?' || D[step]=='R'){
        if( A[x][y+1] == 0) 
            try_(x, y+1, step+1);
        else{
            if( (A[x][y]-A[x][y+1]>1) && (!A[x-1][y]) && (!A[x+1][y]) )
                goto end_the_path;
        }
    }
    //left
    if(S[step]=='?' || D[step]=='L'){
        if( A[x][y-1] == 0) 
            try_(x,y-1,step+1);
        else{
            if( A[x][y]-A[x][y-1]>1 && !A[x-1][y] && !A[x+1][y] ) 
                goto end_the_path;
        }
    }
    //up
    if(S[step]=='?' || D[step]=='U'){
        if( !A[x-1][y] ) 
            try_(x-1,y,step+1);
        else
            if( A[x-1][y]-A[x][y]>1 && !A[x][y-1] && !A[x][y+1])
                goto end_the_path;
    }
    //down
    if( S[step]=='?' || D[step]=='D'){
        if( !A[x+1][y] ){
            try_(x+1, y, step+1);
        }else{
            if( A[x+1][y]-A[x][y]>1 && !A[x][y+1] && !A[x][y-1] ){
                goto end_the_path;
            }
        }
    }
    end_the_path:
    unmark(x,y);
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(  "input", "r", stdin);
    //freopen(  "output", "w", stdout);
    cin >> S;
    try_();
    cout << res << '\n';
    return 0;
}