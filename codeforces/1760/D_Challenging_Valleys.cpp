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
    int n;
    cin >> n;
    bool l = false;
    int ans = 0;
    int prev = 10e10;
    forn(i, n){
        int input;
        cin >> input;

        if(i==0){
            l = true;
        }

        if(input < prev){
            l = true;
        }
        else if(input > prev){
            if(l){
                ans++;
            }
            l = false;
        }

        prev = input;
    }

    ans += l;

    if(ans == 1){
        out("YES");
    }
    else{
        out("NO");
    }
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
