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


void solve(){
    int n, q;
    cin >> n >> q;
    int dp[n][30]; // this solution gets tle if we do this vector<vector<int>> why?

    forn(i, n){
        int input;
        cin >> input;
        input--;
        dp[i][0] = input;
    }

    for(int x = 1; x < 30; x++){
        forn(i, n){
            dp[i][x] = dp[dp[i][x-1]][x-1];
        }
    }

    forn(i, q){
        int x, k;
        cin >> x >> k;
        x--;
        vi qarr;
        for(int f = 0; (1 << f) <= k ; f++)
        {
            if(k & (1 << f)) x = dp[x][f];
        }
        out(x+1);
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
