/************************************ 
	* @file    : management.cpp
	* @brief   : ȫ�ֹ�����Ķ���
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include "management.h"
using namespace std;


//��ʾ���˵�
void management::showMainMenu( ) {
	cout << "======================  ��ӭʹ�û���ԤԼϵͳ  =====================" << endl;
	cout << "\t\t ===============================\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ===============================\n";
}
//ѡ�����˵�ѡ��
void management::choseMainMenuOption( ) {
	cout << "���������ѡ��" << endl;
	cin >> this->select;
	switch (select) {
	//ѧ��
	case 1:
		break;
	//��ʦ
	case 2:
		break;
	//����Ա
	case 3:
		break;
	//�˳�ϵͳ
	case 0:
		this->exitSys( );
		break;
	default:
		cout << "��������������ѡ��" << endl;
		system("pause");
		system("CLS");
		break;
	}
}
//�˳�ϵͳ����
void management::exitSys( ) {
	system("CLS");
	cout << "\n\n��ӭ�´�ʹ�ã�\n\n" << endl;
	system("pause");
	exit(0);
}

