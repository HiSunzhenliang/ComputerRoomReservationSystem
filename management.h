/************************************ 
	* @file    : management.h
	* @brief   : 全局管理类的声明
	* @details : 主菜单显示等
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>

//管理类
class management {
public:
	//主菜单选项
	int select;
	//显示主菜单
	void showMainMenu( );
	//选择主菜单选项
	void choseMainMenuOption( );
	//退出系统功能
	void exitSys( );
};
