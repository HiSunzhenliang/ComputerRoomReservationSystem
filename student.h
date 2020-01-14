/************************************ 
	* @file    : student.h
	* @brief   : 学生子类
	* @details : 继承identity基类
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "computerRoom.h"
#include "identity.h"
#include "order.h"


//学生类
class Student:public Identity {
public:
	//学号
	int m_id;
	//维护机房容器
	vector<ComputerRoom> vCom;
	//维护预约容器
	vector<Order> vOrd;

	//初始化容器
	void initVector( );

	//默认构造函数
	Student( );
	//有参构造
	Student(int id, string name, string password);
	//显示菜单
	virtual void showSecondMenu( );
	//申请预约
	void applyOrder( );
	//查看我的预约
	void showMyOrder( );
	//查看所有预约
	void showAllOrder( );
	//取消预约
	void cancelOrder( );
};
