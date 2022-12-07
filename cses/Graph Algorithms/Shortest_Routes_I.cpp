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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<p(2)>> adj(n);
    vi visited(n, 0);

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1, --v2;
        adj[v1].pb({w, v2});
    }

    priority_queue<p(2)> djk;

    djk.push({0, 0});

    while(!djk.empty()){
        auto [w, v] = djk.top();
        w *= -1;
        djk.pop();

        if(visited[v]){
            continue;
        }

        if(v == 0)
            visited[v] = -1;
        else
            visited[v] = w;

        for(auto [nw, nv]: adj[v]){
            djk.push({-1*(w+nw), nv});
        }
    }

    forn(i, n){
        if(visited[i] == -1){
            cout << 0 << " ";
            continue;
        }
        cout << visited[i] << " ";
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
