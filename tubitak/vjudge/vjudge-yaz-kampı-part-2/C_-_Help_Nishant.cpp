#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int n;
    cin >> n;
    ll int l, r, m, ans;
    l = 0;
    r = n;
    ans = 0;
    while(l <= r && r >= l){
        m = l + (r - l)/2;
        long long int res = ((m)*((m+1))/2);
        if(res == n){
            ans = m - 1;
            break;
        }
        if(res > n){
            r = m - 1;
        }
        else{
            ans = max(ans, m);
            l = m + 1;    
        }
    }

    cout << 2*(ans+1) << endl;
}

int main(){
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}