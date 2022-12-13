#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n;
    string s;
    vector<vector<int>> alp(26, vector<int>(26, 0));
    cin >> n;
    cin >> s;
    bool flag = false;
    forn(i, n-1){
        if(alp[s[i]-'a'][s[i+1]-'a']){
            if(alp[s[i]-'a'][s[i+1]-'a'] < i){
                out("YES");
                return;
            }
        }
        else alp[s[i]-'a'][s[i+1]-'a'] = i+1;
    }
    out("NO");
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
