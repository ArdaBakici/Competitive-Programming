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
    
    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
    }

    vector<int> memo(x+1, 0);

    memo[0] = 0;

    fornn(i, x){
        int minima = 10e7;
        for(auto f:arr){
            if(i-f >= 0){
                minima = min(memo[i-f]+1, minima);
            }
        }
        memo[i] = minima;
    }

    int limit = 10e7;
    if(memo[x] >= limit){
        out(-1);
        return;
    }
    out(memo[x]);
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