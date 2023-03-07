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
#include <sstream>

using namespace std;

string LargeSum(std::vector<std::string> &numVector) {
    vector<int> iNums;
    string result;
    do {
        if (numVector.empty()) {
            break;
        }

        auto index = numVector.cbegin();
        transform((*index).begin(), (*index).end(), back_insert_iterator(iNums), [](char c)->int{
            return atoi(&c);
        });

        int cDigitSum = 0, pNum = 0, iDigit = 0;
        int largestDigitSum = 0;
        for (index += 1; index != numVector.end(); ++index) {
            string cNum = *index;
            auto j = iNums.rbegin();
            auto i = cNum.rbegin();
            for (; i != cNum.rend(); ++i, ++j)  {
                pNum = *j;
                iDigit = (int)(*i) - 48;
                cDigitSum += iDigit + pNum;
                *j = cDigitSum % 10;
                cDigitSum /= 10;
//                cout << iDigit << " " << pNum << " sum "<< *j << cDigitSum << endl;
            }
            largestDigitSum += cDigitSum;
            cDigitSum = 0;
            cout << cDigitSum  <<endl;
        }

        if (cDigitSum > 0) {
            iNums.insert(iNums.begin(), cDigitSum);
        }
        
        
        auto r = iNums.cbegin();
        ostringstream oss;
        while (r != iNums.cend()) {
            oss << *r;
            ++r;
            
        }
        result = oss.str();
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
    ifstream of{string{fileName},ofstream::binary | ofstream::in};
    vector<std::string> numVector;

    string num;
    while (of.is_open() && !of.eof() && getline(of, num)) {
        cout << num  << endl;
        numVector.push_back(num);
    }

    string sum = LargeSum(numVector);
    cout << sum << endl;
  }


    return 0;
}
