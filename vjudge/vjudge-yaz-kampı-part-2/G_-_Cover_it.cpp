#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

// wrong solution

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    forn(i, m){
        int vertex_a, vertex_b;
        cin >> vertex_a >> vertex_b;
        adj[vertex_a-1].push_back(vertex_b-1); 
        adj[vertex_b-1].push_back(vertex_a-1); 
    }
    vector<int> taken(n);
    fill(taken.begin(), taken.end(), -1);
    //increase i by +1 since these are indicies

    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    while(!bfs.empty()){
        pair<int, int> vertex = bfs.front();
        bfs.pop();
        if (taken[vertex.first] != -1){
            continue;
        }

        taken[vertex.first] = vertex.second;

        for(auto n_vertex: adj[vertex.first]){
            bfs.push({n_vertex, vertex.second + 1});
        }
    }

    vector<int> even;
    vector<int> odd;

    forn(i, n){
        if(taken[i]%2){
            even.push_back(i);
        }
        else{
            odd.push_back(i);
        }
    }

    if(even.size() < odd.size()){
        cout << even.size() << endl;
        for(auto vert:even){
            cout << vert+1 << " ";
        }
    }
    else{
        cout << odd.size() << endl;
        for(auto vert:odd){
            cout << vert+1 << " ";
        }
    }


    cout << endl;

}

int main(){
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}