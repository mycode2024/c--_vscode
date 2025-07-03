#include <iostream>
#include <vector>
using namespace std;

class Binary_Search
{
public:
    int search(vector<int>& vec,int target)
    {
        int left=0;
        int right=vec.size()-1;
        int middle=(left+right)/2;
        // int middle=left+(right-left)/2;//防止left和right过大相加溢出
        while(left<=right)//左闭右闭写法，[left,right]
        {
            if(target<vec[middle])
            {
                right=middle-1;//小于middle下标，那么vec[middle]本身肯定不是target，所以减去
            }   
            else if(target>vec[middle])
            {
                left=middle+1;//同理
            }
            else{
                return middle;//找到元素，返回下标
            }
            middle=(left+right)/2;//下标不断折中
        }
        return -1;//未找到目标元素下标
    }
};

int main()
{
    Binary_Search temp;
    vector<int> vec={1,2,3,4,5,6};
    int index=temp.search(vec,5);
    cout<<"index="<<index<<endl;
}
