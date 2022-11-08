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
    int n, k;
    cin >> n >> k;
    vector<ll> arr;
    forn(i, k){
        ll input;
        cin >> input;
        arr.pb(input);
    }

    ll ans = 0;
    for(bool flag = true; ; flag = !flag){
        ll greatest = 0;
        int l = 0, r = k-1;
        
        while(l <= r && r >= l){
            int m = l + (r-l)/2;
            if(arr[m] == n){
                greatest = n;
                break;
            }
            else if(arr[m] < n){
                greatest = max(greatest, arr[m]);
                l = m+1;
            }
            else{
                r = m-1;
            }
        }

        if(flag){
            ans += (ll)greatest;
        }

        n -= greatest;
        
        if(n == 0){
            break;
        }
    }
    
    cout << ans << endl;
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