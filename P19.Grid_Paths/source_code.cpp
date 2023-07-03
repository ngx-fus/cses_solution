/*
x 0 1 2 3 4 y
0 *
1
2
3
4
x
*/
 
#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define rep(i, begin, end) for( int i = (begin); i <= (end); i++)
#define rev(i, begin, end) for( int i = (begin); i >= (end); i--)
typedef std::vector< int > vi;
typedef std::pair< int, int > ii;
 
struct point{
    int x, y;
    point(int x=0, int y = 0){this->x=x;this->y=y;} 
    point operator + (point const o){return {x+o.x, y+o.y};}
    bool operator == (point const o){return bool((x==o.x)&&(y==o.y));}
};
 
string direction;
int a[11][11], res = 0;
 
int const Y_MIN = 1, Y_MAX = 7, X_MIN = 1, X_MAX = 7;
#define a(p) a[(p).x][(p).y]
#define can_move_right a(curPoint+point(0,1)) == 0 && curPoint.y < Y_MAX
#define can_move_left a(curPoint+point(0,-1)) == 0 && curPoint.y > Y_MIN
#define can_move_up a(curPoint+point(-1,0)) == 0 && curPoint.x > X_MIN
#define can_move_down a(curPoint+point(1,0)) == 0 && curPoint.x < X_MAX
#define in_the_wall bool(curPoint.x == X_MIN || curPoint.x == X_MAX || curPoint.y == Y_MIN || curPoint.y == Y_MAX)
#define mark(p) a[(p).x][(p).y] = step+1
#define unmark(p) a[(p).x][(p).y] = false
 
void show(){
    //system("cls");
    rep(i,1,7){
        rep(j,1,7){
            cout << a[i][j] << "\t"; 
        }
        cout << endl;
    }
    cout << '\n';
}
 
bool visit(point curPoint = {1,1}, int step = 0){
    mark(curPoint);
    show();
    //success in visiting to point(7,1)
    if( curPoint == point(7,1)) {
        unmark(curPoint);
        if(step == 48) {res ++;  return true;}
        else                    return false;
    }
    //Optimization
    /*If the path touches a wall and can turn either left or right, the grid 
    splits into two parts that contain unvisited squares. In this case, we cannot 
    visit all squares anymore, so we can terminate the search.*/
    if( (!can_move_down && a(curPoint+point(1,0))-a(curPoint) != 1) && can_move_left && can_move_right) goto end_the_path;
    if( (!can_move_right || !can_move_left) && can_move_up && can_move_down) goto end_the_path;
    //
    if( (direction[step] == 'R' || direction[step] == '?') && can_move_right ) 
        visit(curPoint + point(0, 1), step+1);
    if( (direction[step] == 'L' || direction[step] == '?') && can_move_left ) 
        visit(curPoint + point(0,-1), step+1);
    if( (direction[step] == 'U' || direction[step] == '?') &&  can_move_up ) 
        visit(curPoint+point(-1,0), step+1);
    if( (direction[step] == 'D' || direction[step] == '?') &&  can_move_down )
        visit(curPoint+point(1, 0), step+1);
    end_the_path:
    unmark(curPoint);
    return false;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(  "input", "r", stdin);
    freopen(  "output", "w", stdout);
    cin >> direction;
    visit();
    cout << res << endl;
return 0;
}