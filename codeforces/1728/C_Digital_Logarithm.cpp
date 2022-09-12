#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int n;
    set<int> a;
    set<int> b;
    cin >> n;
    forn(i, n){
        int input;
        cin >> input;
        a.emplace(input);
    }

    forn(i, n){
        int input;
        cin >> input;
        b.emplace(input);
    }

    /*for(auto i = a.cbegin(); i !=a.cend(); i++){
        cout << *i << " ";
    }*/

}

int main(){
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}