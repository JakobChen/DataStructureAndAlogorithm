/*
数据流中的移动平均值
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。

实现 MovingAverage 类：

MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 计算并返回数据流中最后 size 个值的移动平均值。
 

示例：

输入：
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
输出：
[null, 1.0, 5.5, 4.66667, 6.0]

解释：
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/k1msc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/



#include<iostream>
#include<queue>
using namespace std;

class MovingAverage {
private:
    queue<int> data;
    int wSize;
    double sum = 0 ;

public:
    MovingAverage(int size) {
        wSize = size;
    }
    
    double next(int val) {
        if(data.size() < wSize){
            data.push(val);
            sum += val;
            return sum / data.size();

        }else{
            sum -= data.front();
            data.pop();
            data.push(val);
            sum += val;
            return sum / data.size();
        }

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */