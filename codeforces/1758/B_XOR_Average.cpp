#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;

    if(n%2){
        while(n--){
            cout << 5 << " ";
        }
        cout << endl;
        return;
    }

    while(n){
        if(n==2){
            cout << 3 << " ";
        }
        else if(n==1){
            cout << 1 << " ";
        }
        else{
            cout << 2 << " ";
        }
        n--;
    }
    cout << endl;
}

int32_t main(){
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
