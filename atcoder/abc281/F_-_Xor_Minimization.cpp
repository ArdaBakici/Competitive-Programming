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

vi a;
vector<vi> dp;
vi rldp;

int f(int m, int low, int high){
    int zeros = -1;
    int ones = 0;

    int l = low;
    int r = high;

    while(l <= r){
        int mid = l + (r-l)/2;
        if(dp[mid][m]){
            //go left
            r = mid-1;
        }
        else{
            zeros = max(zeros, mid);
            l = mid + 1;
        }
    }
    if(zeros < 0){
        zeros = 0;
        ones = high - low + 1;
    }
    else{
        zeros -= low;
        zeros++;
        ones = (high - low + 1) - zeros;
    } 
    if(!ones || !zeros){
        if(!m) rldp[m] = 0;
        else rldp[m] = f(m-1, low, high);
    }
    else if(ones == 1 || zeros == 1){
        rldp[m] = 1 << m;
    }
    else{
        if(!m) rldp[m] = 1;
        else rldp[m] = (1 << m) + min(f(m-1, low, low+zeros-1), f(m-1, low+zeros, high));
    }
    return rldp[m];
}

void solve(){
    int n;
    cin >> n;
    dp = vector<vi>(n, vi(31, 0));
    rldp = vi(31, -2);

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    sort(iter(a));

    forn(x, n){
        int i = 0;
        while(a[x] > 0){
            if(a[x] & 1) dp[x][i] = 1;
            i++;
            a[x] >>= 1;
        }
    }

    out(f(30, 0, n-1));
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
