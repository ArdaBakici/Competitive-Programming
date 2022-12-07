#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
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
* CSES Shortest_Routes_II Dijakstra Implementation
* Not fast enough see Floyd-Warshall Implementation for Correct Solution
*
*/

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<p(2)>> adj(n);
    vector<vi> dist(n, vi(n, 0));

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1, --v2;
        adj[v1].pb({w, v2});
        adj[v2].pb({w, v1});
    }

    forn(v1, n){
        priority_queue<p(2)> bfs;
        bfs.push({0, v1});
        while(!bfs.empty()){
            auto [w, v] = bfs.top();
            bfs.pop();
            w *= -1;
            if(dist[v1][v]) continue;
            if(v == v1) dist[v1][v] = -1;
            else dist[v1][v] = w;

            for(auto [nw, nv]: adj[v]){
                bfs.push({-1*(nw+w), nv});
            }
        }
    }

    forn(i, q){
        int v1, v2;
        cin >> v1 >> v2;
        --v1, --v2;

        out(dist[v1][v2] == 0 ? -1 : dist[v1][v2]);
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
