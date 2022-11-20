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
    int n, l;
    cin >> n >> l;
    int rem = l;
    vi arr;
    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
    }

    for(auto x:arr){
        if(x == 1){
            if(rem > 1){
                rem -= 2;
            }
        }
        else{
            if(rem>2){
                rem-=3;
            }
            else if(rem == 2){
                rem = 0;
            }
            else{
                out("No");
                return;
            }
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
