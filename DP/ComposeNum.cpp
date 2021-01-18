/* CD47 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isValid(const string& express)
{
    int len = express.length();
    if((len%2)==0)
        return false;
    for (int i = 0; i < len;i+=2){
        if(express[i]!='0'&&express[i]!='1')
            return false;
    }
    for (int i = 1; i < len;i+=2){
        if(express[i]!='&'&&express[i]!='|'&&express[i]!='^')
            return false;
    }

    return true;
}
 
int composeNum(const string& express,bool desired)
{
    if(!isValid(express))
    {
        return 0;
    }
    int mod = 1000000007;
    int len = express.length();
    long **t = new long*[len];
    long **f = new long*[len];
    for (int i = 0; i < len; ++i)
    {
        t[i] = new long[len]();
        f[i] = new long[len]();
    }
    for (int i = 0; i < len;++i){
        t[i][i] = express[i] == '1' ? 1 : 0;
        f[i][i] = express[i] == '0' ? 1 : 0;
    }

    for (int i = 2; i < len;i+=2){
        for (int j = i - 2; j >= 0;j-=2){
            for (int k = j; k < i;k+=2){
                char flag = express[k + 1];
                if(flag=='&'){
                    t[j][i] += (t[j][k] * t[k + 2][i])%mod;
                    f[j][i] += ((f[j][k] * (t[k + 2][i] + f[k + 2][i])) % mod + (t[j][k]*f[k+2][i])%mod) % mod;
                }
                else if (flag == '|')
                {
                    t[j][i] += ((t[j][k] * (t[k + 2][i] + f[k + 2][i]))%mod + (f[j][k]*t[k+2][i])%mod)%mod;
                    f[j][i] += (f[j][k] * f[k + 2][i])%mod;
                }
                else
                {
                    t[j][i] += ((t[j][k] * f[k + 2][i])%mod + (f[j][k] * t[k + 2][i])%mod)%mod;
                    f[j][i] += ((t[j][k] * t[k + 2][i])%mod + (f[j][k] * f[k + 2][i])%mod)%mod;
                }
                t[j][i] = t[j][i] % mod;
                f[j][i] = f[j][i] % mod;
            }
        }
    }

    return desired == true ? t[0][len - 1] : f[0][len - 1];
}

int main(int argc, char const *argv[])
{
    string express,desired;
    cin >> express;
    cin >> desired;
    if(desired.compare("true")==0)
        cout << composeNum(express, true) << endl;
    else if(desired.compare("false")==0)
        cout << composeNum(express, false);
    else
        cout << 0 << endl;
    return 0;
}
