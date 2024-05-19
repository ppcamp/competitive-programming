#include "iostream"
#include "vector"

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        for (size_t i = 0, max = nums.size(); i < max; i++) {
            if (nums[i] == val) {
                for (size_t j = i + 1; j < max; j++) {
                    if (nums[j] == val) {
                        continue;
                    }
                    nums[i] = nums[j];
                    i++;
                }
                return i;
            }
        }
	    return nums.size();
    }
};

// int main(int argc, char const *argv[])
// {
//     auto s = new Solution();
//     auto v = vector<int>{3,3,2,2,5,3};
//     auto k = s->removeElement(v,3);
//     v.resize(k);
//     for (auto const & s : v) {
//         cout << s << endl;
//     }
//     return 0;
// }
