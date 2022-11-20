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
    int n, x;
    cin >> n >> x;
    int sum = 0;
    int maxim = 0;
    forn(i, n){
        int input;
        cin >> input;
        sum += input;
        maxim = max(input, maxim); 
    }
    //sum = 1275;
    int goal = 2*(sum + x);
    int l = 0;
    int r = 67;

    while(l<=r && r>=l){
        int m = l + (r-l)/2;
        int te = m*(m+1);
        if(te == goal){
            if(m >= maxim){
                out("YES");
            }
            else{
                out("NO");
            }
            return;
        }
        else if(te < goal){
            l = m+1;
        }
        else{
            r = m-1;
        }
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
