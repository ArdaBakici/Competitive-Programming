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
vector<vi> adj;
vi scc;

void dfs(int v){
    if(visited[v]) return;
    visited[v] = true;
    for(auto nv: adj[v]){
        dfs(nv);
    }
    scc.push_back(v);
}

void solve(){
    int n, m;
    cin >> n >> m;
    adj = vector<vi>(n);
    vector<vi> rv_adj(n);
    visited = vector<bool>(n, false);
    vector<vi> components(n);

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        adj[v1].pb(v2);
        rv_adj[v2].pb(v1);
    }

    forn(i, n){
        dfs(i);
    }

    visited = vector<bool>(n, false);
    int sv = -1;
    for(int i = scc.size()-1; i>=0; i--){
        if(visited[scc[i]]) continue;
        sv++;
        stack<int> dfs;
        dfs.push(scc[i]);
        while(!dfs.empty()){
            auto v = dfs.top();
            dfs.pop();
            if(visited[v]) continue;
            visited[v] = true;
            components[sv].pb(v);
            for(auto nv: rv_adj[v]){
                dfs.push(nv);
            }
        }
    }

    if(sv > 0){
        out("NO");
        cout << components[1][0]+1 << " " << components[0][0]+1;
    }
    else out("YES");
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
