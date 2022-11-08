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
    int a, b;
    cin >> a >> b;

    if(b <= a){
        cout << a-b << endl;
        return;
    }

    int ans = INT_MAX;
    int gamma = b % a;
    int m = b/a;
    int y = 0;

    if(m == 0){
        ans = min(b-a, a-(b%a));
    }
    else{
        for(int i = 0; i+a <= b && i < ans && i < 2*a; i++){
            y = ((m*i) - gamma) % (a+i);
            y = (y<0) ? (a+i) + y : y;

            ans = min(ans, i+y);
            if(y == 0){
                break;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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