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
vector<p(2)> dp;
int ans = 0;
int n;

void dfs(int v){
    int index = -2;
    int maxim = 0;
    for(auto nv: adj[v]){
        if(!dp[nv][1]) dfs(nv);
        if(maxim < dp[nv][0]){
            maxim = dp[nv][0];
            index = nv;
        }
    }
    dp[v] = {maxim ? maxim + 1 : 0, index};
}

void solve(){
    int m;
    cin >> n >> m;
    adj.resize(n);
    dp = vector<p(2)>(n, {0, 0});
    dp[n-1] = {1, -1};
    
    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        adj[v1].pb(v2);
    }

    dfs(0);
    
    if(dp[0][0] == 0){
        out("IMPOSSIBLE");
        return;
    }

    out(dp[0][0]);

    int res = 0;
    while(res != -1){
        cout << res+1 << " ";
        res = dp[res][1];
    }
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
