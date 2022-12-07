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
    int m = 100000;
    cin >> n;
    vi a;
    vector<vector<bool>> dp(m+1, vector<bool>(n, false));

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    for(int x = 0; x <= m; x++){
        for(int i = n-1; i >= 0; i--){
            if(x == 0){
                dp[x][i] = true;
                continue;
            }
            if(i == n-1){
                if(x-a[i] == 0){
                    dp[x][i] = true;
                }
                continue;
            } 
            dp[x][i] = dp[x][i+1];
            if(x-a[i] >= 0) 
                dp[x][i] = dp[x][i] || dp[x-a[i]][i+1];
            /*if(dp[x][i]){
                out(x);
            }*/
        }
    }

    vi ans;

    fornn(x, m){
        if(dp[x][0]) ans.pb(x);
    }

    out(ans.size());
    for(auto x: ans){
        cout << x << " ";
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
