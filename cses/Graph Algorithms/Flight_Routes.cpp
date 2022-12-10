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

void solve(){
    int n, m, k;
    vector<int> ans;
    cin >> n >> m >> k;
    vi visited(n);
    vector<vector<p(2)>> adj(n); 
    

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        adj[v1].pb({v2, w}); 
    }

    priority_queue<p(2)> djk;

    djk.push({0, 0});

    while(!djk.empty()){
        auto [w, v] = djk.top();
        w *= -1;
        djk.pop();

        if(v == n-1){
            ans.pb(w);
            if(ans.size() == k){
                break;
            }
            
        }

        if(visited[v] >= k){
            continue;
        }

        visited[v]++;

        for(auto [nv, nw]: adj[v]){
            djk.push({-1*(nw + w), nv});
        }
    }

    for(auto x: ans){
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
