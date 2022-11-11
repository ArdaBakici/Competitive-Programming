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

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    int m = 1000000007;

    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
    }

    vector<vector<int>> memo(x+1);

    memo[0] = {-1};

    fornn(i, x){
        int ans = 0;
        for(auto f:arr){
            if(i-f >= 0){
                ans += memo[i-f].size();
                int z = 0;
                for(auto w:memo[i-f]){
                    if(f == w){
                        z++;
                    }
                }
                ans -= z;
                if(z != memo[i-f].size()){
                    memo[i].pb(f);
                }
                ans %= m;
            }
        }
    }

    out(memo[x].size());

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