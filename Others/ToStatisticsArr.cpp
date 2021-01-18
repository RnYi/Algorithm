/* CD67 */
#include <iostream>
#include <algorithm>
using namespace std;

void toDistanceArr(int* arr,int n)
{
    int cap;
    for (int i = 0; i < n; ++i)
    {
        if(arr[i]==i){
            cap = i;
        }else if(arr[i]>=0){
            int cur = arr[i];
            arr[i] = -1;
            int prev, next;
            prev = i;
            while (arr[cur]!=cur&&arr[cur]>=0){
                next = arr[cur];
                arr[cur] = prev;
                prev = cur;
                cur = next;
            }
            int dis = arr[cur] == cur ? 0 : arr[cur];
            cur = prev;
            arr[i] = -1;
            while (arr[cur]!=-1){
                --dis;
                prev = arr[cur];
                arr[cur] = dis;
                cur = prev;
            }
            arr[cur] = --dis;
            
        }
    }
    arr[cap] = 0;
}

void toStatisticsArr(int* arr,int n)
{
    for (int i = 0; i < n; ++i)
    {
        int index = arr[i];
        if (index < 0)
        {
            index = -index;
            arr[i] = 0;
            while(true){
                if(arr[index]>=0){
                    ++arr[index];
                    break;
                }else{
                    int next = -arr[index];
                    arr[index] = 1;
                    index = next;
                }
            }
        }
    }
    arr[0] = 1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n;++i)
    {
        cin >> arr[i];
    }
    toDistanceArr(arr, n);
    toStatisticsArr(arr, n);
    for (int i = 0; i < n;++i)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
