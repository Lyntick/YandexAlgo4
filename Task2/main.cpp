#include <iostream>
#include <vector>
#include <random>
#include <fstream>


std::default_random_engine generator;

void quickSort(std::vector<int>& buf, int l, int r){// r = N - 1
    if(l < r){
        std::uniform_int_distribution<int> distribution(l,r);
        int mid = distribution(generator);
        int supElem = buf[mid];

        int less = l, equal = l, bigger = l;
        do{
            int temp = buf[bigger];
            if(temp < supElem){
                buf[bigger] = buf[equal];
                buf[equal] = buf[less];
                buf[less] = temp;
                ++equal;
                ++less;
            }else if(temp == supElem) {
                std::swap(buf[bigger], buf[equal]);
                ++equal;
            }
            ++bigger;
        }while(bigger <= r);

        quickSort(buf, l,less);
        quickSort(buf,equal, r);
    }
}


int main() {
    std::ios::sync_with_stdio(false);//switch off sync between C++ and C print
    std::cin.tie(0);//отключает сброс буфеера пере вызовом cout

    std::vector<int> buf;
    int N = -1;

//        std::cin >> N;
//        buf.reserve(N);
//        for(int i = 0; i < N; ++i) {
//            std::cin >> buf[i];
//        }

//    //Solution
//    quickSort(buf, 0, N);
//    //
//    for(int i = 0; i < N; ++i){
//        std::cout << buf[i] << ' ';
//    }

//    N = 4000000;
//    srand(time(0));
//    for(int i = 0; i < N; ++i){
//        auto temp = rand() % 10000000;
//        buf.push_back(temp);
//    }
//    std::cout << '\n';
//

    auto start = std::chrono::steady_clock::now();
    quickSort(buf,0, N);
//    std::sort(buf.begin(),buf.end());
    auto end = std::chrono::steady_clock::now();
    std::cout << "work time:" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    for(int i =0; i < N-1; ++i){
        if(buf[i] > buf[i+1]){
            std::cout << "\nfalse\n";
            break;
        }
    }

    return 0;
}