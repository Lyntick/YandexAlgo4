#include <iostream>
#include <vector>


int main() {
    std::ios::sync_with_stdio(false);//switch off sync between C++ and C print
    std::cin.tie(0);//отключает сброс буфеера пере вызовом cout

    std::vector<int> buf;
    int N;
    int supElem;

        std::cin >> N;
        buf.reserve(N);
        for(int i = 0; i < N; ++i){
            std::cin >> buf[i];
        }
        std::cin >> supElem;

    //Solution
    if(N <= 0){
        std::cout << 0 << '\n' << 0;
        return 0;
    }

    int less = 0, equal = 0, bigger = 0;
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
    }while(bigger < N);
    //
    std::cout << less << '\n' << N-less;


    return 0;
}