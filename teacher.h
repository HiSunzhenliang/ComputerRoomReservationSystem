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
#include <vector>
#include "identity.h"
#include "order.h"

//��ʦ��
class Teacher:public Identity {
public:
	//��ʦ���
	int m_empId;
	//ά��ԤԼ����
	vector<Order> vOrd;
	//��ʼ������,�ļ���������
	void initVector( );
	//���������ļ�
	void vecInitFile( );

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