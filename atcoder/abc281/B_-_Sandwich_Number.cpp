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
    string s;
    cin >> s;

    bool first = true;
    bool alph = true;
    int num = 0;
    for(auto x: s){
        if(x-'0' < 10){
            if(alph){
                out("No");
                return;
            }
            if(num == 0 && x-'0' == 0){
                out("No");
                return;
            }
            num++;
            if(num == 6){
                alph = true;
            }
        }
        else{
            if(num != 6 && num != 0){
                out("No");
                return;
            }
            num = 0;
            if(!alph){
                out("No");
                return;
            }
            if(first){
                alph = false;
                first = false;
            }
            else first = true;
        }
    }
    if(first && alph && num == 0){
        out("Yes");
        return;
    }
    out("No");
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
