#include <iostream>
#include <vector>



int main(){
    std::ios::sync_with_stdio(false);//switch off sync between C++ and C print
    std::cin.tie(0);//отключает сброс буфеера пере вызовом cout


    std::vector<int> arr1;
    std::vector<int> arr2;
    int size1 = -1, size2 = -1;

    std::cin >> size1;
    arr1.reserve(size1);
    for(int i = 0; i < size1; ++i){
        int temp = 0;
        std::cin >> temp;
        arr1.push_back(temp);
    }

    std::cin >> size2;
    arr2.reserve(size2);
    for(int i = 0; i < size2; ++i){
        int temp = 0;
        std::cin >> temp;
        arr2.push_back(temp);
    }

    //solution
    std::vector<int> result;
    result.reserve(size1 + size2);
    int iter1 = 0, iter2 = 0;
    while(iter1 < size1 && iter2 < size2){
        if(arr1[iter1] <= arr2[iter2]){
            result.push_back(arr1[iter1++]);
        }else{
            result.push_back(arr2[iter2++]);
        }
    }
    while(iter1 < size1){
        result.push_back(arr1[iter1++]);
    }
    while(iter2 < size2) {
        result.push_back(arr2[iter2++]);
    }
    //
    for(int i = 0; i < result.size(); ++i){
        std::cout << result[i] << ' ';
    }

    return 0;
}