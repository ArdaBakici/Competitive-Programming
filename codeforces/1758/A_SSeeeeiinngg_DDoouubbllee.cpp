#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    string s;
    cin >> s;
    string ans;
    vi arr(26, 0);

    for(auto x:s){
        int index = x - 'a';
        arr[index] += 2;
    }

    forn(i, 26){
        int index = arr[i]/2;
        arr[i] -= index;
        char t = i + 'a';
        while(index){
            ans.pb(t);
            index--;
        }
    }

    for(int i = 25; i>=0;i--){
        int index = arr[i];
        arr[i] -= index;
        char t = i + 'a';
        while(index){
            ans.pb(t);
            index--;
        }
    }

    out(ans);
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
