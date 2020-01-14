/************************************ 
	* @file    : order.h
	* @brief   : 预约类
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-14
************************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;;

class Order {
public:
	int date;      //日期
	int interval;  //时间段
	int stuId;     //学生编号
	string stuName;   //学生姓名
	int roomId;    //机房编号
	int status;    //预约状态
};