/************************************ 
	* @file    : management.h
	* @brief   : ȫ�ֹ����������
	* @details : ���˵���ʾ��
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "management.h"

//������
class management {
public:
	//���˵�ѡ��
	int select;
	//��ʾ���˵�
	void showMainMenu( );
	//ѡ�����˵�ѡ��
	void choseMainMenuOption( );
	//��¼����(��Ӧ�����ļ�����Ӧ����)
	Identity* LogIn(string filename, int identity);
	//ѧ��ѡ��
	void studentMenu(Identity* &student);
	//��ʦѡ��
	void teacherMenu(Identity* &teacher);
	//����Աѡ��
	void managerMenu(Identity* &manager);

	//�˳�ϵͳ����
	void exitSys( );
};
