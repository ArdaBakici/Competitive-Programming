#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int input;
    cin >> input;
    if (input == 2){
        cout << "NO";
        return;
    }
    if(input % 2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}

int main(){
    solve();
    return 0;
}