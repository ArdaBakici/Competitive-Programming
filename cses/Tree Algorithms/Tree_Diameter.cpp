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

vi dist;
vector<vi> adj;

void dfs(int v, int parent){
    if(parent == -1){
        dist[v] = 0;    
    }
    else dist[v] = dist[parent]+1;

    for(auto nv: adj[v]){
        if(nv != parent){
            dfs(nv, v);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    adj = vector<vi>(n);
    dist = vi(n, -1);
    if(n==1){
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

    dfs(1, -1);

    int maxim = 0;
    int mnode = 0;

    forn(i, n){
        if(dist[i] > maxim){
            mnode = i;
            maxim = dist[i];
        }
    }

    fill(iter(dist), -1);

    dfs(mnode, -1);

    maxim = 0;
    
    forn(i, n){
        maxim = max(maxim, dist[i]);
    }

    out(maxim);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
