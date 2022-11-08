#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

//complexity O(n(logn)^2)
void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    //take
    forn(i, n){
        int input;
        cin >> arr[i];
    }

    bool flag = true;
    int lower = 0;
    int upper = n;
    pair<int,int> lowest = {0, INT_MAX};
    int prev_mid = -1;
    while(flag){ // O(logn)
        vector<ll> cost_arr(n);
        int cost;
        int num;
        int mid = lower + ((upper-lower)/2);
        if(mid == prev_mid || lower > upper || upper < lower){
            break;
        }
        // calculate O(n)
        forn(i, n){
            cost_arr[i] = arr[i] + mid * (i+1);
        }
        //sort O(nlogn)
        sort(cost_arr.begin(), cost_arr.end());
        //prefix O(n)
        forn(i, mid){
            if (i != 0){
                cost_arr[i] += cost_arr[i-1];
                if(cost_arr[i] < 0 || cost_arr[i] > s){
                    cost_arr[mid-1] = INT_MAX;
                    break;
                }
            } 
        }

        cost = mid == 0 ? 0 : cost_arr[mid-1];

        if(cost > s){
            upper = mid-1;
        }
        else if(cost <= s){
            if(mid > lowest.first){
                lowest.first = mid;
                lowest.second = cost;
            }
            else if(mid == lowest.first){
                if (cost < lowest.second){
                    lowest.second = cost;
                }
            }
            lower = mid+1;
        }
        prev_mid = mid;
    }
    cout << lowest.first << " " << lowest.second << endl;
}

int main(){
    solve();
    return 0;
}