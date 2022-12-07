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
    vi visited(n, -2);

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        --v1, --v2;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    int col1 = -2;
    int col2 = -2;

    forn(i, n){
        if(visited[i] != -2){
            continue;
        }
        queue<array<int, 2>> bfs;
        bfs.push({i, -1});
        bool flag = false;
        while(!bfs.empty()){
            auto [v, prev] = bfs.front();
            bfs.pop();

            if(visited[v] != -2){
                col1 = v;
                col2 = prev;
                flag = true;
                break;
            }

            visited[v] = prev;

            for(auto x: adj[v]){
                if(x != prev){
                    bfs.push({x, v});
                }
            }
        }
        if(flag){
            break;
        }
    }


    int res = col1;
    vi ans;
    int tmp = col2;

    if(col1 == -2){
        out("IMPOSSIBLE");
        return;
    }

    vi nums(n, 0);

    while(col1 != -1){
        nums[col1]++;
        col1 = visited[col1];
    }

    while(col2 != -1){
        nums[col2]++;
        col2 = visited[col2];
    }

    while(res != -1){
        ans.pb(res);
        if(nums[res] > 1){
            break;
        }    
        
        res = visited[res];
    }

    reverse(iter(ans));
    res = tmp;

    while(res != -1){
        ans.pb(res);
        if(nums[res] > 1){
            break;
        }    
        
        res = visited[res];
    }

    out(ans.size());
    for(auto x:ans){
        cout << ++x << " ";
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
