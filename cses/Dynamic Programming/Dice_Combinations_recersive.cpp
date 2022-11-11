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

vector<int> memo(1000000, 0);
int m = 1000000007;

int search(int n){
    int ans = 0;
    fornn(i, 6){
        if(n-i < 0){
            break;
        }
        if(memo[n-i] == 0){
            memo[n-i] = search(n-i)%m; 
        }
        ans += memo[n-i];
    }
    return ans%m;
}

void solve(){
    int n;
    cin >> n;
    memo[0] = 1;
    out(search(n));
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