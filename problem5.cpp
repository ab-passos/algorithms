#include <iostream>

using namespace std;
void permutations(string str, int n, string res)
{
  // base condition (only one character is left in the string)
    if (n == 1)
        cout << res + str << endl;
    else
    {
        // process each character of the remaining string
        for (int i = 0; i < n; i++)
        {
            // push current character to the output string and recuse
            // for the remaining characters
            cout << "substring = " << str.substr(1) << endl;
            permutations(str.substr(1), n - 1, res + str[0]);

            // left rotate the string by 1 unit for next iteration
            // to right rotate the string use reverse iterator
            rotate(str.begin(), str.begin() + 1, str.end());
        }
    }
}
int main()
{
    string str = "XYZ";
    string result;
    permutations(str, str.size(), result);
    return 0;
}
