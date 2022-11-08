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
    int n;
    cin >> n;
    vector<double> people;
    vector<double> dress;
    forn(i, n){
        int input;
        cin >> input;
        people.pb(input);
    }
    forn(i, n){
        int input;
        cin >> input;
        dress.pb(input);
    }

    while(n != 1){
        forn(i, ceil(n/2)){
            if(i == (n-1-i)){
                break;
            }
            double res = abs(dress[i] - dress[n-1-i]);

            if(res > abs(people[i] - people[n-1-i])){
                if(dress[i] > dress[n-1-i]){
                }
                else{
                    people[i] = people[n-1-i];
                    dress[i] = dress[n-1-i];
                }
            }
            else{
                if(people[i] == people[n-i-1]){
                    dress[i] = max(dress[i], dress[n-1-i]);
                    continue;
                }
                if(dress[i] > dress[n-1-i]){
                    if(people[i] > people[n-i-1]){
                        people[i] = ((double)res + (double)people[i] + (double)people[n-1-i])/2;        
                    }
                    else{
                        people[i] = (((double)res*-1) + (double)people[i] + (double)people[n-1-i])/2;
                    }
                }
                else{
                    if(people[i] < people[n-i-1]){
                        people[i] = ((double)res + (double)people[i] + (double)people[n-1-i])/2;        
                    }
                    else{
                        people[i] = (((double)res*-1) + (double)people[i] + (double)people[n-1-i])/2;
                    }
                }
                dress[i] = dress[n-1-i] + abs(people[i] - people[n-i-1]);
            }
        }
        n = ceil((float)n/2);
    }
    
    cout << people[0] << endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(8);
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