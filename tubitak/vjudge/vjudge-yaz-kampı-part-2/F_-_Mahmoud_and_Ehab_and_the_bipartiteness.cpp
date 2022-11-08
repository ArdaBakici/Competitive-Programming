#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<set<int>> adj(n);

    forn(i, n-1){
        int vertex_a, vertex_b;
        cin >> vertex_a >> vertex_b;
        vertex_a--;
        vertex_b--;
        adj[vertex_a].emplace(vertex_b);
        adj[vertex_b].emplace(vertex_a);
    }

    //bfs
    queue<pair<int, int>> bfs;
    vector<bool> visited(n);
    vector<int> odd;
    vector<int> even;
    fill(visited.begin(), visited.end(), false);
    bfs.push({0, 0});

    while(!bfs.empty()){
        pair<int, int> node = bfs.front();
        int vertex = node.first;
        bfs.pop();

        if(visited[vertex]){
            continue;
        }

        visited[vertex] = true;

        if(node.second%2){
            odd.push_back(vertex);
        }
        else{
            even.push_back(vertex);
        }

        for(auto i:adj[vertex]){
            bfs.push({i, node.second+1});
        }
    }

    ll ans = 0;
    
    if(even.size() < odd.size()){
        for(auto i:even){
            int n_size = adj[i].size();
            ans += (ll)odd.size()-n_size;
        }
    }
    else{
        for(auto i:odd){
            int n_size = adj[i].size();
            ans += (ll)even.size()-n_size;
        }
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}