#include <iostream>
#include <cstdio>
#include <queue>
//Assume the last N measurements is 100
#define N 100

class Measurement{
public:
    Measurement(): window_size(N), sum(0){}
    double AverageAfterNext( int val){
        if(data.size() < window_size){
            data.push(val);
            sum += val;
        }else{
            sum -= data.front();
            data.pop();
            data.push(val);
            sum += val;
        }
        return sum / data.size();
    }
    
private:
    int window_size;
    double sum;
    //FIFO
    std::queue<int> data;         
};

int main (int argc, char *argv[]){
    
    // test case
    Measurement measurement;
    for(int i=0; i < 200; i++){
        double avg = measurement.AverageAfterNext(i);
        std::cout << "Index: "<< i << " Avg: " << avg << std::endl;  
    }
    return 0;
}