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

vector<bool> visited;
vi topo;
vector<vi> adj;
vi parent;

int bfs(int v, int prev){
    if(parent[v] != -2){
        parent[v] = prev;
        return v;
    }

    parent[v] = prev;
    visited[v] = true;

    for(auto nv: adj[v]){
        if(visited[nv] && parent[nv] == -2) continue;
        int res = bfs(nv, v); 
        if(res != -2) return res;
    }

    parent[v] = -2;
    topo.pb(v+1);
    return -2;
}

void solve(){
    int n, m;
    cin >> n >> m;
    visited = vector<bool>(n, false);
    adj.resize(n);
    parent = vi(n, -2);

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        adj[v1].pb(v2);
    }

    int ans = -2;

    forn(i, n){
        if(visited[i]) continue;
        ans = bfs(i, -1);
        if(ans != -2){
            break;
        }
    }

    if(ans != -2){
        out("IMPOSSIBLE");
        return;
    }

    reverse(iter(topo));

    for(auto x: topo){
        cout << x << " ";
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
