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
    vector<array<int, 2>> visited(n, {INT_MAX, -1});

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        --v1, --v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    queue<array<int , 3>> dfs;
    dfs.push({0, 1, -1});

    while(!dfs.empty()){
        auto [x, val, prev] = dfs.front();
        dfs.pop();

        if(val >= visited[x][0]){
            continue;
        }

        visited[x] = {val, prev};

        for(auto v: adj[x]){
            dfs.push({v, val+1, x});
        }
    }

    if(visited[n-1][0] == INT_MAX){
        out("IMPOSSIBLE");
        return;
    }

    out(visited[n-1][0]);

    int cur = n-1;
    stack<int> ans;

    while(cur != -1){
        ans.push(cur);
        cur = visited[cur][1];
    }

    while(!ans.empty()){
        int val = ans.top();
        ans.pop();
        cout << ++val << " ";
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
