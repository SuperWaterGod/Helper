// 10.16 For Li.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
using namespace std;

int main()
{
	int x = -1, y = -1;
	unsigned short m;
	unsigned long n;
	bool b;
	char c = 'A';
	unsigned char a = -1;
    cout << "请输入整数：";
	cin >> x;
	n = x * x + y * y;
	cout << "x和y的平方和为："<<n<<endl;	//输出x和y的平方和
	m = n = 0;
	b = x > y;
	cout << "x>y=" << b << endl;			//x>y为1否则为0
	b = y > m;
	cout << "y>m=" << b << endl;
	b = y > n;
	cout << "y>n=" << b << endl;

	--m;
	cout << "--m=" << dec << m << ',' << hex << m << endl;				//dec以十进制输出	hex以十六进制输出
	cout << "y>>8=" << dec << (y >> 8) << "," << hex << (y >> 8) << endl;	//>>右移		<<左移
	cout << "y<<16=" << dec << (y << 16) << "," << hex << (y << 16) << endl;
	cout << "m>>8=" << dec << (m >> 8) << "," << hex << (m >> 8) << endl;
	cout << "m<<16=" << dec << (m << 16) << "," << hex << (m << 16) << endl;

	cout << c << "," << c + 1 << "," << c - a << endl;				//c为字符	c+1为对应ASCLL数字	c-a十六进制输出
	
	return 0;

}