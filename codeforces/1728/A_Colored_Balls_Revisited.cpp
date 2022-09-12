#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int num_of_colors;
    cin >> num_of_colors;
    //int colors[num_of_colors];
    int biggest_value = 0;
    int index;
    forn(i, num_of_colors){
        int input;
        cin >> input;
        if (input > biggest_value){
            index = i;
            biggest_value = input;
        }
        //colors[i] = input;
    }

    cout << index+1 << endl;
    return;
}

int main(){
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}