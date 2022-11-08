#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()

using namespace std;

void solve(){
    string a, b;
    int n, x, y;

    cin >> n >> x >> y;
    cin >> a >> b;
    
    vector<int> diff;
    forn(i, a.length()){
        if(a[i] != b[i]){
            diff.push_back(i);
        }
    }

    if(diff.size()%2){
        cout << -1 << endl;
        return;
    }

    bool flag = x < 2*y; // x can be used
    ll ans = 0;


    forn(index, diff.size()/2){
        int comp = diff[(diff.size()/2) + index];
        int i = diff[index];
        if((comp - i) == 1){
            if(flag){
                ans += (ll)x;
            }
            else{
                ans += (ll)2*y;
            }
        }
        else{
            ans += (ll)y;
        }
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