/************************************ 
	* @file    : teacher.cpp
	* @brief   : ��ʦ�ඨ��
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "globalFile.h"
#include "teacher.h"
#include "identity.h"
#include "order.h"
#include "management.h"

void Teacher::initVector( ) {
	//��ȡԤԼ�ļ���Ϣ
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vOrd.clear( );
	Order o;
	while (ifs >> o.date >> o.interval >> o.stuId >> o.stuName >> o.roomId >> o.status) {
		vOrd.push_back(o);
	}
	ifs.close( );
}

void Teacher::vecInitFile( ) {
	if (vOrd.size( ) == 0) {
		cout << "���ļ���¼��";
		system("pause");
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	if (!ofs.is_open( )) {
		cout << "δ���ļ���";
		system("pause");
	}
	for (auto it : vOrd) {
		ofs << it.date << " ";
		ofs << it.interval << " ";
		ofs << it.stuId << " ";
		ofs << it.stuName << " ";
		ofs << it.roomId << " ";
		ofs << it.status << endl;
	}
	ofs.close( );
}

Teacher::Teacher( ) {

}

Teacher::Teacher(int empId, string name, string password) {
	this->m_empId = empId;
	this->m_Name = name;
	this->m_Password = password;
	this->initVector( );
}

void Teacher::showSecondMenu( ) {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Teacher::showAllOrder( ) {
	system("CLS");
	cout << "���м�¼��" << endl;
	if (vOrd.size( ) == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("CLS");
		return;
	}
	int i = 0;
	for (auto it : vOrd) {
		cout << ++i << " ";
		cout << "ԤԼ���ڣ� ��" << it.date << " ";
		cout << "ʱ�Σ�" << it.interval << " ";
		cout << "ѧ����ţ�" << it.stuId << " ";
		cout << "ѧ����" << it.stuName << " ";
		cout << "������" << it.roomId << " ";
		cout << "ԤԼ״̬��" << management::orderStatus(it.status) << endl;
	}
	system("pause");
	system("CLS");
}

void Teacher::checkOrder( ) {
	system("CLS");
	cout << "���м�¼��" << endl;
	if (vOrd.size( ) == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("CLS");
		return;
	}
	int i = 0;
	for (auto it : vOrd) {
		cout << ++i << " ";
		cout << "ԤԼ���ڣ� ��" << it.date << " ";
		cout << "ʱ�Σ�" << it.interval << " ";
		cout << "ѧ����ţ�" << it.stuId << " ";
		cout << "ѧ����" << it.stuName << " ";
		cout << "������" << it.roomId << " ";
		cout << "ԤԼ״̬��" << management::orderStatus(it.status) << endl;
	}
	cout << "����˴��ڡ�����С���ԤԼ���롣" << endl;
	cout << "��������˵ļ�¼: " << endl;
	int select = 0;
	int j = 0;
	while (true) {
		cin >> select;
		if (select >= 1 && select <= i) {	//++++++++++++++++
			for (auto &it : vOrd) {			//auto &it,�ſ��޸�
				j++;						//++++++++++++++++
				if (j == select) {
					//����״̬�޸�
					cout << "��������˽��" << endl;
					cout << "1��ͨ��" << endl;
					cout << "2����ͨ��" << endl;
					int ret = 0;
					cin >> ret;
					while (true) {
						if (ret==1){
							it.status = 2;
							break;
						}
						else if (ret == 2) {
							it.status = -1;
							break;
						}
						else {
							cout << "������������������" << endl;
						}
					}
					this->vecInitFile( );
					this->initVector( );
					cout << "��������" << endl;
					break;
				}
			}
			break;
		}
		else {
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("CLS");
}

