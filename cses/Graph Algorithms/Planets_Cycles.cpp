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

vi visited;
vi a;
vi ans;

int f(int v, int size){
    if(visited[v]){
        if(visited[v] == 1){
            // newly discovered cycle
            ans[v] = size - ans[v];
            return v;
        }
        if(visited[v] == 2){
            // node already discovered
            return -1;
        }
    }
    visited[v] = 1;
    ans[v] = size;
    
    int res = f(a[v], size+1);
    visited[v] = 2;
    if(res == v){
        // last point of cycle before entering tree
        ans[v] = ans[a[v]];
        return -1;
    }
    else if(res == -1){
        // in tree connected to cycle
        ans[v] = ans[a[v]] + 1;
        return -1;
    }
    else{
        // in cycle
        ans[v] = ans[a[v]];
        return res;
    }
}

void solve(){
    int n;
    cin >> n;
    visited = vi(n, 0);
    ans = vi(n, 0);


    forn(i, n){
        int input;
        cin >> input;
        input--;
        a.pb(input);
    }

    forn(i, n){
        if(visited[i]) continue;
        f(i, 0);
    }

    forn(i, n){
        cout << ans[i] << " ";
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
