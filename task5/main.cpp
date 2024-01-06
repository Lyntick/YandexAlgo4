#include <iostream>
#include <vector>
#include <array>

//todo change consept of working with interger number to string, because have limitation in integer type
int main(){
    std::ios::sync_with_stdio(false);//switch off sync between C++ and C print
    std::cin.tie(0);//отключает сброс буфеера пере вызовом cout


    std::vector<int> arr;
    int size = -1;

    std::cin >> size;
    arr.reserve(size);
    std::cout << "Initial array:\n";
    for(int i = 0; i < size; ++i){
        int temp;
        std::cin >> temp;
        arr.push_back(temp);
        std::cout << temp;
        if(i < size - 1)
            std::cout << ", ";
    }

    std::cout << "\n**********\n";
    //solution


    std::array<std::vector<int>,10> buffer{};
    auto print = [&buffer](){
        for(int i = 0; i < buffer.size(); ++i){
            std::cout << "Bucket " << i << ": ";
            if(buffer[i].empty()){
                std::cout << "empty";
            }
            else{
                for(int j = 0; j  <  buffer[i].size(); ++j){
                    std::cout << buffer[i][j];
                    if(j < buffer[i].size()-1)
                        std::cout << ", ";
                }
            }
            std::cout << '\n';
        }
        std::cout << "**********\n";
    };

    auto lastRadix = [](int num, int rad){
        int theRad = -1;
        for(int i = 0; i < rad; ++i){
            num /= 10;
        }
        theRad = num % 10;
        return theRad;
    };

    auto numberOfDigits = [](int num){
        int digits = 0;
        while(num > 0){
            num/= 10;
            ++digits;
        }
        return digits;
    };


    std::cout << "Phase " << 1 << '\n';
    for(int i : arr){
        int temp = lastRadix(i, 0);
        buffer[temp].push_back(i);
    }
    print();

    int digits = numberOfDigits(arr[0]);
    for(int phase = 1; phase < digits; ++phase){
        std::cout << "Phase " << phase+1 << '\n';
        //todo count sort, thing how to take items from buffer and process them
        std::array<std::vector<int>,10> bufferTemp{};
        for(int i = 0; i < buffer.size(); ++i){
            for(int j = 0; j < buffer[i].size(); ++j){
                int temp = lastRadix(buffer[i][j], phase);
                bufferTemp[temp].push_back(buffer[i][j]);
            }
        }
        buffer = bufferTemp;
        print();
    }

    for(int i = 0, arrIter = 0; i < buffer.size(); ++i){
        for(int j = 0; j <buffer[i].size(); ++j){
            if(buffer[i].empty()){
                continue;
            }
            arr[arrIter++] = buffer[i][j];
        }
    }

    //
    std::cout << "Sorted array:\n";
    for(int i = 0; i < arr.size(); ++i){
        std::cout << arr[i];
        if(i < arr.size() - 1)
            std::cout << ", ";
    }

    return 0;
}