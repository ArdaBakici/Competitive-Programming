#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define p(x) array<int, x>
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);
    vi visited(n, 0);

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        --v1, --v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    forn(i, n){
        if(visited[i]){
            continue;
        }
        queue<p(2)> bfs;
        bfs.push({i, 1});

        while(!bfs.empty()){
            auto [v, c] = bfs.front();
            bfs.pop();

            if(visited[v]){
                if(visited[v] != c){
                    out("IMPOSSIBLE");
                    return;
                }
                continue;
            }

            visited[v] = c;
            int fc = c == 1 ? 2 : 1;

            for(auto x: adj[v]){
                bfs.push({x, fc});
            }
        }
    }
       
    for(auto x: visited){
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
