Problem Statement :

Given word and dictionary of words, search the word in dictionary such that, more than one occurances can be skipped while matching.

Examples below :

example 1 :

word = "lleeetttcooodddee"
dictionary = ["letcode", "leettccf", "lleetcode", "leetcod"]

output : true






#include <bits/stdc++.h> 
using namespace std;

string wordInDictionary(string word, vector<string>& dict) {
    for(string s : dict) {
        if(word[0] != s[0]) continue;
        int j = 1;
        bool equal = true;
        for(int i = 1; i < word.size(); i++) {
            if(word[i] != s[j]) {
                if(word[i] != word[i - 1]) break;
            }
            if(word[i] == s[j]) {
                j++;
            }
            if(j == s.size()) { // if string found check rest part of word
                                // if it's equal we can skip it
                for(int z = i + 1; z < word.size(); z++) {
                    if(word[z] != word[z - 1]) {
                        equal = false;
                        break;
                    }
                }
                break;
            }
        }
        if(j == s.size() && equal) return s;
    }
    return "";
}

int main() {
    string word = "lleeetttcooodddee";
    vector<string> dict = {"letcode", "leettccf", "lleetcode", "leetcod"};
    cout << wordInDictionary(word, dict);

	return 0;
}
