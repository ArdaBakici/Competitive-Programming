#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define arr(x) array<int, x>
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vi> map(n, vi(m, 0));
    arr(3) a;
    arr(2) b;
    forn(i, n){
        string s;
        cin >> s;
        forn(x, m){
            map[i][x] = s[x] == '#';
            if(s[x] == 'A') a = {i, x, -1};
            if(s[x] == 'B') b = {i, x};
        }
    }

    queue<arr(3)> bfs;
    bfs.push(a);

    while(!bfs.empty()){
        auto [x1, y1, prev] = bfs.front();
        bfs.pop();
        if(arr(2)({x1, y1}) == b){
            map[x1][y1] = prev; 
            break;
        }
        if(map[x1][y1]){
            continue;
        }
        map[x1][y1] = prev;

        if(x1<n-1 && !map[x1+1][y1]) bfs.push({x1+1, y1, 4});
        if(x1>0 && !map[x1-1][y1]) bfs.push({x1-1, y1, 3});
        if(y1<m-1 && !map[x1][y1+1]) bfs.push({x1, y1+1, 2});
        if(y1>0 && !map[x1][y1-1]) bfs.push({x1, y1-1, 1});
    }

    string ans;
    auto [xr, yr] = b;
    if(!map[xr][yr]){
        out("NO");
        return;
    }

    out("YES");

    while(map[xr][yr] != -1){
        switch (map[xr][yr])
        {
        case 1:
            ans.pb('L');
            yr++;
            break;
        case 2:
            ans.pb('R');
            yr--;
            break;
        case 3:
            ans.pb('U');
            xr++;
            break;
        case 4:
            ans.pb('D');
            xr--;
            break;
        }
    }
    out(ans.length());
    reverse(iter(ans));
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
