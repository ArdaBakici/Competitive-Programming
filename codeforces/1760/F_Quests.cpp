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
    int n, c, d;
    cin >> n >> c >> d;
    vi arr;
    vi prefix;

    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
    }

    sort(iter(arr), greater<int>());

    if(arr[0]*d < c){
        out("Impossible");
        return;
    }

    if(arr[0] >= c){
        out("Infinity");
        return;
    }

    int sum = 0;

    for(auto x:arr){
        sum += x;
        prefix.pb(sum);
    }

    int l = 0;
    int r = d+2;
    int k = 0;
    while(l <= r && r >= l){
        int m = l + (r-l)/2;
        int rem = 0;
        int index;
        if((d%(m+1)) != 0){
            index = min((d%(m+1))-1, n-1);
            rem = prefix[index];
        }
        index = min(m, n-1);
        int val = (prefix[index]*(d/(m+1))) + rem;

        if(val < c){
            r = m-1;
        }
        if(val >= c){
            k = max(k, m);
            l = m+1;
        }
    }
    if(k > d){
        out("Infinity");
        return;
    }
    out(k);
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
