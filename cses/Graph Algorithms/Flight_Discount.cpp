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
    int n, m;
    cin >> n >> m;
    vector<vector<p(2)>> adj(n);
    vi nprice(n, INF);
    vi price(n, INF);

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        adj[v1].pb({w, v2});
    }

    priority_queue<p(4)> djk;
    djk.push({0, 1, 0, -1});

    while(!djk.empty()){
        auto [w, c, v, p] = djk.top();
        w *= -1;
        c *= -1;
        djk.pop();

        if(c){
            if(w >= price[v]){
                continue;
            }
            else{
                price[v] = w;
            }
        }
        else{
            if(w >= nprice[v]){
                continue;
            }
            else{
                nprice[v] = w;
            }
        }

        for(auto [nw, nv]: adj[v]){
            if(nv == p) continue;
            if(c) djk.push({-1*(w+(nw/2)), 0, nv, v});
            djk.push({-1*(nw+w), -1*c, nv, v});
        }
    }

    out(nprice[n-1]);
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
