#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"

using namespace std;


void solve(){
    ll n;
    ll ans = 0;
    ll index = 0;
    ll limit = 1;
    cin >> n;
    vector<ll> arr;

    forn(i, n){
        ll input;
        cin >> input;
        arr.pb(input);
    }

    forn(j, n){
        while(limit>arr[j] && index<n){
            index++;
            limit--;
        }

        ans += (j-index+1);
        limit++;
    }

    cout << ans << endl;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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