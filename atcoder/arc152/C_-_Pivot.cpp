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
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi arr;

    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
    }

    int min = arr[0];
    int max = arr[arr.size()-1];

    int opt_pivot = max/2;
    int found_pivot = -1;
    int l = 0;
    int r = arr.size()-1;

    while(l<=r && r>=l){
        int m = l+(r-l)/2;
        if(arr[m] == opt_pivot){
            found_pivot = opt_pivot;
            break;
        }
        else if(arr[m] < opt_pivot){
            l = m+1;
        }
        else{
            r = m-1;
            found_pivot = arr[m];
        }
    }

    int n_max = (2*found_pivot) - min;
    out((max<n_max?max:n_max));
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
