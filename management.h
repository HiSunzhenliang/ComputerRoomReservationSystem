/************************************ 
	* @file    : management.h
	* @brief   : ȫ�ֹ����������
	* @details : ���˵���ʾ��
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#pragma once
#include <iostream>

//������
class management {
public:
	//���˵�ѡ��
	int select;
	//��ʾ���˵�
	void showMainMenu( );
	//ѡ�����˵�ѡ��
	void choseMainMenuOption( );
	//�˳�ϵͳ����
	void exitSys( );
};
