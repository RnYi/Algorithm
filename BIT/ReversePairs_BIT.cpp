#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class BIT {
    int count;
    vector<int> tree;

public:
    BIT(int n)
        : count(n)
        , tree(n + 1, 0)
    {
    }
    static int lowbit(int num)
    {
        return num & (-num);
    }

    int sum(int index)
    {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= lowbit(index);
        }
        return result;
    }

    void add(int index, int num)
    {
        while (index <= count) {
            tree[index] += num;
            index += lowbit(index);
        }
    }
};

int reversePairs(vector<int>& nums)
{
    int len = nums.size();
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    for (auto& num : nums) {
        num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
    }

    int rtv = 0;
    BIT bit_tree(len);
    for (int i = len - 1; i >= 0; --i) {
        rtv += bit_tree.sum(nums[i] - 1);
        bit_tree.add(nums[i], 1);
    }
    return rtv;
}

int main()
{
    return 0;
}
