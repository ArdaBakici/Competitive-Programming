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
    int n1, n2, k1, k2;
    int m = 100000000;
    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<vector<vi>>> dp(n1+1, vector<vector<vi>>(n2+1, vector<vi>(k1+1, vi(k2+1, 0))));

    for(int x1 = 0; x1 <= n1; x1++){
        for(int x2 = 0; x2 <= n2; x2++){
            for(int y1 = 0; y1 <= k1; y1++){
                for(int y2 = 0; y2 <= k2; y2++){
                    if(x1 == 0 && x2 == 0){
                        dp[x1][x2][y1][y2]++;
                        continue;
                    }
                    if(x2 >= 1 && y2 >= 1){
                        dp[x1][x2][y1][y2] += dp[x1][x2-1][k1][y2-1]%m;
                        dp[x1][x2][y1][y2] %= m;
                    }
                    if(x1 >= 1 && y1 >= 1){
                        dp[x1][x2][y1][y2] += dp[x1-1][x2][y1-1][k2]%m;
                        dp[x1][x2][y1][y2] %= m; 
                    }
                }
            }
        }    
    }

    out(dp[n1][n2][k1][k2]);
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
