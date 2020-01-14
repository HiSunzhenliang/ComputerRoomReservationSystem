/************************************ 
	* @file    : manager.h
	* @brief   : ����Ա����
	* @details : �̳�identity����
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "identity.h"

//����Ա��
class Manager:public Identity {
public:
	//ά���������������ڸ����ļ�������
	vector<Student> vStu;
	vector<Teacher> vTea;
	//������ʼ��
	void initVector( );
	//Ĭ�Ϲ���
	Manager( );
	//�вι���
	Manager(string name, string password);
	//�˵�
	virtual void showSecondMenu( );
	//����˺�
	void addUser( );
	//�鿴�˺�
	void showUser( );
	//�鿴����
	void showRoom( );
	//�����Ϣ
	void cleanFile( );
	//ȥ�غ���
	bool isRepeat(int id, int identity);
	//��ӡѧ����Ϣ
	void printStudent(Student &s);
	//��ӡ��ʦ��Ϣ
	void printTeacher(Teacher &t);
	//��ӡ������Ϣ
	void printRoom( );
};