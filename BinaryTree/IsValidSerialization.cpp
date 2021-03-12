// Leetcode 331
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

bool isValidSerialization(string preorder)
{
    auto len=preorder.length();
    size_t index=0;
    int diff=1;
    while(index<len){
        char ch=preorder[index++];
        if(ch==','){
            continue;
        }
        --diff;
        if(diff<0){
            return false;
        }
        if(ch!='#'){
            diff+=2;
            while(index<len && preorder[index]!=','){
                ++index;
            }
        }
    }
    return diff==0;
} 

int main(void)
{
    string preorder="9,#,#,1";
    printf("%d",isValidSerialization(preorder));
    return 0;
}
