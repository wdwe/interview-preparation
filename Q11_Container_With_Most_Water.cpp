class Solution {
public:
    int maxArea(vector<int>& height) {
        int l, r, l_old, r_old;
        l_old = l = 0;
        r_old = r = height.size() - 1;
        int res = compute_volume(l, r, height);
        while (l < r) {
            if (height.at(l) < height.at(r)) ++l;
            else --r;

            if (height.at(l) > height.at(l_old) || height.at(r) > height.at(r_old)) {
                res = max({res, compute_volume(l, r, height)});
                l_old = l;
                r_old = r;
            }
        }
        return res;
    }
private:
    int compute_volume(int l, int r, vector<int>& height);
};

int Solution::compute_volume(int l, int r, vector<int>& height) {
    return min({height.at(l), height.at(r)}) * (r - l);
}