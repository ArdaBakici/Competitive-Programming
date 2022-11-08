#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int x[n];
    forn(i, n){
        cin >> x[i];
    }
    int limit = ceil(log2(n));
    cout << limit << endl;
    forn(f, k%limit){
        forn(i, n){
            if(i == 0){
                x[i] = x[i];
            }
            else{
                x[i] ^= x[i-1];
            }
        }
        cout << x[n-1] << endl;
    }
}

int main(){
    solve();
    return 0;
}