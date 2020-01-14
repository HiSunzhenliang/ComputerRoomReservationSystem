/************************************ 
	* @file    : manager.cpp
	* @brief   : 管理类实现
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

//初始化容器
void Manager::initVector( ) {
	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "文件读取失败" << endl;
		return;
	}
	vStu.clear( );
	Student s;
	while (ifs >> s.m_id&&ifs >> s.m_Name&&ifs >> s.m_Password) {
		vStu.push_back(s);
	}
	ifs.close( );

	//读取教师文件中信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "文件读取失败" << endl;
		return;
	}
	vTea.clear( );
	Teacher t;
	while (ifs >> t.m_empId&&ifs >> t.m_Name&&ifs >> t.m_Password) {
		vTea.push_back(t);
	}
	ifs.close( );

	//读取机房文件中信息
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "文件读取失败" << endl;
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
	//初始化容器
	this->initVector( );
}

void Manager::showSecondMenu( ) {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "学生当前数量为：" << vStu.size( ) << endl;
	cout << "教师当前数量为：" << vTea.size( ) << endl;
	cout << "机房当前数量为：" << vCom.size( ) << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//添加账号
void Manager::addUser( ) {
	system("CLS");
	cout << "\n添加账号：\n";
	string fileName;
	ofstream writeFile;
	int select = 0;
	int mark = 1;//辅助标志

	while (mark) {
		cout << "请输入添加账号的类型" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加老师" << endl;
		cout << "0、退出选择" << endl;
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
			cout << "输入有误，请重新选择！" << endl;
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
		cout << "请输入编号： " << endl;
		cin >> id;
		if (this->isRepeat(id,select)){
			cout << "编号重复！请重新输入。" << endl;
		}
		else {
			break;
		}
	}
	cout << "请输入姓名： " << endl;
	cin >> name;
	cout << "请输入密码： " << endl;
	cin >> pwd;
	writeFile << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;
	writeFile.close( );
	this->initVector( );
	system("pause");
	system("CLS");
}
//查看账户
void Manager::showUser( ) {
	system("CLS");
	int mark = 1;
	int select = 1;
	while (mark) {
		cout << "请输入查看账号的类型" << endl;
		cout << "1、学生" << endl;
		cout << "2、老师" << endl;
		cout << "0、退出选择" << endl;
		cin >> select;
		switch (select) {
		case 1:
			system("CLS");
			cout << "所有学生信息如下： " << endl;
			for (auto it:vStu){
				printStudent(it);
			}
			system("pause");
			system("CLS");
			mark = 0;
			break;
		case 2:
			system("CLS");
			cout << "所有老师信息如下： " << endl;
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
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("CLS");
			break;
		}
	}
}

void Manager::showRoom( ) {
	system("CLS");
	cout << "所有机房信息如下： " << endl;
	for (auto it : vCom) {
		printRoom(it);
	}
	system("pause");
	system("CLS");
}

void Manager::cleanFile( ) {
	system("CLS");
	//文件存在就先删除再重建
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close( );
	cout << "清除成功！" << endl;
	system("pause");
	system("CLS");
}
//去重函数
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
//打印学生信息
void Manager::printStudent(Student &s) {
	cout << "学号： " << s.m_id <<" 姓名： "<< s.m_Name << " 密码： " << s.m_Password << endl;
}
//打印老师信息
void Manager::printTeacher(Teacher &t) {
	cout << "编号： " << t.m_empId << " 姓名： " << t.m_Name << " 密码： " << t.m_Password << endl;
}
//打印机房信息
void Manager::printRoom(ComputerRoom &c ) {
	cout << "编号： " << c.m_ComId << " 容量： " << c.m_MaxNum << endl;
}
