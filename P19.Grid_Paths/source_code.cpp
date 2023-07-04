#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

int A[11][11] = {
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

#define mark(x,y) A[x][y] = step+1
#define unmark(x,y) A[x][y] = 0


bool try_(int x = 1, int y = 1, int step = 0){
    if( A[x][y] != 0 ) return false;
    if( x==7 && y== 1 ){
        if( step == 48)
            return ++res;
        else 
            return false;
    }
    mark(x,y);
    /*  0  #
    #--@ -#
       0  #      #:wall
    */
    if( A[x][y+1] && A[x][y-1] && !A[x+1][y] && !A[x-1][y]) goto end_the_path;
    /* #         @: you
    0 @ 0       0: can move
    # # #      #: wall
    */
    if( A[x-1][y] && A[x+1][y] && !A[x][y+1] && !A[x][y-1]) goto end_the_path;
    //move right
    if( !A[x][y+1] && (S[step]=='?' || S[step]=='R') ) try_(x, y+1, step+1);
    //move left
    if( !A[x][y-1] && (S[step]=='?' || S[step]=='L') ) try_(x, y-1, step+1);
    //move up
    if( !A[x-1][y] && (S[step]=='?' || S[step]=='U') ) try_(x-1, y, step+1);
    //move down
    if( !A[x+1][y] && (S[step]=='?' || S[step]=='D') ) try_(x+1, y, step+1);

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