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
    vi arr;
    vi suffix(n);

    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
    }

    int sum = 0;
    int first0 = INT_MAX;
    int last1 = -1;
    int inv = 0;

    for(int i = arr.size()-1; i >= 0; i--){
        if(arr[i] == 0){
            first0 = min(i, first0);
        }

        if(arr[i] == 1){
            inv += n-i-1-sum;
            last1 = max(i, last1);
        }
        
        suffix[i] = sum;
        sum += arr[i];
    }

    int addit = 0;

    if(first0 != INT_MAX){
        addit = max(addit, n-1-first0-suffix[first0] - (sum-suffix[first0]));
    }

    if(last1 != -1){
        addit = max(addit, sum-suffix[last1]-1 - (n-last1-1-suffix[last1]));
    }

    inv += addit;
    
    out(inv);
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
