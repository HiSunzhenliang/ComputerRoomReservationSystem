/************************************ 
	* @file    : manager.h
	* @brief   : 管理员子类
	* @details : 继承identity基类
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "identity.h"

//管理员类
class Manager:public Identity {
public:
	//维护两个容器，用于更新文件，查重
	vector<Student> vStu;
	vector<Teacher> vTea;
	//容器初始化
	void initVector( );
	//默认构造
	Manager( );
	//有参构造
	Manager(string name, string password);
	//菜单
	virtual void showSecondMenu( );
	//添加账号
	void addUser( );
	//查看账号
	void showUser( );
	//查看机房
	void showRoom( );
	//清空信息
	void cleanFile( );
	//去重函数
	bool isRepeat(int id, int identity);
	//打印学生信息
	void printStudent(Student &s);
	//打印老师信息
	void printTeacher(Teacher &t);
	//打印机房信息
	void printRoom( );
};