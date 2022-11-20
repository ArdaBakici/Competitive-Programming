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
    int n;
    cin >> n;
    vi arr;
    int a = 0;
    int b = 0;

    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
    }

    bool check_a = true;

    if(n > 2 && !(n%2)){
        for(auto x:arr){
            if(a==0){
                a = x;
            }
            else if(b==0){
                b = x;
            }

            if(check_a){
                if(x == a){
                    check_a = false;
                }
                else{
                    out(n);
                    return;
                }
            }
            else{
                if(x == b){
                    check_a = true;
                }
                else{
                    out(n);
                    return;
                }
            }
        }
        out(((n-4)/2)+3);
        return;
    }

    out(n);
    
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
