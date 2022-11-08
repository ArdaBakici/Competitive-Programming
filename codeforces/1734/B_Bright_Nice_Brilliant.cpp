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
    forn(i, n){
        forn(x, i+1){
            if(x == 0 || x == i){
                cout << "1 ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
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