/************************************ 
	* @file    : student.cpp
	* @brief   : ѧ�����ඨ��
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "computerRoom.h"
#include "globalFile.h"
#include "student.h"
#include "identity.h"
#include "order.h"
#include "management.h"

//��ʼ����������������
void Student::initVector( ) {
	//��ȡ�����ļ�����Ϣ
	fstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vCom.clear( );
	ComputerRoom c;
	while (ifs >> c.m_ComId&&ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	ifs.close( );

	//��ȡԤԼ�ļ���Ϣ
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

//Ĭ�Ϲ��캯��
Student::Student( ) {

}
//�вι���
Student::Student(int id, string name, string password) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Password = password;
	this->initVector( );
}
//��ʾ�˵�
void Student::showSecondMenu( ) {
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����ԤԼ
void Student::applyOrder( ) {
	system("CLS");
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	//���ڣ�������
	int date = 0;
	int interval = 0;
	//����
	int room = 0;

	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "�����������������룺" << endl;
	}

	cout << "��ѡ��ʱ��Σ�" << endl;
	cout << "1������  2������" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "�����������������룺" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "�����������������룺" << endl;
	}
	cout << "\nԤԼ�ɹ�������С�\n";
	//д��order.txt
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << date << " ";
	ofs << interval << " ";
	ofs << this->m_id << " ";
	ofs << this->m_Name << " ";
	ofs << room << " ";
	ofs << 1 << endl;//0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
	ofs.close( );
	//����ԤԼ�ļ�������
	this->initVector( );
	system("pause");
	system("CLS");

}
//�鿴�ҵ�ԤԼ
void Student::showMyOrder( ) {
	system("CLS");
	cout << "ѧ����" << this->m_Name << endl;
	if (vOrd.size( ) == 0) {
		cout << "��ԤԼ��¼��" << endl;
	}
	for (auto it:vOrd){
		if (it.stuId == this->m_id) {
			cout << "ԤԼ���ڣ� ��" << it.date << " ";
			cout << "ʱ�Σ�" << it.interval << " ";
			cout << "������" << it.roomId << " ";
			cout << "ԤԼ״̬��" << management::orderStatus(it.status) << endl;
		}
	}
	system("pause");
	system("CLS");
}
//�鿴����ԤԼ
void Student::showAllOrder( ) {
	system("CLS");
	cout << "���м�¼��" << endl;
	if (vOrd.size( ) == 0) {
		cout << "��ԤԼ��¼��" << endl;
	}
	for (auto it : vOrd) {
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
//ȡ��ԤԼ
void Student::cancelOrder( ) {

}

