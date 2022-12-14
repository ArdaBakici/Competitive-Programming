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
    int n, m;
    cin >> n >> m;
    vi a;
    int mod = 1000000007;
    vector<vi> dp(n, vi(m+1, 0));

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    if(a[0] != 0){
        dp[0][a[0]] = 1;
    }
    else{
        fornn(i, m){
            dp[0][i] = 1;    
        }
    }

    for(int i = 1; i < n; i++){
        fornn(x, m){
            if(a[i] != 0 && x != a[i]){
                dp[i][x] = 0;
                continue;
            }
            if(x > 1) dp[i][x] += dp[i-1][x-1];
            dp[i][x] %= mod;
            if(x < m) dp[i][x] += dp[i-1][x+1]; 
            dp[i][x] %= mod;
            dp[i][x] += dp[i-1][x];
            dp[i][x] %= mod;
        }
    }

    int ans = 0;

    fornn(x, m){
        ans += dp[n-1][x];
        ans %= mod;
    }

    out(ans);
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
