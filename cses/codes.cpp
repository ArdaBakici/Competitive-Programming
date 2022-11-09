string convert(int size, int num){
    string s;
    int t = 0;
    while(num > 0){
        int ans = num & 1;
        s.pb((char)(ans + '0'));
        num >>= 1;
        t++;
    }
    for(int i=t; i < size ; i++){
        s.pb('0');
    }
    reverse(iter(s));
    return s;
}