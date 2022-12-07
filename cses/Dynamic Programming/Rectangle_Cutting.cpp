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

void solve(){
    int a, b;
    cin >> a >> b;
    vector<vi> dp(a+1, vi(b+1, INT_MAX));

    fornn(i, a){
        fornn(x, b){
            if(i == x){
                dp[i][x] = 0;
                continue;
            }

            if(x <= a && i <= b && dp[x][i] != INT_MAX){
                dp[i][x] = dp[x][i];
            }

            fornn(t, i-1){
                dp[i][x] = min(dp[i][x], 1 + dp[t][x] + dp[i-t][x]);
            }

            fornn(t, x-1){
                dp[i][x] = min(dp[i][x], 1 + dp[i][t] + dp[i][x-t]);
            }
        }
    }

    out(dp[a][b]);
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
