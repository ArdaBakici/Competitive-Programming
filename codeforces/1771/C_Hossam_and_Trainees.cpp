#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;

vi primes;

void sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(is_prime[i]){
            for(int x = i*i; x <=n; x+=i){
                is_prime[x] = false;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(is_prime[i]) primes.pb(i);
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n); 
    forn(i, n){
        cin >> a[i];
    }
    multiset<int> in_primes;

    forn(i, n){
        for(int x = 0; x < primes.size() && primes[x] * primes[x] <= a[i]; x++){
            if(!(a[i] % primes[x])){
                in_primes.insert(primes[x]);
                if(in_primes.count(primes[x]) > 1){
                    out("YES");
                    return;
                }
                while(!(a[i] % primes[x]))
                    a[i] /= primes[x];
            }
        }
        if(a[i] != 1) in_primes.insert(a[i]);
        if(in_primes.count(a[i]) > 1){
            out("YES");
            return;
        }
    }
    out("NO");
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(31700);
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
