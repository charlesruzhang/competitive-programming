#include <bits/stdc++.h>

using namespace std;
#define int long long int
struct Node {
  int value;
  int idx;
  pair<int, int> interval;
  Node* left;
  Node* right;
};

Node* constructTree(vector<int>& stones) {
    stack<Node*> s;
    for (int i = 0; i < stones.size(); i++) {
        Node* newNode = new Node();
        newNode->value = stones[i];
        newNode->idx = i;
        newNode->interval = {i, i};
        Node* top = nullptr;
        while (!s.empty() && s.top()->value < stones[i]) {
            top = s.top();
            s.pop();
        }
        newNode->left = top;
        if (!s.empty()) {
            Node* parent = s.top();
            parent->right = newNode;
        }
        s.push(newNode);
    }
    while (s.size() > 1) {
        s.pop();
    }
    return s.top();
}

vector<long long> constructSums(vector<int> nums) {
    vector<long long> ret = vector<long long>(nums.size() + 1);
    ret[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
        ret[i + 1] = nums[i] + ret[i];
    }
    return ret;
}

pair<int, int> constructIntervals(Node* root) {
    if (root == nullptr) {
        return {INT_MAX, INT_MIN};
    }
    
    pair<int, int> l = constructIntervals(root->left);
    pair<int, int> r = constructIntervals(root->right);
    
    root->interval.first = min({root->idx, l.first, r.first});
    root->interval.second = max({root->idx, l.second, r.second});
    
    return {root->interval.first, root->interval.second};
}

bool checkPass(Node* root, vector<long long>& prefixSums) {
    if (root == nullptr) {
        return true;
    }
    return (root->value >= (prefixSums[root->interval.second + 1] - prefixSums[root->interval.first]))
           && checkPass(root->left, prefixSums)
           && checkPass(root->right, prefixSums);
}

signed main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numCases, n;
    cin >> numCases;
    for (int currCase = 0; currCase < numCases; currCase++) {
        cin >> n;
        vector<int> stones(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> stones[i];
        }
        Node* root = constructTree(stones);
        vector<long long> prefixSums = constructSums(stones);
        constructIntervals(root);
        if (checkPass(root, prefixSums)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
 
}