#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1,2,3,4,5};
    for(auto& num : vec){
        num=(num%2==0)?num:num*2;
    }
    for(auto& num : vec){
        std::cout<<num<<' ';
    }
    return 0;
}
