#include <iostream>
#include <vector>
using  namespace std;
#include <queue>

int main()
{
    vector<int> vec {1,2,3,4};
    vector<int>::iterator it;

    vector<int> vec1 {5,5,6,5,5,6};
    vec.swap(vec1);

    vector<int>::const_iterator first = vec.begin();
    vector<int>::const_iterator end = vec.begin() + 3;
    vector<int> newVec(vec.begin(),vec.begin() + 3);
    for(auto el : newVec){
        cout << el << endl;
    }
    vector<int> vec3 (3);
    vec3 = (vec.begin(),vec.begin() + 2);

    cout << "test: " << vec3[1]<<endl;

    /*
    for (it = vec.begin(); it !=vec.end();it++)
    {
        cout << *it << endl;
    }
    it = vec.begin();
    vec.insert(it, 10);
    for (it = vec.begin(); it !=vec.end();it++)
    {
        cout << *it << endl;
    }    
     
    vec.pop_back();
    for (it = vec.begin(); it !=vec.end();it++)
    {
        cout << *it << endl;
    }  

    it = vec.begin();
    vec.erase(it);
    for (it = vec.begin(); it !=vec.end();it++)
    {
        cout << *it << endl;
    } 
    it = vec.begin();
    vec.erase(vec.begin(), vec.end() -1);
    for (it = vec.begin(); it !=vec.end();it++)
    {
        cout << *it << endl;
    } 
    */

    return 0;
}