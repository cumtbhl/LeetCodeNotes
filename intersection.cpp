#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 暴力解法
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(auto i : nums1){
            // 这里 find 的时间复杂度为O(N)，再加上for循环，整个时间复杂度就是O(N * N)
            if(find(nums2.begin(), nums2.end(), i) != nums2.end() && 
            find(result.begin(), result.end(), i) == result.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};

// 哈希表解法-unordered_set查询
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;

        // 这一步将 nums1 的所有元素插入 unordered_set_num1
        // 插入每个元素的平均时间复杂度为 O(1)
        // 故该步骤总的时间复杂度为 O(N)
        unordered_set<int> unordered_set_num1(nums1.begin(), nums1.end());


        for(auto i : nums2){
            // 这里 find(i) 的时间复杂度为 O(1)，再加上for循环，整个时间复杂度就是O(N)
            if(unordered_set_num1.find(i) != unordered_set_num1.end()){
                result.insert(i);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

// 哈希表解法-vector查询
class Solution3 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        vector<int> vec_nums1(1005,0);
        for(auto i : nums1){
            vec_nums1[i] = 1;
        }

        for(auto i : nums2){
            if(vec_nums1[i] == 1){
                result.insert(i);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

int main(){
    vector<int> a = {1,1,2,2,444,5,5};
    vector<int> b = {1,5};
    Solution2 s;
    vector<int> result = s.intersection(a,b);
    for(auto i : result){
        cout << i << endl;
    }
    return 0;
}