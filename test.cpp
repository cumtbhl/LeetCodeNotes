#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> test;
    cout << test.size() << endl;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    cout << test.at(1) << endl;
    cout << test[1] << endl;
    return 0;
}