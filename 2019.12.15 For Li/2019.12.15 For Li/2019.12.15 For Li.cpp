// 2019.12.15 For Li.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define RED 1
#define GREEN 2
#define BLUE 3
using namespace std;
int map[3][3] = {0};
int number(int red, int blue,int green)
{
    int red_ = 0; int blue_ = 0;int green_ = 0;
    for (int a = 0; a <= 2; a++)
    {
        for (int b = 0; b <= 2; b++)
        {
            if (map[a][b] == RED)
                red_ = red_ + 1;
            else if (map[a][b] == GREEN)
                green_ = green_ + 1;
            else if(map[a][b]==BLUE)
                blue_ = blue_ + 1;
        }
    }
    if ((red == red_) && (blue == blue_) && (green == green_))
        return 0;
}
int test()
{
    int judge = 0;
    for (int a = 0; a <= 2; a++)
    {
        for (int b = 0; b <= 2; b++)
        {
            if ((map[a][b] == map[a - 1][b]) || (map[a][b] == map[a + 1][b]) || (map[a][b] == map[a][b + 1]) || (map[a][b] == map[a][b - 1]))
                judge = 1;
        }
    }
    return judge;
}
int main()
{
    int red, blue, green = 0;
    cout << "请输入“红 蓝 绿”三种颜色的数量：" << endl;
    cin >> red >> blue >> green;
    if ((red + blue + green != 9) || (red <= 0) || (blue <= 0) || (green <= 0))
    {
        cout << "输入个数错误" << endl;
        return 0;
    }
    for (int a = 1; a <= 3; a++)
    {
        map[0][0] = a;
        for (int b = 1; b <= 3; b++)
        {
            map[0][1] = b;
            for (int c = 1; c <= 3; c++)
            {
                map[0][2] = c;
                for (int d = 1; d <= 3; d++)
                {
                    map[1][0] = d;
                    for (int e = 1; e <= 3; e++)
                    {
                        map[1][1] = e;
                        for (int f = 1; f <= 3; f++)
                        {
                            map[1][2] = f;
                            for (int g = 1; g <= 3; g++)
                            {
                                map[2][0] = g;
                                for (int h = 1; h <= 3; h++)
                                {
                                    map[2][1] = h;
                                    for (int i = 1; i <= 3; i++)
                                    {
                                        map[2][2] = i;
                                        if (test() != 1)//判断合理
                                        {
                                            if (number(red,blue,green) == 0) //符合数量
                                            {
                                                for (int x = 0; x <= 2; x++)//输出结果
                                                {
                                                    for (int y = 0; y <= 2; y++)
                                                    {
                                                        if (map[x][y] == RED)
                                                            cout << "R";
                                                        if (map[x][y] == BLUE)
                                                            cout << "B";
                                                        if (map[x][y] == GREEN)
                                                            cout << "G";

                                                    }
                                                }
                                                cout << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
