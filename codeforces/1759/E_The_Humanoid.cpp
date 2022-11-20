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
    int n, rh;
    cin >> n >> rh;
    vi ast;
    int ans = 0;

    forn(i, n){
        int input;
        cin >> input;
        ast.pb(input);
    }

    sort(iter(ast));

    forn(i, 3){
        int pot[3];
        if(i == 0){
            pot[0] = 2;
            pot[1] = 2;
            pot[2] = 3;
        }
        if(i == 1){
            pot[0] = 2;
            pot[1] = 3;
            pot[2] = 2;
        }
        if(i == 2){
            pot[0] = 3;
            pot[1] = 2;
            pot[2] = 2;
        }
        int res = 0;
        int ifdex = 0;
        int h = rh;
        bool skip = false;
        for(auto x:ast){
            res++;
            skip = false;
            if(x < h){
                h += x/2;
                continue;
            }

            while(ifdex < 3){
                h *= pot[ifdex];
                ifdex++;
                if(x < h){
                    h+=x/2;
                    skip = true;
                    break;
                }
            }
            if(skip) continue;
            res--;
            break;
        }
        ans = max(res, ans);
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
