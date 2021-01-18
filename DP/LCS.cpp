/* leetcode1143 */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int longestCommonSubsequence_promte(string text1, string text2)
{
    int len1 = text1.length();
    int len2 = text2.length();
    int *dp = new int [len2 + 1]();

    //dp[i][j] = max(dp[i-1][j],dp[i][j-1]),    str1[i]!=str2[j]
    //         = dp[i-1][j-1]+1,    str1[i]==str2[j]

    for (int i = 1; i <= len1;++i){
        int dp_i_1_j_1 = dp[0];
        for (int j = 1; j <= len2; ++j)
        {
            int tmp = dp[j];
            if (text1[i - 1] == text2[j - 1])
            {
                dp[j] = dp_i_1_j_1 + 1;
            }
            else
            {
                dp[j] = max(dp[j], dp[j - 1]);
            }

            dp_i_1_j_1 = tmp;
        }
    }
    int result = dp[len2];
    delete[] dp;
    return result;
}


int longestCommonSubsequence(string text1, string text2)
{
    int len1 = text1.length();
    int len2 = text2.length();
    int **dp = new int *[len1 + 1];
    for(int i=0;i<=len1;++i){
        dp[i] = new int[len2+1]();
    }

    //dp[i][j] = max(dp[i-1][j],dp[i][j-1]),    str1[i]!=str2[j]
    //         = dp[i-1][j-1]+1,    str1[i]==str2[j]

    for (int i = 1; i <= len1;++i){
        for (int j = 1; j <= len2;++j){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = dp[len1][len2];
    for(int i=0;i<=len1;++i){
        delete[] dp[i];
    }
    delete[] dp;
    return result;
}

int main(int argc, char const *argv[])
{
    return 0;
}
