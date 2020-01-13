/************************************ 
	* @file    : identity.h
	* @brief   : 身份基类
	* @details : 抽象类
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;

//身份抽象类
class Identity {
public:
	//用户名
	string m_Name;
	//密码
	string m_Password;

	//菜单
	virtual void showSecondMenu( ) = 0;
};