/************************************
	* @file    : management.cpp
	* @brief   : ȫ�ֹ�����Ķ���
	* @details :
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "management.h"
using namespace std;


//��ʾ���˵�
void management::showMainMenu( ) {
	cout << "======================  ��ӭʹ�û���ԤԼϵͳ  =====================" << endl;
	cout << "\n\n";
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
	cout << "���������ѡ��" ;
	cin >> this->select;
	switch (select) {
		//ѧ��
	case 1:
		if (Identity *student=this->LogIn(STUDENT_FILE, 1)){
			this->studentMenu(student);
		}
		break;
		//��ʦ
	case 2:
		if (Identity *teacher =this->LogIn(TEACHER_FILE, 2)){
			this->teacherMenu(teacher);
		}
		break;
		//����Ա
	case 3:
		if (Identity *manager =this->LogIn(ADMIN_FILE, 3)){
			this->managerMenu(manager);
		}
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
//��¼����(��Ӧ�����ļ�����Ӧ����)
Identity* management::LogIn(string filename, int identity) {
	Identity *person = nullptr;

	ifstream readFile;
	readFile.open(filename, ios::in);

	//����ļ�������
	if (!readFile.is_open( )) {
		cout << "�ļ������ڣ�" << endl;
		readFile.close( );
		return person;
	}

	int id = 0;
	string name;
	string pwd;
	while (identity == 1 || identity == 2) {
		cout << "�������ţ�" << endl;
		cin >> id;
		break;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	switch (identity) {
	case 1:
		//ѧ����¼��֤
	{
		int fid;
		string fname;
		string fpwd;
		while (readFile >> fid && readFile >> fname && readFile >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "ѧ���˺ŵ�¼�ɹ���" << endl;
				system("pause");
				system("CLS");
				person = new Student(id, name, pwd);
				return person;
			}
		}
	}
	break;
	case 2:
		//��ʦ��¼��֤
	{
		int fid;
		string fname;
		string fpwd;
		while (readFile >> fid && readFile >> fname && readFile >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "��ʦ�˺ŵ�¼�ɹ���" << endl;
				system("pause");
				system("CLS");
				person = new Teacher(id, name, pwd);
				return person;

			}
		}
	}
	break;
	case 3:
		//����Ա��¼��֤
	{
		string fname;
		string fpwd;
		while (readFile >> fname && readFile >> fpwd) {
			if (name == fname && pwd == fpwd) {
				cout << "����Ա�˺ŵ�¼�ɹ���" << endl;
				system("pause");
				system("CLS");
				person = new Manager(name, pwd);
				return person;

			}
		}
	}
	break;
	}
	cout << "��֤ʧ�ܣ�" << endl;
	system("pause");
	system("CLS");
	return person;
}

//ѧ��ѡ��
void management::studentMenu(Identity* &student) {
	while (true){
		//��ʾѧ���˵�
		student->showSecondMenu( );
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			//����ԤԼ
			stu->applyOrder( );
			break;
		case 2:
			//�鿴�Լ�ԤԼ
			stu->showMyOrder();
			break;
		case 3:
			//�鿴ȫ��ԤԼ
			stu->showAllOrder();
			break;
		case 4:
			//ȡ��ԤԼ
			stu->cancelOrder();
			break;
		case 0:
			//ע��
			delete student;
			cout << "ע���ɹ�" << endl;
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
//��ʦѡ��
void management::teacherMenu(Identity* &teacher) {

}
//����Աѡ��
void management::managerMenu(Identity* &manager) {
	while (true) {
		//��ʾ����Ա�˵�
		manager->showSecondMenu( );
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			//����˺�
			man->addUser( );
			break;
		case 2:
			//�鿴�˺�
			man->showUser( );
			break;
		case 3:
			//�鿴����
			man->showRoom( );
			break;
		case 4:
			//���ԤԼ
			man->cleanFile( );
			break;
		case 0:
			//ע��
			delete manager;
			cout << "ע���ɹ�" << endl;
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

//�˳�ϵͳ����
void management::exitSys( ) {
	system("CLS");
	cout << "\n\n��ӭ�´�ʹ�ã�\n\n" << endl;
	system("pause");
	exit(0);
}

