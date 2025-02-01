#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    long long N, C;
    cin >> N >> C;
    vector<long long> nums(N);
    unordered_map<long long, long long> countMap;

    // 读入数字并统计每个数字出现的次数
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        countMap[nums[i]]++;
    }

    long long pairCount = 0;

    // 遍历数组，计算满足条件的数对个数
    for (long long num : nums) {
        if (countMap.find(num - C) != countMap.end()) {
            pairCount += countMap[num - C];
        }
        // 如果A和B相等，那么这个数对只能算一次，所以减去自身
        if (num - C == num) {
            pairCount -= 1;
        }
    }

    cout << pairCount << endl;

    return 0;
}