
#define all(x) x.begin(), x.end()
#define vec vector<lint>
vec nums;

int main() {
    for(int i = 0; i < 1000; ++i) {
        nums.push_back(i);
    }

    int target = 799;
    int output = 0;

    // binary search
    output = upper_bound(all(nums), target) - nums.begin();
    // output = lower_bound(all(nums), target) - nums.begin();

    cout<<output<<endl;
    return 0;
}
