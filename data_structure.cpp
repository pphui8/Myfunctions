#include <bits/stdc++.h>
using namespace std;

// 动态数组
vector<int> vec;

// 双向链表
list<int> nums;

// 有序集合，元素不可重复，底层实现默认为红黑树
// 快速获取最大或最小值效率不如 priority_queue
set<int> nums;

// 无序集合（记忆化查找）
unordered_set<int> found_num;

// 最大值先出的数据结构
// 常用于维护数据结构并快速获取最大或最小值
priority_queue<int> p_que;

stack<int> stk;
queue<int> que;

// 有序映射或有序表
map<char, int> maps = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};
