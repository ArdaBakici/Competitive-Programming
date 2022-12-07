#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;

/*
Solution

f(n-1) = (2*1 - 1) * f(n-2) + 2*2 - 1 * f(n-3) + (2*3 - 1) * f(n-4)
f(n) = (2*1 - 1) * f(n-1) + (2*2 - 1) * f(n-2) + (2*3 - 1) * f(n-3) + 7 f(n-4)
f(n-1) = 2 * (f(n-2) + f(n-3) + f(n-4))
f(n) = 2 * (f(n-1) + f(n-2) + f(n-3) + f(n-4))
f(n) = 2 * f(n-1) + 2(f(n-2) + f(n-3) + ...)
f(n) = 2 * f(n-1) + f(n-1)
f(n) = 3 * f(n-1)
*/

int mod = 1000000007;
int n = 1000000;
vector<p(2)> dp(n+1, p(2)({0, 0}));

void solve(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = 2*dp[i-1][0] + dp[i-1][1];
        dp[i][0] %= mod;
        dp[i][1] = dp[i-1][0] + 4*dp[i-1][1];
        dp[i][1] %= mod;
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    int tt;
    cin >> tt;
    forn(i, tt){
        int input;
        cin >> input;
        out((dp[input][0] + dp[input][1])%mod);
    } 
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
