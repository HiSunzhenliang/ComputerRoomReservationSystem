/************************************ 
	* @file    : management.cpp
	* @brief   : 全局管理类的定义
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include "management.h"
using namespace std;


//显示主菜单
void management::showMainMenu( ) {
	cout << "======================  欢迎使用机房预约系统  =====================" << endl;
	cout << "\t\t ===============================\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ===============================\n";
}
//选择主菜单选项
void management::choseMainMenuOption( ) {
	cout << "请输入你的选择：" << endl;
	cin >> this->select;
	switch (select) {
	//学生
	case 1:
		break;
	//老师
	case 2:
		break;
	//管理员
	case 3:
		break;
	//退出系统
	case 0:
		this->exitSys( );
		break;
	default:
		cout << "输入有误，请重新选择！" << endl;
		system("pause");
		system("CLS");
		break;
	}
}
//退出系统功能
void management::exitSys( ) {
	system("CLS");
	cout << "\n\n欢迎下次使用！\n\n" << endl;
	system("pause");
	exit(0);
}

