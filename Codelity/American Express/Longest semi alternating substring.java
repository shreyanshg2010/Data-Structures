You are given a string s of length n containing only characters a and b. A substring of s called a semi-alternating substring 
if it does not contain three identical consecutive characters. Return the length of the longest semi-alternating substring.

Example 1:

Input: "baaabbabbb"
Output: 7
Explanation: "aabbabb"
Example 2:

Input: "abaaaa"
Output: 4
Explanation: "abaa"




  private int findLongestSemiAlteringSubstring(String str) {
        int len = 0;
        if(str == null) return 0;
        if(str.length() < 3) return str.length();
        for(int i=2,j=0;i<str.length(); ++i) {
            if(str.charAt(i) == str.charAt(i-1) && str.charAt(i) == str.charAt(i-2))
                j = i-1;
            len = Math.max(len, i-j+1);
        }
        return len;
    }
