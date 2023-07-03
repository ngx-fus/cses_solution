#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
//mark a cell in the chessboard 
#define mark_(line, col) can_be_attacked[line][col]++;
//unmark a cell
#define unmark_(line, col) can_be_attacked[line][col]--;
 
using namespace std;
 
int chessboard[16][16],
    can_be_attacked[16][16],
    queens, res;
 
//scan chessboard from input
void scan_chessboard(){
    char tmp;
    FOR(line, 1, 8){
        FOR(col, 1, 8){
            cin >> tmp;
            chessboard[line][col] = (tmp=='*')?(-1):(0);
        }
    }
}
//place a queen
void place_a_queen(int line, int col){
    if(can_be_attacked[line][col] || chessboard[line][col] != 0) return;
    chessboard[line][col] = ++queens;
    //mark line and col
    FOR(x, 1, 8) { mark_(x, col); mark_(line, x);}
    //auxiliary diagonal
    int LINE = 1, COL = line+col-1;
    while( LINE < 9 && COL > 0) mark_(LINE++, COL--);
    //main diagonal
        LINE = line - min(line,col) + 1,
        COL  = col  - min(line,col) + 1;
    while( LINE < 9 && COL < 9) mark_(LINE++, COL++);
}
//remove a queen
void remove_a_queen(int line, int col){
    if(chessboard[line][col] == -1) return;
    chessboard[line][col] = 0, queens--;
    //mark line and col
    FOR(x, 1, 8) { unmark_(x, col); unmark_(line, x);}
    //auxiliary diagonal
    int LINE = 1, COL = line+col-1;
    while( LINE < 9 && COL > 0) unmark_(LINE++, COL--);
    //main diagonal
        LINE = line - min(line,col) + 1,
        COL  = col  - min(line,col) + 1;
    while( LINE < 9 && COL < 9) unmark_(LINE++, COL++);
}
//processing
void processing(int line = 1){
    FOR(col, 1, 8){
        if( chessboard[line][col] != 0 || can_be_attacked[line][col] > 0 ) continue;
        if(queens == 7) {res++; continue;}
        place_a_queen(line, col);                              
        processing(line+1);
        remove_a_queen(line, col);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scan_chessboard();
    processing();
    cout << res << "\n";
return 0;
}