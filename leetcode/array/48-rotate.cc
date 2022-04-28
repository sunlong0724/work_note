
#include <vector>
#include <iostream>

using namespace std;

/*
n*n matrix roata 90.
nxn的矩阵想象成一个一个嵌套的正方形。嵌套了len/2成。然后顺时针旋转每层正方形的边上点。
*/
void rotate(std::vector<std::vector<int>>& matrix){
    int len = matrix.size();
    int level = len /2;
    for (int i = 0; i < level; ++i){
        for (int j = i; j < len - i - 1; ++j){
            int temp = matrix[i][j];//左上角的点，列变行不变
            //主要分清是行边还是列变
            matrix[i][j] = matrix[len - j - 1][i];//左下角点  在该循环内，列时不变的所以列值取i，从下往上取 行值取len-j-1
            matrix[len - j -1][i] = matrix[len - i - 1][len -j -1];//右下角点 在该循环内，从右往左，列变行不变
            matrix[len - i - 1][len - j -1] = matrix[j][len-i-1];//右上角点 在该循环内，从上往下，行变列不变
            matrix[j][len-i-1] = temp;
        }
    }
}


int main(int argc, char ** argv){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (auto& v : matrix){
        for (auto& x : v){
            fprintf(stdout,"%d ", x);
        }
        fprintf(stdout,"\n");
    }

    rotate(matrix);

    for (auto& v : matrix){
        for (auto& x : v){
            fprintf(stdout,"%d ", x);
        }
        fprintf(stdout,"\n");
    }
}