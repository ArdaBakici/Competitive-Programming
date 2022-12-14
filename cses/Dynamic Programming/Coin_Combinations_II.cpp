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

    vector<int> memo(x+1, 0);

    memo[0] = 1;

    forn(k, n){
        for(int i = 0; i+arr[k] <= x; i++){
            if(memo[i] > 0) memo[i+arr[k]]+=memo[i];
            memo[i+arr[k]] %= m;
        }
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