#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    forn(i,n){
        int input;
        cin >> input;
        arr.pb(input);
    }
    
    sort(iter(arr));

    ll ans = -1;

    forn(i, n-2){
        ll temp_ans;
        temp_ans = arr[i+1] - arr[i];
        temp_ans += arr[i+2] - arr[i+1];
        if(ans == -1){
            ans = temp_ans;
        }
        else{
            ans = min(ans, temp_ans);
        }
    }

    cout << ans << endl;
}

int main(){
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