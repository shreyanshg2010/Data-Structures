map<char, int> vals = { {'I', 1}, 
                        {'V', 5}, 
                        {'X', 10}, 
                        {'L', 50}, 
                        {'C', 100}, 
                        {'D', 500}, 
                        {'M', 1000}
                    };


vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}


int romanToInt(string s){
    int res = vals[s[s.size() - 1]];
    for (int i = s.size() - 2; i >= 0; i--) {
        if (vals[s[i]] < vals[s[i+1]])
            res -= vals[s[i]];
        else
            res += vals[s[i]];
    }
    return res;
}

bool comp(string a, string b) {
    vector<string> s1 = split(a, ' ');
    vector<string> s2 = split(b, ' ');
    for (auto s: s1)
        cout << s << endl;
    if (s1[0] < s2[0]) return true;
    if (s1[0] == s2[0] and romanToInt(s1[1]) <= romanToInt(s2[1]))
        return true;
    return false;   

}


vector<string> numeral(vector<string> names){
sort(names.begin(),names.end(),comp);
return names;}


