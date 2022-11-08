#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> highest(k);
    fill(iter(highest), 0);
    forn(i, n){
        int input;
        cin >> input;
        highest[(i+1)%k] = max(highest[(i+1)%k], input);
    }

    ll ans = 0;
    for(int i:highest){
        ans += (ll)i;
    }

    cout << ans << endl;
}

int main(){
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/