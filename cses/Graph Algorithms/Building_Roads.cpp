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
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);
    vector<bool> visited(n, false);
    vector<array<int, 2>> ans;

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    forn(i, n){
        if(visited[i]){
            continue;
        }

        if(i){
            ans.pb({i-1, i});
        }

        stack<int> dfs;
        dfs.push(i);
        while(!dfs.empty()){
            int v1 = dfs.top();
            dfs.pop();
            if(visited[v1]){
                continue;
            }
            visited[v1] = true;

            for(auto x: adj[v1]){
                dfs.push(x);
            }
        }
    }

    out(ans.size());
    for(auto [x, y]: ans){
        cout << ++x << " " << ++y << endl;
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
