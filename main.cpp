#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void inorder(TreeNode *r, bool& prevValid, TreeNode*& prev, int &distance) {
        if (!r) return;
        inorder(r->left, prevValid, prev, distance);
        if (prevValid)
            distance = min(distance, r->val - prev->val);
        prevValid = true;
        prev = r;
        inorder(r->right, prevValid, prev, distance);
    }

    int minDiffInBST(TreeNode *root) {
        if (!root) return 0;
        assert(root->left || root->right);
        int distance = INT_MAX;
        bool prevValid = false;
        inorder(root, prevValid, root, distance);
        return distance;
    }
};

void test1() {
//    vector<int> v1 {4, 2, 6, 1, 3};
//    auto t1 = new TreeNode(v1);
//    cout << "1 ? " << Solution().minDiffInBST(t1) << endl;

//    vector<int> v2 {27,-1,34,-1,58,50,-1,44,-1,-1,-1};
//    auto t2 = new TreeNode(v2, -1);
//    cout << t2 << endl;
//    cout << "6 ? " << Solution().minDiffInBST(t2) << endl;

    vector<int> v3{90, 69, -1, 49, 89, -1, 52};
    auto t3 = new TreeNode(v3, -1);
    cout << t3 << endl;
    cout << "1 ? " << Solution().minDiffInBST(t3) << endl;
}

void test2() {

}

void test3() {

}