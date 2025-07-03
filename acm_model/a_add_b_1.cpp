#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class solution {
public:
    void add_list(vector<vector<int>>& vec) {
        auto iter = vec.begin();
        while (iter!=vec.end()) {
            cout<<(*iter).at(0)+(*iter).at(1)<<endl;
            iter++;
        }
    }
    
}; 
int main()
{
    vector<vector<int>> data;
    string line;

    while (getline(cin, line)) { // 读取整行
        if (line.empty()) break; // 空行终止
        istringstream iss(line);
        int a, b;
        iss >> a >> b; // 从行中提取两个数字
        data.push_back({a, b});
    }

    solution so;
    so.add_list(data);
    
    return 0;

}