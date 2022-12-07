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
*
*   Solution seems to be correct
*   Checked from discord
*
*/

void solve(){
    int n, k;
    int m = 1000000007;
    cin >> n >> k;
    vector<vi> dp(k+1, vi(n+1, 0));
    vi cost;

    forn(i, n){
        int input;
        cin >> input;
        cost.pb(input);
    }

    for(int x = 0; x <= k; x++){
        for(int w = 0; w <= n; w++){
            if(x == 0){
                dp[x][w] = 1;
                continue;
            }
            if(w == 0){
                dp[x][w] = 0;
                continue;
            }

            if(x-cost[n-w] >= 0){
                dp[x][w] += dp[x-cost[n-w]][w-1] % m;
            }
            // 2  1 
            dp[x][w] += dp[x][w-1] % m;
            dp[x][w] %= m;
        }
    }

    out(dp[k][n]);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
