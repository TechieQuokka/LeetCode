class NumArray {
private:
    vector<int> buffer;

public:
    NumArray(vector<int>& numbers) : buffer (numbers.size() + 1) {
        
        buffer.push_back (0);
        int length = numbers.size();
        for (int index = 0; index < length; index++) {

            this->buffer[index + 1] = this->buffer[index] + numbers[index];
        }
        return;
    }
    
    int sumRange(int left, int right) {
        
        return this->buffer[right + 1] - this->buffer[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */