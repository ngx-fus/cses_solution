#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define SZ(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, x) for (auto &a : (x))
//#define DEBUG(x) cerr << '<' << #x << ": " << x << '\n'
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int, int> PII;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void upgrade() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); }
// head: credit MiFaFaOvO
 
string input;
map<pair<int, ll>, ll> dp;
int ans=0;
 
bool check(int x, int y, ll bits){
    int pos = y*7+x;
    if (pos == 42) return false;
    int suc0 = x > 0 && (bits & (1ll << (pos - 1)))==0;
    int suc1 = y > 0 && (bits & (1ll << (pos - 7)))==0;
    int suc2 = x < 6 && (bits & (1ll << (pos + 1)))==0;
    int suc3 = y < 6 && (bits & (1ll << (pos + 7)))==0;
    bool ret = suc0 + suc1 + suc2 + suc3 <= 1;
    return ret;
}
 
ll recur(int x, int y, ll bits)
{
    int pos = y*7+x;
    if ((bits & (1ll << pos)) > 0)
    {
        return 0;
    }
    int ind = __builtin_popcountll(bits);
    if (pos == 42){
        if (ind == 48) return 1;
        return 0;
    }
    int suc0 = x > 0 && (bits & (1ll << (pos - 1)))==0;
    int suc1 = y > 0 && (bits & (1ll << (pos - 7)))==0;
    int suc2 = x < 6 && (bits & (1ll << (pos + 1)))==0;
    int suc3 = y < 6 && (bits & (1ll << (pos + 7)))==0;
    if (suc0 && suc2 && !suc1 && !suc3){
        return 0;
    }
    if (suc1 && suc3 && !suc0 && !suc2){
        return 0;
    }
    auto it = dp.find(mp(pos, bits));
    if (it != dp.end())
    {
        return it->se;
    }
    bits ^= 1ll << pos;
    char c = input[ind];
    ll ans=0;
    if (suc0 && check(x-1,y, bits))
    {
        if (c == 'L' || c == '?')
            ans += recur(x-1,y, bits);
    }
    else if (suc2 && check(x+1,y, bits))
    {
        if (c == 'R' || c == '?')
            ans += recur(x+1,y, bits);
    }
    else if (suc1 && check(x,y-1, bits))
    {
        if (c == 'U' || c == '?')
            ans += recur(x,y-1, bits);
    }
    else if (suc3 && check(x,y+1, bits))
    {
        if (c == 'D' || c == '?')
            ans += recur(x,y+1, bits);
    }
    else {
        if (x > 0 && (c == 'L' || c == '?')&& (bits & (1ll << (pos-1))) == 0)
        {
            ans += recur(x-1,y, bits);
        }
        if (x < 6 && (c == 'R' || c == '?')&& (bits & (1ll << (pos+1))) == 0)
        {
            ans += recur(x+1,y, bits);
        }
        if (y > 0 && (c == 'U' || c == '?')&& (bits & (1ll << (pos-7))) == 0)
        {
            ans += recur(x, y-1, bits);
        }
        if (y < 6 && (c == 'D' || c == '?')&& (bits & (1ll << (pos+7))) == 0)
        {
            ans += recur(x, y+1, bits);
        }
    }
    bits ^= 1ll << pos;
 
    return dp[mp(pos, bits)] = ans;
}
 
int main()
{
    upgrade();
    cin >> input;
    ans = recur(0,0,0);
    cout<<ans<<nl;
}