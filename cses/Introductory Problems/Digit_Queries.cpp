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
#define vi vector<int>
using namespace std;

void solve(){
    int q;
    cin >> q;
    forn(i, q){
        int k;
        int multi = 9;
        int lw = 0;
        int plw = 0;
        int index = 0;
        int rem = 0;
        cin >> k;
        while(k > lw){
            index++;
            plw = lw;
            lw += multi*index;
            multi *= 10;
        }
        k -= plw;
        rem = k % index ? index-k%index : k % index;
        k += rem;
        k /= index;
        int value = pow(10, index-1);
        value--; 
        k += value;
        forn(z, rem){
            k /= 10;
        }
        out(k%10);
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