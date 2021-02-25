// Leetcode
/* #include <algorithm> */
#include <stdio.h>
/* #include <vector> */
/* using namespace std; */

class A {
public:
    A(int i)
    {
        printf("Default\n");
    }
    A(const A& other)
    {
        printf("Left Value\n");
    }
    A(A&& other)
    {
        printf("Right Value\n");
    }
};

int main(int argc, char* argv[])
{
    A a=A(A(1));
    return 0;
}
