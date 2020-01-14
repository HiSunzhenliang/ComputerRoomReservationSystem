/************************************ 
	* @file    : teacher.cpp
	* @brief   : 教师类定义
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
	//读取预约文件信息
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open( )) {
		cout << "文件读取失败" << endl;
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
		cout << "无文件记录！";
		system("pause");
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	if (!ofs.is_open( )) {
		cout << "未打开文件！";
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
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Teacher::showAllOrder( ) {
	system("CLS");
	cout << "所有记录：" << endl;
	if (vOrd.size( ) == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("CLS");
		return;
	}
	int i = 0;
	for (auto it : vOrd) {
		cout << ++i << " ";
		cout << "预约日期： 周" << it.date << " ";
		cout << "时段：" << it.interval << " ";
		cout << "学生编号：" << it.stuId << " ";
		cout << "学生：" << it.stuName << " ";
		cout << "机房：" << it.roomId << " ";
		cout << "预约状态：" << management::orderStatus(it.status) << endl;
	}
	system("pause");
	system("CLS");
}

void Teacher::checkOrder( ) {
	system("CLS");
	cout << "所有记录：" << endl;
	if (vOrd.size( ) == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("CLS");
		return;
	}
	int i = 0;
	for (auto it : vOrd) {
		cout << ++i << " ";
		cout << "预约日期： 周" << it.date << " ";
		cout << "时段：" << it.interval << " ";
		cout << "学生编号：" << it.stuId << " ";
		cout << "学生：" << it.stuName << " ";
		cout << "机房：" << it.roomId << " ";
		cout << "预约状态：" << management::orderStatus(it.status) << endl;
	}
	cout << "请审核处于“审核中”的预约申请。" << endl;
	cout << "请输入审核的记录: " << endl;
	int select = 0;
	int j = 0;
	while (true) {
		cin >> select;
		if (select >= 1 && select <= i) {	//++++++++++++++++
			for (auto &it : vOrd) {			//auto &it,才可修改
				j++;						//++++++++++++++++
				if (j == select) {
					//进行状态修改
					cout << "请输入审核结果" << endl;
					cout << "1、通过" << endl;
					cout << "2、不通过" << endl;
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
							cout << "输入有误，请重新输入" << endl;
						}
					}
					this->vecInitFile( );
					this->initVector( );
					cout << "已完成审核" << endl;
					break;
				}
			}
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("CLS");
}

