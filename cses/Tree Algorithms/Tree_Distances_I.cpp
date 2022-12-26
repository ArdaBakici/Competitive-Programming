/*
* Readability first and foremost
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define forin(i, n) for(int i = 1; i <= n; i++)
#define rforn(i, n) for(int i = n-1; i >= 0; i--)
#define rforin(i, n) for(int i = n; i >= 0; i--)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl
using namespace std;

vector<vi> adj;

void dfs(int v, int anc, vi &dist){
    if(anc == -1) dist[v] = 0;
    else dist[v] = dist[anc] + 1;
    for(auto nv: adj[v]){
        if(nv != anc){
            dfs(nv, v, dist);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    adj = vector<vi>(n);
    vi dist(n, -1);

    if(n == 1){
        out(0);
        return;
    }

    forn(i, n-1){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    dfs(0, -1, dist);

    int maxim = 0;
    int node_a = 0;

    forn(i, n){
        if(dist[i] > maxim){
            node_a = i;
            maxim = dist[i];
        }
    }

    vi a_dist(n, -1);
    dfs(node_a, -1, a_dist);
    maxim = 0; 
    int node_b = 0;
    vi b_dist(n, -1);

    forn(i, n){
        if(a_dist[i] > maxim){
            node_b = i;
            maxim = a_dist[i];
        }
    }

    dfs(node_b, -1, b_dist);

    forn(i, n){
        cout << max(a_dist[i], b_dist[i]) << " ";
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
