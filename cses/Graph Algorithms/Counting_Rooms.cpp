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
    int ans = 0;
    vector<bool> visited(n*m, false);
    vector<vi> map(n, vi(m, 0));

    forn(i, n){
        string t;
        cin >> t;
        forn(x, m){
            map[i][x] = (t[x] == '.' ? 0 : 1);
        }
    }

    forn(i, n){
        forn(x, m){
            if(!map[i][x]){
                ans++;
                stack<pair<int, int>> dfs;
                dfs.push({i, x});
                while(!dfs.empty()){
                    pair<int, int> q = dfs.top();
                    int x1 = q.first;
                    int y1 = q.second;
                    dfs.pop();
                    if(map[x1][y1]){
                       continue; 
                    }
                    map[x1][y1] = 2;
                    
                    if(x1<n-1 && !map[x1+1][y1]) dfs.push({x1+1, y1});
                    if(x1>0 && !map[x1-1][y1]) dfs.push({x1-1, y1});
                    if(y1<m-1 && !map[x1][y1+1]) dfs.push({x1, y1+1});
                    if(y1>0 && !map[x1][y1-1]) dfs.push({x1, y1-1});
                }
            }
        }
    }
    out(ans);
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
