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
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int m = 1000000007;
    vector<vi> memo(n+1,vi(k+1, 0));
    
    memo[1][0] = 3;
    memo[1][1] = 1;
    memo[2][0] = 9;
    memo[2][1] = 4;
    memo[2][2] = 3;

    for(int i = 3; i <= n; i++){
        forn(x, min(i, k)+1){
            int sum = 0;

            if(n > 0 && x > 0){
                sum += (memo[i-1][x-1]);
            }

            if(n > 2 && x > 0){
                sum -= 2*(memo[i-2][x-1]);
            }

            if(n > 1){
                sum += 3*(memo[i-1][x]);
            }

            /*if(sum < 0){
                out("here");
            }*/

            sum %= m;
            memo[i][x] = sum;
        }
    }

    out(memo[n][k]);
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
