#include <iostream>
#include <vector>
#include <array>


const int digitsNum = 10;

int main(){
    std::ios::sync_with_stdio(false);//switch off sync between C++ and C print
    std::cin.tie(0);//отключает сброс буфеера пере вызовом cout


    std::vector<std::string> arrInputData;
    int size = -1;

    std::cin >> size;
    arrInputData.reserve(size);
    std::cout << "Initial array:\n";
    std::cin.ignore(64, '\n');
    for(int i = 0; i < size; ++i){
        std::string temp{};
        std::getline(std::cin, temp, '\n');
        arrInputData.push_back(temp);
        std::cout << temp;
        if(i < size - 1)
            std::cout << ", ";
    }
    int digitSize = arrInputData[0].size();
    std::cout << "\n**********\n";
    //solution


    std::array<std::vector<std::string>,digitsNum> buffer{};//consist 10 string array for bucket, 10 because ten digits
    auto print = [&buffer](){
        for(int i = 0; i < digitsNum; ++i){
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



    auto lastRadix = [digitSize](std::string numStr, int rad){
        int num = numStr[digitSize - rad-1] - '0';
        return num;
    };

    std::cout << "Phase " << 1 << '\n';
    for(std::string i : arrInputData){
        int temp = lastRadix(i, 0);
        buffer[temp].push_back(i);
    }
    print();

    for(int phase = 1; phase < arrInputData[0].size(); ++phase){
        std::cout << "Phase " << phase+1 << '\n';
        std::array<std::vector<std::string>,10> bufferTemp{};
        for(int i = 0; i < digitsNum; ++i){
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
            arrInputData[arrIter++] = buffer[i][j];
        }
    }

    //
    std::cout << "Sorted array:\n";
    for(int i = 0; i < arrInputData.size(); ++i){
        std::cout << arrInputData[i];
        if(i < arrInputData.size() - 1)
            std::cout << ", ";
    }

    return 0;
}