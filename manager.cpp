/************************************ 
	* @file    : manager.cpp
	* @brief   : ������ʵ��
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "identity.h"
#include "management.h"
#include "computerRoom.h"
using namespace std;

//��ʼ������
void Manager::initVector( ) {
	//��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vStu.clear( );
	Student s;
	while (ifs >> s.m_id&&ifs >> s.m_Name&&ifs >> s.m_Password) {
		vStu.push_back(s);
	}
	ifs.close( );

	//��ȡ��ʦ�ļ�����Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vTea.clear( );
	Teacher t;
	while (ifs >> t.m_empId&&ifs >> t.m_Name&&ifs >> t.m_Password) {
		vTea.push_back(t);
	}
	ifs.close( );

	//��ȡ�����ļ�����Ϣ
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
}

Manager::Manager( ) {

}

Manager::Manager(string name, string password) {
	this->m_Name = name;
	this->m_Password = password;
	//��ʼ������
	this->initVector( );
}

void Manager::showSecondMenu( ) {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "ѧ����ǰ����Ϊ��" << vStu.size( ) << endl;
	cout << "��ʦ��ǰ����Ϊ��" << vTea.size( ) << endl;
	cout << "������ǰ����Ϊ��" << vCom.size( ) << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�
void Manager::addUser( ) {
	system("CLS");
	cout << "\n����˺ţ�\n";
	string fileName;
	ofstream writeFile;
	int select = 0;
	int mark = 1;//������־

	while (mark) {
		cout << "����������˺ŵ�����" << endl;
		cout << "1�����ѧ��" << endl;
		cout << "2�������ʦ" << endl;
		cout << "0���˳�ѡ��" << endl;
		cin >> select;
		switch (select) {
		case 1:
			fileName = STUDENT_FILE;
			mark = 0;
			break;
		case 2:
			fileName = TEACHER_FILE;
			mark = 0;
			break;
		case 0:
			system("pause");
			system("CLS");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("CLS");
			break;
		}
	}
	writeFile.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	while (true){
		cout << "�������ţ� " << endl;
		cin >> id;
		if (this->isRepeat(id,select)){
			cout << "����ظ������������롣" << endl;
		}
		else {
			break;
		}
	}
	cout << "������������ " << endl;
	cin >> name;
	cout << "���������룺 " << endl;
	cin >> pwd;
	writeFile << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;
	writeFile.close( );
	this->initVector( );
	system("pause");
	system("CLS");
}
//�鿴�˻�
void Manager::showUser( ) {
	system("CLS");
	int mark = 1;
	int select = 1;
	while (mark) {
		cout << "������鿴�˺ŵ�����" << endl;
		cout << "1��ѧ��" << endl;
		cout << "2����ʦ" << endl;
		cout << "0���˳�ѡ��" << endl;
		cin >> select;
		switch (select) {
		case 1:
			system("CLS");
			cout << "����ѧ����Ϣ���£� " << endl;
			for (auto it:vStu){
				printStudent(it);
			}
			system("pause");
			system("CLS");
			mark = 0;
			break;
		case 2:
			system("CLS");
			cout << "������ʦ��Ϣ���£� " << endl;
			for (auto it:vTea){
				printTeacher(it);
			}
			system("pause");
			system("CLS");
			mark = 0;
			break;
		case 0:
			system("pause");
			system("CLS");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("CLS");
			break;
		}
	}
}

void Manager::showRoom( ) {
	system("CLS");
	cout << "���л�����Ϣ���£� " << endl;
	for (auto it : vCom) {
		printRoom(it);
	}
	system("pause");
	system("CLS");
}

void Manager::cleanFile( ) {
	system("CLS");
	//�ļ����ھ���ɾ�����ؽ�
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close( );
	cout << "����ɹ���" << endl;
	system("pause");
	system("CLS");
}
//ȥ�غ���
bool Manager::isRepeat(int id, int identity) {
	switch (identity) {
	case 1:
		for (auto it = vStu.begin( ); it != vStu.end( ); it++) {
			if (id==it->m_id) {
				return true;
			}
		}
		return false;
		break;
	case 2:
		for (auto it = vTea.begin( ); it != vTea.end( ); it++) {
			if (id == it->m_empId) {
				return true;
			}
		}
		return false;
		break;
	}
	return false;
}
//��ӡѧ����Ϣ
void Manager::printStudent(Student &s) {
	cout << "ѧ�ţ� " << s.m_id <<" ������ "<< s.m_Name << " ���룺 " << s.m_Password << endl;
}
//��ӡ��ʦ��Ϣ
void Manager::printTeacher(Teacher &t) {
	cout << "��ţ� " << t.m_empId << " ������ " << t.m_Name << " ���룺 " << t.m_Password << endl;
}
//��ӡ������Ϣ
void Manager::printRoom(ComputerRoom &c ) {
	cout << "��ţ� " << c.m_ComId << " ������ " << c.m_MaxNum << endl;
}
