#include<iostream>
#include<vector>
using namespace std;

class Test{
public:
    Test(const string& name , int& value);
    void print();
private:
    string name;
    int value;
};

// 在成员函数中，如果没有局部变量与成员变量同名，通常不需要使用 this->
// 只有在局部变量与成员变量同名时，使用 this-> 可以明确区分。
Test::Test(const string& a , int& b){
    b++;
    name = a;
    value = b;
}

void Test::print(){
    cout << "my name is " << name << " , my value is " << value << endl;
}

int main(){
    int a = 10;
    int b = 11;
    vector<Test> vec;
    vec.emplace_back("hou",a);
    vec.emplace_back("shi",b);
    // vec[0].print();
    // vec[1].print();
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}