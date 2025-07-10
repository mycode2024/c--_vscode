//44. 开发商购买土地
//https://kamacoder.com/problempage.php?pid=1044

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Developers_purchase_land{
public:
    void solution() {
        int n = 0, m = 0;
        int sum = 0;
        cin >> n >> m;
        vector<vector<int>> vec(n, vector<int>(m, 0));//创建二维数组
        
        for (int i = 0; i < n; i++) {//数据输入
            for (int j = 0; j < m; j++) {
                cin >> vec[i][j];
                sum += vec[i][j];
            }
        }

        //统计横向数据大小
        vector<int> horizontal(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                horizontal[i]+= vec[i][j];
            }
        }

        //统计纵向数据大小
        vector<int> vertical(m, 0);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                vertical[j]+= vec[i][j];
            }
        }

        //开始计算
        int result = INT_MAX;
        int horizontalCut = 0;
        for (int i = 0; i < n; i++) {
            horizontalCut+= horizontal[i];
            result = min(result, abs(sum - horizontalCut - horizontalCut));
        }

        int verticalCut = 0;
        for (int i = 0; i < n; i++) {
            verticalCut+= vertical[i];
            result = min(result, abs(sum - verticalCut - verticalCut));
        }

        cout << result << endl;
    }
};
