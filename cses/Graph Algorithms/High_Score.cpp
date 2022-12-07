#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define INF 10000000000000
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n, vi(n, INF));
    vector<p(3)> edges;
    queue<int> visitlist;
    vi chlist(n, false);
    vi dist(n, INF);
    
    // get input
    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        w *= -1;
        adj[v1][v2] = min(adj[v1][v2], w);
    }

    // reverse bfs from destination node to find all nodes that can effect the answer
    visitlist.push(n-1);

    while(!visitlist.empty()){
        int x = visitlist.front();
        visitlist.pop();

        if(chlist[x]){
            continue;
        }

        chlist[x] = true;

        forn(i, n){
            if(adj[i][x] != INF){
                visitlist.push(i);
            }
        }
    }

    // create list of edges
    forn(i, n){
        forn(j, n){
            if(adj[i][j] != INF){
                edges.pb({i, j, adj[i][j]});
            }
        }
    }

    // bellmen-ford
    dist[0] = 0;
    forn(i, n-1){
        for(auto [v1, v2, w]: edges){
            if(dist[v1] != INF){
                dist[v2] = min(dist[v2], dist[v1] + w);
            }
        }
    }

    // check for any negative cycles
    vi prev_dist = dist;
    for(auto [v1, v2, w]: edges){
        if(dist[v1] != INF){
            dist[v2] = min(dist[v2], dist[v1] + w);
        }
    }
    
    // check if negative cycles effect the answer
    forn(x, n){
        if(dist[x] != prev_dist[x] && chlist[x]){
            out(-1);
            return;
        }
    }

    out(-1*dist[n-1]);
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
