#include <iostream>
#include <vector>

void merges(std::vector<int>& arr, std::vector<int>& buf, int l, int r){
    if(l < r){
        int mid = l/2 + r/2;
        merges(arr,buf, l, mid);
        merges(arr,buf,mid+1, r);

        int leftIndex = l, rightIndex = mid+1, bufIndex = 0;
        while(leftIndex <= mid && rightIndex <= r){
            if(arr[leftIndex] <= arr[rightIndex]){
                buf[bufIndex++] = arr[leftIndex++];
            }else{
                buf[bufIndex++] = arr[rightIndex++];
            }
        }
        while(leftIndex <= mid){
            buf[bufIndex++] = arr[leftIndex++];
        }
        while(rightIndex <= r){
            buf[bufIndex++] = arr[rightIndex++];
        }

        for(int i = 0; i < bufIndex; ++i){
            arr[l++] = buf[i];
        }
    }
}

void mergeSort(std::vector<int>& arr){//including r
    std::vector<int> buf(arr.size());
    merges(arr,buf, 0, arr.size()-1);
}


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
    mergeSort(arr);
    //
    for(int i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << ' ';
    }

    return 0;
}