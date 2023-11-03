#include <iostream>
#include <vector>

void quickSort(std::vector<int>& buf, int l, int r){
    if(l < r){
        //partition
        int mid = l/2 + r/2;
        int supElem = buf[mid];
        while(buf[l] < supElem){++l;}
        while(supElem < buf[r]){--r;}
        if(l >= r){
            return;
        }
        std::swap(buf[l], buf[mid]);// move supElem at the beginning
        //Solution
        int less = l, equal = l+1, bigger = l+1;
        do{
            int tempBig = buf[bigger];
            if(tempBig < supElem){
                buf[bigger] = buf[equal];
                buf[equal] = buf[less];
                buf[less] = tempBig;
                ++equal;
                ++less;
            }else if(tempBig == supElem){
                std::swap(buf[bigger], buf[equal]);
                ++equal;
            }
            ++bigger;
        }while(bigger < r);
        //
        quickSort(buf, l,less-1);
        quickSort(buf,equal, r);
    }
}


int main() {
    std::ios::sync_with_stdio(false);//switch off sync between C++ and C print
    std::cin.tie(0);//отключает сброс буфеера пере вызовом cout

    std::vector<int> buf;
    int N = -1;

        std::cin >> N;
        buf.reserve(N);
        for(int i = 0; i < N; ++i) {
            std::cin >> buf[i];
        }
    //Solution
    quickSort(buf, 0, N);
    //
    for(int i = 0; i < N; ++i){
        std::cout << buf[i] << ' ';
    }


    return 0;
}