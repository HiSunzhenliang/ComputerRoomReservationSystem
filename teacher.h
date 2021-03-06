/************************************ 
	* @file    : teacher.h
	* @brief   : 教师子类
	* @details : 继承identity基类
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "identity.h"
#include "order.h"

//教师类
class Teacher:public Identity {
public:
	//教师编号
	int m_empId;
	//维护预约容器
	vector<Order> vOrd;
	//初始化容器,文件更新容器
	void initVector( );
	//容器更新文件
	void vecInitFile( );

	//默认构造
	Teacher( );
	//有参构造
	Teacher(int empId, string name, string password);
	//菜单
	virtual void showSecondMenu( );
	//查看所有预约
	void showAllOrder( );
	//审核预约
	void checkOrder( );
};