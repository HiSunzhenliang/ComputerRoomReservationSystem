/************************************ 
	* @file    : teacher.h
	* @brief   : ��ʦ����
	* @details : �̳�identity����
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <string>
#include "identity.h"

//��ʦ��
class Teacher:public Identity {
public:
	//��ʦ���
	int m_empId;

	//Ĭ�Ϲ���
	Teacher( );
	//�вι���
	Teacher(int empId, string name, string password);
	//�˵�
	virtual void showSecondMenu( );
	//�鿴����ԤԼ
	void showAllOrder( );
	//���ԤԼ
	void checkOrder( );
};