/************************************ 
	* @file    : identity.h
	* @brief   : ��ݻ���
	* @details : ������
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;

//��ݳ�����
class Identity {
public:
	//�û���
	string m_Name;
	//����
	string m_Password;

	//�˵�
	virtual void showSecondMenu( ) = 0;
};