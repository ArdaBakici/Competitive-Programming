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
    int n, m, k;
    cin >> n >> m >> k;
    if(k >(floor(n/2)*floor(m/2))){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int last_k = 0;
    vector<int> k_arr(floor(m/2));

    forn(i, n){
        forn(x, m){
            if(i%2){
                if(m%2 && x == (m-1)){
                    cout << k_arr[floor(x/2)-1] << " "; 
                }
                else{
                    cout << k_arr[floor(x/2)] << " ";

                }
            }
            else{
                if(!(x%2)){
                    if(m%2 && x == (m-1)){
                    }
                    else if(last_k<k){
                        last_k++;
                        k_arr[x/2] = last_k;
                    }
                    else{
                        k_arr[x/2] = last_k;
                    }
                }
                
                cout << last_k << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}