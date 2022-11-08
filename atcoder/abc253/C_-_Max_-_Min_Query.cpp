    #include <iostream>
    #include <bits/stdc++.h>
    #define ll long long
    #define int ll
    #define forn(i, n) for(int i = 0; i < n; i++)
    #define em emplace_back
    #define iter(i) i.begin(),i.end()
    #define pb push_back
    #define endl "\n"
    #define out(x) cout<<x<<endl
     
    using namespace std;
     
    void solve(){
        int q;
        cin >> q;
        multiset<int> s;
        forn(i, q){
            int input;
            int x, c, minima;
            multiset<int>::iterator it;
            cin >> input;
            switch (input)
            {
            case 1: //O(logn)
                cin >> x;
                s.insert(x);
                break;
            case 2: //O(logn)
                cin >> x >> c;
                it = s.find(x);
                forn(f, c){
                    if(*it != x){
                        break;
                    }
                    s.erase(it++);    
                }
                break;
            case 3: // O(1)
                out(*(--s.cend()) - *s.cbegin());
                break;
            }
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