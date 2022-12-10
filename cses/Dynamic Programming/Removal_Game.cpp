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
    int n;
    cin >> n;
    vi a;
    vector<vi> dp(n, vi(n, 0));

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    for(int i = n-1; i >= 0; i--){
        forn(x, n){
            if(x < i){
                continue;
            }
            if(i == x){
                dp[i][x] = a[i];
                continue;
            }
            if(i == n-2) dp[i][x] = a[i];
            else if(i < n-2) dp[i][x] = a[i] + min(dp[i+2][x], dp[i+1][x-1]);
            if(x == 1) dp[i][x] = max(dp[i][x], a[x]);
            else if(x > 1) dp[i][x] = max(dp[i][x], a[x] + min(dp[i][x-2], dp[i+1][x-1]));
        }
    }

    out(dp[0][n-1]);
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
