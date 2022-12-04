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
    vi arr;
    int max_a = 0;
    int max_b = 0;

    forn(i, n){
        int input;
        cin >> input;
        if(input >= max_a){
            max_b = max_a;
            max_a = input;
        }
        else if(input > max_b){
            max_b = input;
        }
        arr.pb(input);
    }
    
    for(auto x:arr){
        if(x==max_a){
            cout << (x-max_b) << " ";
        }
        else{
            cout << (x-max_a) << " ";
        }
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
