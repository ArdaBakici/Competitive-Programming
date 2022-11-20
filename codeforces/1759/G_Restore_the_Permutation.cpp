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
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<bool> ex(n, false);
    vi arr;

    forn(i, n/2){
        int input;
        cin >> input;
        ex[input-1] = true;
        arr.pb(input);
    }

    int p1 = 0;
    string ans;
    for(auto x:arr){
        for(;ex[p1];p1++){
        }
        if((p1+1) > x){
            out(-1);
            return;
        }
        ans.pb((p1+1 + '0'));
        ans.pb(' ');
        ans.pb(x + '0');
        ans.pb(' ');
        p1++;
    }
    cout << ans << endl;
}

int32_t main(){
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
