#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int n;
    cin >> n;
    
    if (n > 6 && n%3==0){
        cout << "3 1 2 ";
        for(int i = 4; i < n-3; i++){
            cout << i << " ";
        }
        cout << n-2 << " " << n-3 << " " << n-1 << " " << n << endl;
        return;
    }    
    for(int i = 1; i < n-3; i++){
        cout << i << " ";
    }
    cout << n-2 << " " << n-3 << " " << n-1 << " " << n << endl;
}

int main(){
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}

/*

1 2 3 4 5 6 7 8 9
3 1 2 4 5 7 6 8 9
  x     x    


1 2 3 4 5 6 7 8 9 10 11 12
3 1 2 4 5 6 7 8 10 9 11 12
3 0 2 6 0 6 14 0 10 0
*/