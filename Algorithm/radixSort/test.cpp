
#include <iostream>
#include <math.h> 
using namespace std;

int main(){
    int carry = 0;
    int largest = 90;
    int temp = pow(10,0);
    cout << largest / temp << endl;
    while(int(largest / pow(10,carry)) !=0){
        carry++;
        cout << carry <<endl;
    }

    int c = 0;
    temp = largest;
        while (temp != 0) {
        c++;
        temp /= 10;
        cout << c <<" "; 
    }
    return 0;
}
