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
    ll n, m;
    cin >> n >> m;
    vector<ll> cap(n);
    ll prev_value = 0;
    forn(i, n){
        ll input;
        cin >> input;
        cap[i] = (m - input) + prev_value;
        prev_value = input;
    }

    /*for(auto x:cap){
        cout << x << " ";
    }*/

    int moves = 0;
    int total_cap = 0;
    forn(i, n){
        if(cap[i] < 0){
            if(i == n-1){
                moves++;
                break;
            }
            if(cap[i-1] > -1*cap[i] && i != 0){
                moves++;
                cap[i-1] += cap[i];
                cap[i] = 0;
            }
            else if(cap[i+1] > -1*cap[i]){
                moves++;
                cap[i+1] += cap[i];
                cap[i] = 0;
            }
            else if(cap[i+1] + cap[i-1] > -1*cap[i] && i!=0){
                moves++;
                cap[i] += cap[i-1];
                cap[i-1] = 0;
                cap[i+1] += cap[i];
                cap[i] = 0;
            }
            else{
                //int tmp_moves_a = 0;
                for(int x=i+1; x < n && cap[x-1]<0; x++){
                    //tmp_moves_a++;
                    moves++;
                    cap[x] += cap[x-1];
                    cap[x-1] = 0;
                }
                /*int tmp_moves_b = 0;
                for(int x=i-1; x >= 0 && cap[i]<0; x--){
                    tmp_moves_b++;
                    if(cap[x] > 0){
                        if(-1*cap[i] > cap[x]){
                            cap[i] += cap[x];
                            cap[x] = 0;
                        }
                        else{
                            cap[x] += cap[i];
                            cap[i] = 0;
                            break;
                        }
                    }
                }*/
            }
        }

        total_cap += cap[i];
    }

    cout << moves << endl;
}

int main(){
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