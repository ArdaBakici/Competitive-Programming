#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;
    vector<int> s_arr;
    vector<int> t_arr;
    vector<char> s_c;
    vector<char> t_c;

    char prev = '0';
    int sp = -1;

    for(auto x: s){
        if(prev != x){
            sp++;
            s_arr.pb(0);
            s_c.pb(x);
        }
        s_arr[sp]++;
        prev = x;
    }

    prev = '0';
    sp = -1;
    for(auto x: t){
        if(prev != x){
            sp++;
            t_arr.pb(0);
            t_c.pb(x);
        }
        t_arr[sp]++;
        prev = x;
    }

    if(t_arr.size() != s_arr.size() || s_c != t_c){
        out("No");
        return;
    }

    forn(i, t_arr.size()){
        if(s_arr[i] > t_arr[i] || ((t_arr[i] > s_arr[i]) && s_arr[i] == 1)){
            out("No");
            return;
        }
    }

    out("Yes");
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