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
vector<bool> visited;
vi dp;
int n;
int m = 10e8+7;

void dfs(int v){
    int ans = 0;
    visited[v] = true;
    for(auto nv: adj[v]){
        if(!visited[nv]) dfs(nv);
        ans += dp[nv];
        ans %= m;
    }
    dp[v] = ans;
}

void solve(){
    int m;
    cin >> n >> m;
    adj.resize(n);
    visited = vector<bool>(n, false);
    dp = vi(n, 0);
    dp[n-1] = 1;
    visited[n-1] = true;
    
    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        adj[v1].pb(v2);
    }

    dfs(0);

    out(dp[0]);
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
