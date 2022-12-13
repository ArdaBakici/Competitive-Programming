/*
* Readability first and foremost
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define forin(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl
using namespace std;

unordered_map<int, vi> ladders;
unordered_map<int, bool> visited;

int f(int floor){
    visited[floor] = true;
    
    int ans = floor;
    for(auto x: ladders[floor]){
        if(visited[x]) continue;
        ans = max(ans, f(x));
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    forn(i, n){
        int v1, v2;
        cin >> v1 >> v2;
        visited[v1] = false;
        visited[v2] = false;
        ladders[v1].pb(v2);
        ladders[v2].pb(v1);
    }

    out(f(1));
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
