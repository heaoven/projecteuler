//
//  main.cpp
//  probleam15
//
//  Created by venwu on 2023/3/7.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

long LargeSum(std::vector<std::string> &numVector) {
    vector<int> iNums;
    long result = 0;
    do {
        if (numVector.empty()) {
            break;
        }

        auto index = numVector.cbegin();
        transform((*index).begin(), (*index).end(), back_insert_iterator(iNums), [](char c)->int{
            return atoi(&c);
        });

        int cDigitSum = 0;
        for (index += 1; index != numVector.end(); ++index) {
            string cNum = *index;
            for (auto i = cNum.size() - 1; i >= 0; --i) {
                int iDigit = (int)cNum.at(i) - 48 ;
                cDigitSum += iDigit + iNums[i];
                iNums[i] = cDigitSum % 10;;
                cDigitSum /= 10;
            }
        }

        if (cDigitSum > 0) {
            iNums.push_back(cDigitSum);
        }

        for (int i = 0 ; i < 10; ++i) {
            cout << iNums[i] << endl;
            result += iNums[i] * std::pow(10, i);
        }

    } while (0);

    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

  {

    std::string fileName{argv[1]};
    std::string fileName2{argv[2]};
    cout << "fileName: " << fileName << "fileNmae2" << fileName2 << endl;
    ifstream of{string{fileName2},ofstream::binary | ofstream::in};
    vector<std::string> numVector;

    string num;
    while (of.is_open() && !of.eof() && getline(of, num)) {
        cout << num  << endl;
        numVector.push_back(num);
    }

    long sum = LargeSum(numVector);
    cout << sum << endl;
  }


    return 0;
}
