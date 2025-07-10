//58. 区间和
//https://kamacoder.com/problempage.php?pid=1070

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Interval_sum {
public:
    void solution_my() {
        Interval_sum sum;
        int num = 0;
        vector<int> vec;
        cin >> num;
        int temp;
        for (int i = 0; i < num; i++) {
            cin >> temp;  
            vec.emplace_back(temp);
        } 

        vector<vector<int>> arr;
        int begin = 0;
        int end = 0;
        string line;
        int index = 0;
        getline(cin, line);
        while (getline(cin, line)) {
            if (line.empty()) {
                break; // 输入空行时退出循环
            }

            istringstream iss(line);
            if (iss >> begin >> end) {
                arr.emplace_back(); // 添加新行
                arr.back().push_back(begin);
                arr.back().push_back(end);
            } else {
                cerr << "输入格式错误，请输入两个整数！" << endl;
            }
        }

        auto it = arr.begin();
        while (it != arr.end()) {
            int sum = 0;
            for (int i = (*it).at(0); i <= (*it).at(1); i++ ) {
                sum+= vec[i];
            }
            (*it).at(0) = sum;
            it++;
        }

        for (int i = 0; i < arr.size(); i++) {
            cout << arr.at(i).at(0) << endl;
        }
        
    }

    void print_1(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr.at(i) << " ";
        }
    }

    void print_2(vector<vector<int>> arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr.at(i).at(0) << " ";
            cout << arr.at(i).at(1) << " " << endl;
        }
    }

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