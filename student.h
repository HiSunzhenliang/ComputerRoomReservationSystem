/************************************ 
	* @file    : student.h
	* @brief   : ѧ������
	* @details : �̳�identity����
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "identity.h"


//ѧ����
class Student:public Identity {
public:
	//ѧ��
	int m_id;
	//������Ϣ ����


	//Ĭ�Ϲ��캯��
	Student( );
	//�вι���
	Student(int id, string name, string password);
	//��ʾ�˵�
	virtual void showSecondMenu( );
	//����ԤԼ
	void applyOrder( );
	//�鿴�ҵ�ԤԼ
	void showMyOrder( );
	//�鿴����ԤԼ
	void showAllOrder( );
	//ȡ��ԤԼ
	void cancelOrder( );
};
