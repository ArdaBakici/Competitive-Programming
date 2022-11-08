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
    int x, y, z;
    cin >> x >> y >> z;



    if(x>0){
        if(y<0 || x<y){
            cout << x << endl;
            return;
        }
        if(z<0){
            cout << (-2*z) + x << endl;
            return;
        }
        if(z < y){
            cout << x << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    else{
        if(y>0 || y < x){
            cout << -1*x << endl;
            return;
        }
        if(z>0){
            cout << (2*z) + (-1*x) << endl;
            return;
        }
        if(z > y){
            cout << -1*x << endl;
            return;
        }
        cout << -1 << endl;
        return;
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