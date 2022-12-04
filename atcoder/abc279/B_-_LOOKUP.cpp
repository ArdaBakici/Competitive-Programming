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
    string s, t;
    cin >> s >> t;

    int pa = 0;
    bool flag = false;

    for(auto x:s){
        if(x == t[pa]){
            pa++;
            if(pa == t.length()){
                flag = true;
                break;
            }
        }
        else{
            pa = 0;
        }
    }

    if(flag){
        out("Yes");
    }
    else{
        out("No");
    }
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
