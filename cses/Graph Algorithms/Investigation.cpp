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
    int modulo = 10e8+7;
    int n, m;
    cin >> n >> m;
    vector<vector<p(2)>> adj(n);
    vector<p(4)> dp(n, {100000000000000, 0, 100000000000000, 0});

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        adj[v1].pb({w, v2});
    }

    priority_queue<p(3)> djk;

    djk.push({0, 0, -1});

    while(!djk.empty()){
        auto [w, v, prev] = djk.top();
        w *= -1;
        djk.pop();

        if(v == 0){
            dp[v][0] = 0;
            dp[v][1] = 1;
            dp[v][2] = 0;
            dp[v][3] = 0;
        }

        if(w > dp[v][0]) continue;

        for(auto [nw, nv]: adj[v]){
            if(nw+w <= dp[nv][0]){
                if(nw+w < dp[nv][0]){
                    djk.push({-1*(nw+w), nv, v});
                    dp[nv][0] = nw+w;
                    dp[nv][1] = dp[v][1];
                    dp[nv][2] = dp[v][2]+1;
                    dp[nv][3] = dp[v][3]+1;
                }
                else{
                    dp[nv][1] += dp[v][1];
                    dp[nv][2] = min(dp[nv][2], dp[v][2]+1);
                    dp[nv][3] = max(dp[nv][3], dp[v][3]+1);
                }
                dp[nv][1] %= modulo;
            } 
        }
    }

    forn(i, 4){
        cout << dp[n-1][i] << " ";
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
