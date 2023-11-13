#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);//switch off sync between C++ and C print
    std::cin.tie(0);//отключает сброс буфеера пере вызовом cout


    std::vector<int> arr;
    int size = -1;

    std::cin >> size;
    arr.reserve(size);
    for(int i = 0; i < size; ++i){
        int temp = 0;
        std::cin >> temp;
        arr.push_back(temp);
    }

    //solution

    //
    for(int i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << ' ';
    }

    return 0;
}