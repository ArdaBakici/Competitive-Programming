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

vector<vi> adj;
vi coins;
vi dp;

int dfs(int v){
    if(dp[v] != -2) 
        return dp[v];
    int ans = 0;
    for(auto nv: adj[v]){
        ans = max(ans, dfs(nv));
    }
    ans += coins[v];
    dp[v] = ans;
    return dp[v];
}

void solve(){
    int n, m;
    cin >> n >> m;
    adj = vector<vi>(n);
    coins = vi(n);
    dp = vi(n, -2);

    forn(i, n){
        cin >> coins[i];
    }

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        adj[v1].pb(v2);
    }

    int maxim = 0;
    forn(i, n){
        maxim = max(maxim, dfs(i));
        out("test");
    }
    out(maxim);
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