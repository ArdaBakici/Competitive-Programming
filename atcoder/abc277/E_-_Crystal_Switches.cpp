/*
* Readability first and foremost
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define forin(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl
using namespace std;

vector<vi> dp;
vector<bool> switches;
vector<vector<bool>> visited;
vector<vector<p(2)>> adj;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    adj = vector<vector<p(2)>>(n);
    switches = vector<bool>(n, false);
    dp = vector<vi>(n, vi(2, -1));
    visited = vector<vector<bool>>(n, vector<bool>(2, false));

    forn(i, m){
        int v1, v2, p;
        cin >> v1 >> v2 >> p;
        v1--; v2--;
        adj[v1].pb({v2, p});
        adj[v2].pb({v1, p});
    }

    forn(i, k){
        int input;
        cin >> input;
        input--;
        switches[input] = true;
    }

    dp[n-1][0] = 0;
    dp[n-1][1] = 0;

    priority_queue<p(3)> djk;
    djk.push({0, n-1, 0});
    djk.push({0, n-1, 1});

    int ans = INT_MAX;

    while(!djk.empty()){
        auto [w, v, p] = djk.top();
        w *= -1;
        djk.pop();
        if(visited[v][p]) continue;
        visited[v][p] = true;

        if(v == 0 && (p == 1 || switches[v])){
            ans = w;
            break;
        }

        for(auto [nv, np]: adj[v]){
            if(np == p){
                djk.push({-1*(w+1), nv, np});
            }
            else if(switches[v]){
                djk.push({-1*(w+1), nv, np});
            }
        }
    }

    if(ans != INT_MAX) out(ans);
    else out(-1);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
