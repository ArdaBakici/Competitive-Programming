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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vi> adj(n, vi(n, 0));

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1, --v2;
        adj[v1][v2] = min(adj[v1][v2] == 0 ? INT_MAX : adj[v1][v2], w);
        adj[v2][v1] = min(adj[v2][v1] == 0 ? INT_MAX : adj[v2][v1], w);
    }

    forn(i, n){
        forn(j, n){
            if(i == j) adj[i][j] = 0;
            else if(!adj[i][j]) adj[i][j] = -1;
        }
    }

    forn(k, n){
        forn(i, n){
            forn(j, n){
                if(adj[i][j] == -1){
                    if(adj[i][k] == -1 || adj[k][j] == -1) adj[i][j] = -1;
                    else adj[i][j] = adj[i][k] + adj[k][j];
                }
                else{
                    if(adj[i][k] != -1 && adj[k][j] != -1) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    forn(i, q){
        int v1, v2;
        cin >> v1 >> v2;
        --v1, --v2;
        out(adj[v1][v2]);
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
