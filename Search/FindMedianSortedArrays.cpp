#include <vector>
#include <algorithm>
using namespace std;

int getKthNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    int index1, index2;
    index1 = index2 = 0;
    while (true)
    {
        if(index1>=len1){
            return nums2[index2 + k - 1];
        }
        if(index2>=len2){
            return nums1[index1 + k - 1];
        }
        if(k==1){
            return min(nums1[index1], nums2[index2]);
        }

        int nidx1 = min(index1 + k / 2 - 1, len1 - 1);
        int nidx2 = min(index2 + k / 2 - 1, len2 - 1);

        if(nums1[nidx1]<=nums2[nidx2]){
            k -= nidx1 - index1 + 1;
            index1 = nidx1 + 1;
            
        }
        else
        {
            k -= nidx2 - index2 + 1;
            index2 = nidx2 + 1;    
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    int len = len1 + len2;
    if (len % 2 == 0)
    {
        return (getKthNumber(nums1, nums2, len / 2 ) + getKthNumber(nums1, nums2, len / 2 + 1)) / 2.0;
    }else{
        return getKthNumber(nums1, nums2, len / 2 + 1);
    }
}