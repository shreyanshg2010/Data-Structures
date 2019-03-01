Your task is to design a contacts application that supports two features :

add name where name is a string that denotes the name of the contact. This operation must store a new contact by the name name.

find partial where partial is a string denoting a part of the name to search for in the directory. It must count the number of contacts that start with partial and print the count.

You are given n sequential operations of either type 1 or type 2. You are expected to perform them in the order given.

Input Format

The first line contains a single integer, n , denoting the number of operations to perform. Each line i of the n subsequent lines contains an operation in one of the two forms defined above.

Constraints

1 <= n <= 105
1 <= |name|, |partial| <= 21
It is guaranteed that name and partial contain lowercase english letters only.
Output Format

For each find partial operation, print the number of contact names starting with partial on a new line.

Sample Input 0

4
add hack
add hackerrank
find hac
find hak
Sample Output 0

2
0



#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// Map of all Substrings of the input string
std::map<string, long int> contactsMap;

void addContacts(string contactName){
  for (size_t i = 1; i <= contactName.size(); i++) {
    std::string subStr = contactName.substr(0,i);
    if (contactsMap.find(subStr) != contactsMap.end() ) { // Existing Entry
      contactsMap[subStr]+=1;
    }
    else{
      contactsMap[subStr]=1; // New Entry
    }
  }
}

long int extractContacts(string contactName){
  if (contactsMap.find(contactName) != contactsMap.end()) { //Entry Found
    std::map<string, long int>:: iterator contactsIter  = contactsMap.find(contactName);
    return contactsIter->second;
  }
  else{
    return 0; // No Entry Found
  }
}

int main() {

  long int querySize;
  std::cin >> querySize;
  for (size_t i = 0; i < querySize; i++) {
    string opName,inputString;
    std::cin >> opName>>inputString;
    if (opName=="add") {
      addContacts(inputString);
    }
    else if(opName=="find"){
    std::cout <<  extractContacts(inputString) << '\n';
    }
  }
    return 0;
}
