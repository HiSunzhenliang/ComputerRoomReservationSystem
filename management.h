/************************************ 
	* @file    : management.h
	* @brief   : 全局管理类的声明
	* @details : 主菜单显示等
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "management.h"

//管理类
class management {
public:
	//主菜单选项
	int select;
	//显示主菜单
	void showMainMenu( );
	//选择主菜单选项
	void choseMainMenuOption( );
	//登录功能(对应操作文件，对应子类)
	Identity* LogIn(string filename, int identity);
	//学生选项
	void studentMenu(Identity* &student);
	//教师选项
	void teacherMenu(Identity* &teacher);
	//管理员选项
	void managerMenu(Identity* &manager);

	//退出系统功能
	void exitSys( );
};
