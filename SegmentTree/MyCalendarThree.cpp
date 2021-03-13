// Leetcode 732
#include <algorithm>
#include <stdio.h>
using namespace std;

// 解法1
class SegTree {
    using SegTreeNode = SegTree;
    int startTime, endTime;
    int maxCount;
    int delayCount;
    SegTreeNode *left, *right;

public:
    SegTree(int start, int end)
        : startTime(start)
        , endTime(end)
        , maxCount(0)
        , delayCount(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    inline int getMid(){
        return startTime+(endTime-startTime)/2;
    }
    SegTreeNode* leftChild(){
        if(left==nullptr){
            left=new SegTreeNode(startTime,getMid());
        }
        return left;
    }
    SegTreeNode* rightChild(){
        if(right==nullptr){
            right=new SegTreeNode(getMid(),endTime);
        }
        return right;
    }
    int insert(int start,int end){
        if(start<=startTime && end>=endTime){
            ++maxCount;
            ++delayCount;
        }else if(!(endTime<=start || startTime>=end)){
            leftChild()->maxCount+=delayCount;
            leftChild()->delayCount+=delayCount;
            rightChild()->maxCount+=delayCount;
            rightChild()->delayCount+=delayCount;
            delayCount=0;
            maxCount=max({maxCount, left->insert(start, end), right->insert(start, end)});
        }
        return maxCount;
    }
};

class MyCalendarThree {
    SegTree* segtree;
public:
    MyCalendarThree()
    {
        segtree=new SegTree(0,1e9);
    }

    int book(int start, int end)
    {
        return segtree->insert(start, end);
    }
};

int main(void)
{
    return 0;
}
