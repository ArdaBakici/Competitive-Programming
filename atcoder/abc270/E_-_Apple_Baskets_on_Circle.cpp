#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> arr;
    forn(i, n){
        ll input;
        cin >> input;
        arr.pb(input);
    }

    while(k>0){
        forn(i, n){
            if(arr[i] > 0){
                arr[i]--;
                k--;
                if(k==0){
                    break;
                }
            }
        }
        if(k==0){
            break;
        }
    }

    for(auto x:arr){
        cout << x << " ";
    }
}

int main(){
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