#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl
using namespace std;
    
void solve(){
    int n;
    cin >> n;
    int tmp = pow(2, n);
    vector<bool> arr(n, false);

    fornn(i, tmp){
        //print
        for(int x = n-1; x>=0 ; x--){
            cout << arr[x];
        }
        cout << endl;

        forn(x, n){
            int cur = pow(2, x+1);
            if(!( (i-(cur/2)) % cur )){
                arr[x] = !arr[x];
            }
        }
    }
}
    
int32_t main(){
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