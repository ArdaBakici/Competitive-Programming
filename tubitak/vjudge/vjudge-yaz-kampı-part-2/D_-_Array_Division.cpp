#include <iostream>
#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define ll long long int

using namespace std;

void solve();

int main(){
    solve();
}


void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr;
    ll ans = -1;
    ll max_value = 0;
    ll total = 0;
    forn(i, n){
        ll input;
        cin >> input;
        total += input;
        max_value = max(max_value, input);
        arr.push_back(input);
    }

    ll l = max_value, r = total;

    while(l<=r && r >= l){
        ll mid = l + (r - l) / 2;
        ll sum = 0, sub_arrays = 1;
        bool flag = false;
        for(ll index : arr){
            if (flag) sub_arrays++, flag=false;
            if(sum + index > mid){
                sub_arrays++;
                sum = index; 
            }
            else if(sum + index == mid){
                flag=true;
                sum = 0;
            }
            else{
                sum += index;
            }
        }

        if(sub_arrays <= k){
            if (ans == -1){
                ans = mid;
            }
            else{
                ans = min(mid, ans);
            }
            
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << endl;
}