/************************************ 
	* @file    : student.cpp
	* @brief   : ѧ�����ඨ��
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include <string>
#include "student.h"
#include "identity.h"
//Ĭ�Ϲ��캯��
Student::Student( ) {

}
//�вι���
Student::Student(int id, string name, string password) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Password = password;
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

}
//�鿴�ҵ�ԤԼ
void Student::showMyOrder( ) {

}
//�鿴����ԤԼ
void Student::showAllOrder( ) {

}
//ȡ��ԤԼ
void Student::cancelOrder( ) {

}

