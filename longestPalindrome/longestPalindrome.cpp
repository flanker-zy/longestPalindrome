#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            }
            else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            }
            else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                ans = s.substr(i, l + 1);
            }
        }
    }
    return ans;
}


int main()
{
    string s = "ababas";
    cout << "最长回文为：" << longestPalindrome(s) << endl;
    return 0;
}