#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<random>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;
const int M = 1e5 + 50;
int map[26][M];


ll solve_b(string s, string t){
    
	int f = 0;
	long long ans = 0;
  //1. Playing the table
	for(int i = 0; i <26; i++)map[i][s.length()] = -1;//Initialization, -1 means not found from s.length to the right (i+'a')
	for(int i = s.length()-1; i >=0; i-- ){
		for(int j = 0; j <26; j++){
			map[j][i] = map[j][i+1];//Record where the nearest ('a'+j) from i to the right is;
		}
		map[s[i]-'a'][i] = i;//The position of the nearest s[i] from the i-th bit to the right is at i
	}
 
	int flag = 0;//is there
	int wz = 0;//Current position
	for(int i = 0; i <t.length(); i++){
		if(wz == 0 && map[t[i]-'a'][wz] == -1){//If t[i] is not found at the beginning, it means there is no
			flag = 1;
			break;
		}
		else{
			if( map[t[i]-'a'][wz] != -1 ){//If t[i] is found
				ans+=map[t[i]-'a'][wz]-wz+1;//The answer is added to this position
				wz = map[t[i]-'a'][wz]+1;//change the current position to the next match
			}
			else{//If not found, but the current position is not at the beginning, go to the next paragraph s
				ans+=s.length()-wz;//First change the position to the end of the paragraph s
				wz = 0;//The current position becomes the beginning of the next segment s
				i--;//Because t[i] is not matched, t[i] is still matched
			}
		}
	}
	if(flag == 1)
		return -1;
	else{
		return ans;
	}
}

ll solve_a(string s, string t){
    ll cost = 0;
    vector<int> mask[26];
    forn(s_cur, s.length()){
        mask[s[s_cur] - 'a'].em(s_cur+1);
    }
    ll prev_index = -1;
    forn(t_cur, t.length()){
        ll index = -1;
        vector<int> loc_arr = mask[t[t_cur] - 'a'];
        if (loc_arr.size() == 0){
            //cout << -1 << endl;
            return -1;
        }

        if(prev_index == -1){
            index = loc_arr[0];
            cost += index;
        }
        else{
            int passive_index = -1;
            for(int loc_cur = 0; loc_cur < loc_arr.size(); loc_cur++){
                if(loc_arr[loc_cur] > prev_index){
                    index = loc_arr[loc_cur];
                    cost += (index - prev_index);
                    break;
                }
                else{
                    if(passive_index == -1)
                    passive_index = loc_arr[loc_cur]; 
                }
            }
            if (index == -1){
                index = passive_index;
                cost += (s.length() - prev_index + index);    
            }
        }
        prev_index = index;
    }
    //cout << cost << endl;
    return cost;
}

string generateRandomString(int size){
    mt19937 generator{random_device{}()};
   //modify range according to your need "A-Z","a-z" or "0-9" or whatever you need.
    uniform_int_distribution<int> distribution{'a', 'z'};

    auto generate_len = size; //modify length according to your need
    string rand_str(generate_len, '\0');
    for(auto& dis: rand_str)
        dis = distribution(generator);

    return rand_str;
}

int generateRandomNumber(int low_bound, int high_bound){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(low_bound, high_bound); // define the range

    return distr(gen); // generate numbers
}


int main(){
    string s, t;
    ll res_a, res_b;
    printf("Starting Analyzing\n");
    int i = 0;
    while(true){
        int size_a = generateRandomNumber(1, 100000); //100000
        int size_b = generateRandomNumber(1, 100000); //100000
        s = generateRandomString(size_a);
        t = generateRandomString(size_b);
        res_a = solve_a(s, t);
        res_b = solve_b(s, t);
        if(res_a != res_b){
            cout << endl;
            break;
        }
        i++;
        if(i == 10){
            printf(".\n");
            i = 0;
        }
    }
    cout << s << endl;
    cout << t << endl;
    cout << "Mine: " << res_a << endl;
    cout << "Theirs " << res_b << endl;
    return 0;
}

/*
hrvvg
gv
Mine: 9
Theirs: 8

ggu
ug
Mine: 5
Theirs: 4

*/