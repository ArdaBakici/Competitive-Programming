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
    int input;
    vector<bool> arr(3, false);
    forn(i, 2){
        cin >> input;
        switch (input)
        {
        case 1:
            arr[0] = true;
            break;
        case 2:
            arr[1] = true;
            break;
        case 4:
            arr[2] = true;
            break;
        case 3:
            arr[0] = true;
            arr[1] = true;
            break;
        case 5:
            arr[0] = true;
            arr[2] = true;
            break;
        case 6:
            arr[1] = true;
            arr[2] = true;
            break;
        case 7:
            arr[0] = true;
            arr[1] = true;
            arr[2] = true;
            break;
        }
    }
    int ans = 0;
    forn(i,3){
        if(arr[i]){
            switch (i)
            {
            case 0:
                ans+=1;
                break;
            case 1:
                ans+=2;
                break;
            case 2:
                ans+=4;
                break;
            default:
                break;
            }
        }
    }
    cout << ans << endl;
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