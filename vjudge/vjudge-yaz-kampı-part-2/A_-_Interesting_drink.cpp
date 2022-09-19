#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int n, q;
    cin >> n;
    vector<int> x;
    forn(i, n){
        int input;
        cin >> input;
        x.push_back(input);
    }
    sort(x.begin(), x.end());
    cin >> q;
    //int m[q];
    forn(i, q){
        ll input;
        cin >> input;
        auto ans = upper_bound(x.begin(), x.end(), input);
        cout << ans - x.begin() << endl;      
    }
}

int main(){
    solve();
    return 0;
}