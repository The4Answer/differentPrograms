void Merge(vector<int>& arr, int l, int mid, int r){
    int ind1 = 0, ind2 = 0;
    vector<int> f, s;
    for (int i = l; i <= mid; ++i) 
        f.push_back(arr[i]);
    for (int i = mid + 1; i <= r; ++i)
        s.push_back(arr[i]);

    for (int i = l; i <= r; ++i) {
        if (ind1 < f.size() && ind2 < s.size()) {
            if (f[ind1] <= s[ind2]) {
                arr[i] = (f[ind1]);
                ind1++;
            }
            else {
                arr[i] = (s[ind2]);
                ind2++;
            }
        }
        else if (ind1 < f.size()) {
            arr[i] = (f[ind1]);
            ind1++;
        }
        else {
            arr[i] = (s[ind2]);
            ind2++;
        }
    }
    return;
}
