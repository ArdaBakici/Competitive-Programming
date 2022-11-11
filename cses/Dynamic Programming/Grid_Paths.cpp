#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int m = 1000000007;
    vector<string> sarr(n);
    forn(i, n){
        cin >> sarr[i];
    }

    vector<vector<int>> memo(n, vector<int>(n, 0));

    forn(y, n){
        forn(x, n){
            if(sarr[y][x] == '*'){
                memo[y][x] = 0;
                continue;
            }
            if(y == 0 && x == 0){
                memo[y][x] = 1;
                continue;
            }
            int ans = 0;
            if(x>0) ans += memo[y][x-1];
            if(y>0) ans += memo[y-1][x];
            ans %= m;
            memo[y][x] = ans;
        }
    }
    out(memo[n-1][n-1]);
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