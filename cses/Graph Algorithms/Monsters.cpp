#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define p(x) array<int, x>
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vi> map(n, vi(m, INT_MAX));
    vector<vi> visited(n, vi(m, 0));
    queue<p(3)> bfs;
    p(2) a;

    forn(i, n){
        string t;
        cin >> t;
        forn(x, m){
            if(t[x] == '#'){
                map[i][x] = -1;
            }
            if(t[x] == 'M'){
                bfs.push({i, x, 0});
                map[i][x] = 0;
            }
            if(t[x] == 'A'){
                map[i][x] = 0;
                a = {i, x};
            }
        }
    }

    while(!bfs.empty()){
        auto [vx, vy, h] = bfs.front();
        bfs.pop();

        if(vx<n-1 && map[vx+1][vy] > h+1) {bfs.push({vx+1, vy, h+1}); map[vx+1][vy] = h+1;}
        if(vx>0 && map[vx-1][vy] > h+1) {bfs.push({vx-1, vy, h+1}); map[vx-1][vy] = h+1;}
        if(vy<m-1 && map[vx][vy+1] > h+1) {bfs.push({vx, vy+1, h+1}); map[vx][vy+1] = h+1;}
        if(vy>0 && map[vx][vy-1] > h+1) {bfs.push({vx, vy-1, h+1}); map[vx][vy-1] = h+1;}
    }

    queue<p(4)> bfs2;
    p(2) res = {-2, -2};
    bfs2.push({a[0], a[1], 0, -1});
    map[a[0]][a[1]] = INT_MAX;

    while(!bfs2.empty()){
        auto [x, y, h, prev] = bfs2.front();
        bfs2.pop();

        if(map[x][y] <= h || visited[x][y]){
            continue;
        }

        visited[x][y] = prev;

        if(x == n-1 || y == m-1 || x == 0 || y == 0){
            res = {x, y};
            break;
        }

        if(x<n-1 && map[x+1][y] > h) bfs2.push({x+1, y, h+1, 4});
        if(x>0 && map[x-1][y] > h) bfs2.push({x-1, y, h+1, 3});
        if(y<m-1 && map[x][y+1] > h) bfs2.push({x, y+1, h+1, 2});
        if(y>0 && map[x][y-1] > h) bfs2.push({x, y-1, h+1, 1});
    }

    if(res[0] == -2){
        out("NO");
        return;
    }

    string ans;

    while(visited[res[0]][res[1]] != -1){
        switch (visited[res[0]][res[1]])
        {
        case 1:
            ans.pb('L');
            res[1]++;
            break;
        case 2:
            ans.pb('R');
            res[1]--;
            break;
        case 3:
            ans.pb('U');
            res[0]++;
            break;
        case 4:
            ans.pb('D');
            res[0]--;
            break;
        }
    }

    reverse(iter(ans));

    out("YES");
    out(ans.size());
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
