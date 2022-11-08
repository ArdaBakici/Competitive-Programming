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
    vector<int> pre_fix(n);
    forn(i, n){
        int input;
        cin >> input;
        if(i == 0){
            pre_fix[0] = input;
        }
        else{
            pre_fix[i] = pre_fix[i-1] + input;
        }
    }

    forn(i, k){
        int q_one, q_two;
        ll pre, suf;
        cin >> q_one >> q_two;

        if(q_one == 0){
            pre = 0;
        }
        else{
            pre = (ll) pre_fix[q_one-1];
        }

        suf = (ll) pre_fix[q_two-1];

        cout << (ll) suf-pre << endl;
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