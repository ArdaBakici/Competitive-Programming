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
    int n;
    cin >> n;
    vector<int> even, odd;
    forn(i, n){
        int input;
        cin >> input;
        if(input%2){
            odd.push_back(input);
        }
        else{
            even.pb(input);
        }
    }

    sort(iter(odd));
    sort(iter(even));

    if(odd.size() < 2 || even.size() < 2){
        if(even.size() < 2 && odd.size() >= 2){
            ll ans = odd[odd.size()-1] + odd[odd.size()-2];
            cout << ans << endl;
            return;
        }
        else if(even.size() < 2 && odd.size() < 2){
            cout << -1 << endl;
            return;
        }
        else{
            ll ans = even[even.size()-1] + even[even.size()-2];
            cout << ans << endl;
            return;
        }
    }
    else{
        ll large_odd = odd[odd.size()-1] + odd[odd.size()-2];
        ll large_even = even[even.size()-1] + even[even.size()-2];
        ll ans = large_odd > large_even ? large_odd : large_even;
        cout << ans << endl;
    }
}

int main(){
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