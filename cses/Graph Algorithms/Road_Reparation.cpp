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
    vector<vector<p(2)>> adj(n);
    vector<bool> visited(n, false);
    int ans = 0;
    int not_added = n;

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--; v2--;
        adj[v1].pb({w, v2});
        adj[v2].pb({w, v1});
    }

    priority_queue<p(2)> prim;
    prim.push({0, 0});
    while(!prim.empty()){
        auto [w, v] = prim.top();
        prim.pop();
        w *= -1;
        
        if(visited[v]){
            continue;
        }

        visited[v] = true;
        not_added--;
        ans += w;
        if(not_added == 0){
            break;
        }

        for(auto [nw, nv]: adj[v]){
            prim.push({-1*(nw), nv});
        }
    }

    if(not_added != 0){
        out("IMPOSSIBLE");
        return;
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
