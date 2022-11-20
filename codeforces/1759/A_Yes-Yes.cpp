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
    string s;

    cin >> s;

    string yes = "Yes";
    int index = 0;
    int lx=0;
    bool found = false;

    while(lx < s.length()){
        char x = s[lx];
        if(x == yes[index]){
            index++;
            lx++;
            found = true;
        }
        else{
            if(found){
                out("NO");
                return;
            }
            index++;
        }
        if(index > 2){
            if(!found){
                out("NO");
                return;
            }
            index %= 3;
        }
    }
    out("YES");
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
