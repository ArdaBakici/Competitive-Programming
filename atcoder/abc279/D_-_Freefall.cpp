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
    int a, b;
    cin >> a >> b;

    long double ans = cbrtl(((a/(2*b))*(a/(2*b))))-1;
    (a/sqrtl(ans+1)) + (b*ans);
    if(ans > 0){
        printf("%.10Lf", ans);
    }
    else{
        printf("%.10Lf", a);
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(11);
    solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
