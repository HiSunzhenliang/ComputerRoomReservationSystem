/************************************ 
	* @file    : order.h
	* @brief   : ԤԼ��
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
	int date;      //����
	int interval;  //ʱ���
	int stuId;     //ѧ�����
	string stuName;   //ѧ������
	int roomId;    //�������
	int status;    //ԤԼ״̬
};