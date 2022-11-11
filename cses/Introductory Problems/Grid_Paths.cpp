#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl
#define vi vector<int>
using namespace std;

int ans = 0;

bool visited[7][7];

void search(int x, int y){
    visited[y][x] = true;
    if(x==6 && y==6){
        bool visited_all = true;
        forn(i, 7){
            forn(x, 7){
                visited_all = visited[i][x];
            }
        }
        if(visited_all) ans++;
        return;
    }

    if(x>0 && !visited[y][x-1]){
        search(x-1, y);
    }

    if(y>0 && !visited[y-1][x]){
        search(x, y-1);
    }

    if(x<6 && !visited[y][x+1]){
        search(x+1, y);
    }

    if(y<6 && !visited[y+1][x]){
        search(x, y+1);
    }
    visited[y][x] = false;
}

void solve(){
    string s;
    cin >> s;
    forn(i, 7){
        forn(x, 7){
            visited[i][x] = false;
        }
    }
    visited[0][0] = true;
    search(0, 1);
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