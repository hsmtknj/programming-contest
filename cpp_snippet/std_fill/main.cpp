#include <bits/stdc++.h>

int main ()
{
    // 2次元配列の初期化
    std::cout << "2D MATRIX" << std::endl;
    int a[3][5];
    std::fill( a[0], a[3], 200);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    // 3次元配列の初期化
    std::cout << "3D MATRIX" << std::endl;
    int b[4][3][2];
    std::fill( b[0][0], b[4][0], 300 );
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                std::cout << b[k][j][i] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}