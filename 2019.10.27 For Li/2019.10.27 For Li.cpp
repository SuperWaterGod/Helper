// 2019.10.27 For Li.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
////////////////////////////////////////////////////////////////////
//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /				  //
//      ========`-.____`-.___\_____/___.-`____.-'========		  //
//                           `=---='							  //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^		  //
//         佛祖保佑       永无BUG     永不修改					  //
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main()
{
	int a = 0, b = 0, door_x = 0, door_y = 0, window_x = 0, window_y = 0, furniture_x = 0, furniture_y = 0;
	int door = 0, window = 0, furniture = 0;

	gotoxy( 0 , 0 );
    cout << "请输入房间的长和宽\n";
	cin >> a >> b;
	while (1)
	{
		while (1)
		{
			cout << "请输入门的坐标\n";
			cin >> door_x >> door_y;
			cout << "请输入窗的坐标\n";
			cin >> window_x >> window_y;
			cout << "请输入家具的坐标\n";
			cin >> furniture_x >> furniture_y;

			if ((door_x == 0 && door_y == 0)||(door_x == a-1 && door_y == 0)||(door_x == 0 && door_y == b-1)||(door_x == a-1 && door_y == b-1))
			{
				cout << "门不能放在角落\n";
				break;
			}
			else if ((door_x == 0 &&  door_y >0 && door_y <b-1)||(door_x == a-1 && door_y > 0 && door_y < b - 1)||(door_y == 0 && door_x > 0 && door_x < a - 1)||(door_y == b-1 && door_x > 0 && door_x < a - 1))
			{
				door = 1;
			}
			else
			{
				cout << "门只能放在墙上\n";
				break;
			}


			if ((window_x == 0 && window_y == 0) || (window_x == a - 1 && window_y == 0) || (window_x == 0 && window_y == b - 1) || (window_x == a - 1 && window_y == b - 1))
			{
				cout << "窗不能放在角落\n";
				break;
			}
			else if ((window_x == 0 && window_y > 0 && window_y < b - 1) || (window_x == a - 1 && window_y > 0 && window_y < b - 1) || (window_y == 0 && window_x > 0 && window_x < a - 1) || (window_y == b - 1 && window_x > 0 && window_x < a - 1))
			{
				if ((window_x == door_x && window_y == door_y )||(window_x == door_x && window_y == door_y+1)||(window_x == door_x && window_y == door_y - 1)||(window_y == door_y && window_x == door_x - 1)||(window_y == door_y && window_x == door_x + 1))
				{
					cout << "窗不能放在门边\n";
					break;
				}
				else
					window = 1;
				
			}
			else 
			{
				cout << "窗只能放在墙上\n";
				break;
			}

			if ((furniture_x == door_x && furniture_y == door_y + 1) || (furniture_x == door_x && furniture_y == door_y - 1) || (furniture_y == door_y && furniture_x == door_x + 1)||(furniture_y == door_y && furniture_x == door_x - 1))
			{
				cout << "家具不能堵门\n";
				break;
			}
			else if (furniture_x >0&& furniture_x<a-1&& furniture_y>0&& furniture_y<b-1)
				furniture = 1;
			else
			{
				cout << "家具必须放在室内\n";
				break;
			}

			break;

		}
		if ((door == 1)&&(window==1)&&(furniture ==1))
			break;
	}

	cout << "请输入家具的坐标\n";
	system("cls");
	for (int x = 0; x < a; x++)//横
		cout << "#";
	gotoxy(0, b - 1);
	for (int x = 0; x < a; x++)//横
		cout << "#";
	gotoxy(0, 0);
	for (int x = 0; x < b; x++)//竖
		cout << "#\n";
	gotoxy(a-1, 0);
	for (int x = 0; x <= b; x++)//竖
	{
		cout << "#";
		gotoxy( a - 1 , x );
	}

	gotoxy(door_x, door_y);
	cout << " ";
	gotoxy(window_x, window_y);
	if (window_y==0|| window_y==b-1)
		cout << "-";
	else
		cout << "|";
	gotoxy(furniture_x, furniture_y);
	cout << "*";
	gotoxy(a+1 , b-1);
	cin >> a;
	return 0;
}
