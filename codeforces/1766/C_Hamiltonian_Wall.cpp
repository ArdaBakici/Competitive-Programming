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

vector<vi> wall;
vector<vector<bool>> visited;
int n;

int f(int x, int y){
    if(x >= n){
        return 0;
    }
    if(wall[y][x] != 1){
        return 0;
    }

    visited[y][x] = true;

    if((wall[1-y][x] == 1) && (!visited[1-y][x])){
        return f(x, 1-y) + 1;
    }
    else{
        return f(x+1, y) + 1;
    }
}

void solve(){
    n;
    string c1, c2;
    cin >> n >> c1 >> c2;
    wall = vector<vi>(2, vi(n, 0));
    visited = vector<vector<bool>>(2, vector<bool>(n, false));
    int blacks = 0;

    forn(i, n){
        wall[0][i] = c1[i] == 'B';
        wall[1][i] = c2[i] == 'B';
        if(c1[i] == 'B') blacks++;
        if(c2[i] == 'B') blacks++;
    }

    int ans = f(0,0);
    visited = vector<vector<bool>>(2, vector<bool>(n, false));
    ans = max(ans, f(0, 1));

    if(ans == blacks){
        out("YES");
    }
    else out("NO");
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
