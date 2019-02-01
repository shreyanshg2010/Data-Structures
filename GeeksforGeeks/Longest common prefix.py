Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.




def longestCommonPrefix(A):
        a = min(A)
        b = max(A)
        counter = 0
        for i in range(min(len(a), len(b))):
            if a[i] == b[i]: counter += 1
            else: break
        return a[:counter]
        
n = int(input())
arr = []
for _ in range(n):
    x = input()
    arr.append(x)  
print(longestCommonPrefix(arr))
