Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    }     
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.




Keep in mind these things -

1) ‘{‘, ‘[’ have the same effect on the printing

2) ‘}’, ‘]’ have the same effect as well

3) ‘:’ and ‘,’ are the only other 2 characters that matter.

Then after taking care of corner cases code will be  -

vector<string> ChangeInput(string str)
{
    vector<string> result;
    if (str.length() == 0) 
        return result;

    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    string indent = "";
    string curr = "";
    int i = 0, len = str.length();
    
    while (i < len)
    {
        curr.push_back(str[i]);
        switch(str[i])
        {
            case ',':
                result.push_back(curr);
                curr = indent;
                i++;
                break;

            case ':':
                i++;
                if (str[i] == '{' || str[i] == '[')
                {
                    result.push_back(curr);
                    curr = indent;
                }
                break;

            case '{':
            case '[':

                i++;
                result.push_back(curr);
                if (i < len && (str[i] != '}' || str[i] != ']'))
                {
                    indent.push_back('\t');
                }
                curr = indent;
                break;

            case '}':
            case ']':
                i++;
                if (i < len && str[i] == ',') break;
                result.push_back(curr);
                if (i < len && (str[i] == '}' || str[i] == ']'))
                {
                    if (!indent.empty()) indent.pop_back();
                }
                curr = indent;
                break;

            default : 
                i++;
                if (i < len && (str[i] == '}' || str[i] == ']'))
                {
                    result.push_back(curr);
                    if (!indent.empty()) indent.pop_back();
                    curr = indent;
                }
        }
    }
    return result;
}
 
