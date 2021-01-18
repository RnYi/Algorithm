/* Leetcode72 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minDistance_promote(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    int *dp = new int[len2+1];
    for (int i = 0; i <= len2;++i){
        dp[i] = i;
    }


    for (int i = 1; i <= len1; ++i)
    {
        int dp_i_1_j_1 = dp[0];
        dp[0] = i;//相当于dp[i][j-1]
        for (int j = 1; j <= len2; ++j)
        {
            int tmp = dp[j];
            if (word1[i - 1] == word2[j - 1])
            {
                dp[j] = dp_i_1_j_1;
            }
            else
            {
                //dp[i][j]=min(dp[i-1][j-1],
                //             dp[i-1][j],
                //             dp[i][j-1])
                dp[j] = min({dp_i_1_j_1, dp[j], dp[j - 1]}) + 1;
            }
            dp_i_1_j_1 = tmp;
        }
    }

    return dp[len2];
}

int minDistance(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    int **dp = new int *[len1+1];
    for (int i = 0; i <= len1;++i){
        dp[i] = new int[len2+1];
    }

    for (int i = 0; i <= len1; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2;++j){
        dp[0][j] = j;
    }

    for (int i = 1; i <= len1;++i){
        for (int j = 1; j <= len2;++j){
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min({dp[i - 1][j - 1],
                               dp[i][j - 1],
                               dp[i - 1][j]}) +
                           1;
            }
        }
    }

    return dp[len1][len2];
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
