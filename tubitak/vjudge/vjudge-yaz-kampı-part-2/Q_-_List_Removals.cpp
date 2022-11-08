#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int n;
    cin >> n;
    unordered_multiset<int> mc;

    forn(i, n){
        int input;
        cin >> input;
        mc.emplace(input);
    }

    forn(i, n){
        int input;
        cin >> input;
        cout << mc.extract() [input-1] << " ";
        mc.erase(mc.begin() + input - 1);
    }
    cout << endl;
}

int main(){
    solve();
    return 0;
}