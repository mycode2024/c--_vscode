//209. 长度最小的子数组
//https://leetcode.cn/problems/minimum-size-subarray-sum/description/

#include <iostream>
#include <vector>
using namespace std;

class The_subarray_with_the_smallest_length{
public:
    void solution() {
        int total_num = 0;
        cin >> total_num;
        vector<int> pre_;
        vector<int> next_;
        int temp_num = 0;
        int sum = 0;
        for (int i = 0; i < total_num; i++) {
            cin >> temp_num;
            pre_.emplace_back(temp_num);
            sum+= temp_num;
            next_.emplace_back(sum);
        }

        int a = 0, b = 0;
        while (cin >> a >> b) {
            int result = 0;
            if (a == 0)
                result = next_.at(b);
            else 
                result = next_.at(b) - next_.at(a-1);
            
            cout << result << endl;
        }
    }
};

