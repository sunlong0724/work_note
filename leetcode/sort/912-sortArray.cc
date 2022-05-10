#include <vector>
#include <iostream>

using namespace std;

void do_quick_sort(vector<int>& vec, int start, int end){
    if (start >= end){
        return;
    }

    swap(vec[end], vec[ start + (end-start)/2]);
    int cur = start;
    for (int i = start; i < end; ++i){
        if (vec[i] < vec[end]){
            swap(vec[cur++], vec[i]);
        }
    }
    swap(vec[end], vec[cur]);
    do_quick_sort(vec, start, cur-1);
    do_quick_sort(vec, cur+1, end);
}

void quick_sort(std::vector<int>& vec){
    do_quick_sort(vec, 0, vec.size()-1);
}

std::vector<int> do_merge_sort(std::vector<int>& arr, int start, int end){
    if (start > end){
        return {};
    }

    if (start == end){
        return {arr[start]};
    }
    
    int m = start + (end-start)/2;
    auto l = do_merge_sort(arr, start, m);
    auto r = do_merge_sort(arr, m+1, end);

    std::vector<int> ret;
    int i = 0, j = 0;
    while( i < l.size() && j < r.size()){
        if (l[i] < r[j]){
            ret.push_back(l[i++]);
        }else{
            ret.push_back(r[j++]);
        }
    }
    if (i < l.size()){
        ret.insert(ret.end(), l.begin() + i, l.end());
    }
    if (j < r.size()){
        ret.insert(ret.begin(), r.begin()+j, r.end());
    }
    return ret;
}

std::vector<int> merge_sort(std::vector<int>& arr){
    return do_merge_sort(arr, 0, arr.size()-1);
}



int main(int argc, char** argv){
    
    int a = 100;
    int b = 10;
    int* c = new int(100);
    int* d = new int(10);
    fprintf(stdout,"%p %p %p %p\n", &a, &b, c, d);
    return 0;


    std::vector<int> vec;
    for (int i = 0; i < 100; ++i){
        vec.push_back(100-i);
    }

    for (auto& x : vec){
        fprintf(stdout,"%d ", x);
    }
    fprintf(stdout,"\n#############################\n");

    //quick_sort(vec);
    auto ret  = merge_sort(vec);
    vec = ret;
    for (auto& x : vec){
        fprintf(stdout,"%d ", x);
    }
    fprintf(stdout,"\n");
    return 0;
}