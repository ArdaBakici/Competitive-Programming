#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    if((x == 0 && y == 0) || x-y == 0){
        cout << -1 << endl;
        return;
    }
    float k = (float)((n-1) - (n*y)) / (x-y);
    //cout << "k is" << k << " " << endl;
    if(k > (n-1) || k < 0 || (int)k != k){
        cout << -1 << endl;
        return;
    }
    
    // k times x n-k times y

    int player = 2;
    int player_w = 1;
    forn(i, k){
        forn(theta, x){
            cout << player_w << " ";
            player++;
        }
        player_w = player;
        //player++;
    }

    forn(i, (n-k)){
        forn(theta, y){
            cout << player_w << " ";
            player++;
        }
        player_w = player;
        //player++;
    }
    cout << endl;
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