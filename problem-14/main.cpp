//
//  main.cpp
//  problem-14
//
//  Created by venwu on 2023/3/8.
//

#include <iostream>
#include <unordered_map>

std::pair<uint32_t, uint32_t> LongestCollatzSequence(uint32_t num) {

    std::unordered_map<uint32_t,uint32_t> preCollatzChainNumMap;

    uint32_t largest = 0, curNum, startNumber;
    for (int i = 2; i < num; ++i) {
        curNum = i;
        uint32_t curChainNums = 1;
        if (preCollatzChainNumMap.find(curNum) != preCollatzChainNumMap.end()) {
            curChainNums += preCollatzChainNumMap[curNum];
        } else {
            while(curNum != 1) {
                    /// even
                if (curNum % 2 == 0) {
                    curNum = curNum / 2;
                } else {
                    curNum =  curNum * 3 + 1;
                }
                curChainNums++;
            }
            preCollatzChainNumMap[i] = curChainNums;
        }

        if (curChainNums > largest) {
            largest = curChainNums;
            startNumber = i;
        }
    }

    return std::pair<uint32_t, uint32_t>{largest, startNumber};

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
  {
    auto longest = LongestCollatzSequence(1000000);

    std::cout << longest.first << " " << longest.second << std::endl;
  }
    return 0;
}
