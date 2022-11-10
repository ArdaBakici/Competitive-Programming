#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    int sum = 0;
    int minima = 10e10;
    vector<int> arr;
    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
        sum += input;
    }

    for(int i=0; i<(1 << n); i++){
        int sum_a = 0;
        forn(f, n){
            if(i&(1<<f)){
                sum_a += arr[f];
            }
        }
        int tmp = abs((2*sum_a) - sum);
        minima = min(minima, tmp);
    }

    out(minima);
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