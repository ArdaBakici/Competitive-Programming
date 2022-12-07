#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 10000000000000000
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
    vector<p(3)> edges;
    vector<vector<bool>> adj(n, vector<bool>(n, false));

    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        if(v1 == v2 && w < 0){
            out("YES");
            cout << v1+1 << " " << v1+1;
            return;
        }
        edges.pb({v1, v2, w});
        adj[v1][v2] = true;
    }

    bool flag = true;
    vector<bool> cyc(n, false);
    vector<p(2)> gobfs;

    vi dist(n, INF);
    dist[edges[0][0]] = 0;
    forn(i, n-1){
        for(auto [v1, v2, w]: edges){
            if(dist[v1] != INF){
                dist[v2] = min(dist[v2], dist[v1]+w);
            }
        }
    }

    for(auto [v1, v2, w]: edges){
        if(dist[v1] != INF){
            if(dist[v1]+w < dist[v2]){
                flag = false;
                gobfs.pb({v1, -1});
                cyc[v1] = true;
                dist[v2] = dist[v1]+w;
            }
            else{
                adj[v1][v2] = false;
            }
        }
    }

    if(flag){
        out("NO");
        return;
    }

    int res = -1;
    vector<int> visited(n, 0);

    for(auto elem: gobfs){
        fill(iter(visited), false);
        queue<p(2)> bfs;
        bfs.push(elem);
        while(!bfs.empty()){
            auto [v, prev] = bfs.front();
            bfs.pop();

            if(visited[v]){
                if(v == elem[0]){
                    visited[v] = prev;
                    res = v;
                    break;
                }
                continue;
            }

            visited[v] = prev;

            forn(x, n){
                if(adj[x][v] && cyc[x]){
                    bfs.push({x, v});
                }
            }
        }
        if(res != -1){
            break;
        }
    }

    out("YES");
    int pres = res;
    do{
        cout << res+1 << " ";
        res = visited[res];
    }while(res != pres);

    cout << res+1 << endl;
    
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
