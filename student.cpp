/************************************ 
	* @file    : student.cpp
	* @brief   : 学生子类定义
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

//初始化容器，更新容器
void Student::initVector( ) {
	//读取机房文件中信息
	fstream ifs;
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

	//读取预约文件信息
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

//默认构造函数
Student::Student( ) {

}
//有参构造
Student::Student(int id, string name, string password) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Password = password;
	this->initVector( );
}
//显示菜单
void Student::showSecondMenu( ) {
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//申请预约
void Student::applyOrder( ) {
	system("CLS");
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	//日期，上下午
	int date = 0;
	int interval = 0;
	//房间
	int room = 0;

	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "输入有误！请重新输入：" << endl;
	}

	cout << "请选择时间段：" << endl;
	cout << "1、上午  2、下午" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误！请重新输入：" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << vCom[2].m_MaxNum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误！请重新输入：" << endl;
	}
	cout << "\n预约成功！审核中。\n";
	//写入order.txt
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << date << " ";
	ofs << interval << " ";
	ofs << this->m_id << " ";
	ofs << this->m_Name << " ";
	ofs << room << " ";
	ofs << 1 << endl;//0 取消的预约   1 审核中   2 已预约 -1 预约失败
	ofs.close( );
	//更新预约文件，容器
	this->initVector( );
	system("pause");
	system("CLS");

}
//查看我的预约
void Student::showMyOrder( ) {
	system("CLS");
	cout << "学生：" << this->m_Name << endl;
	if (vOrd.size( ) == 0) {
		cout << "无预约记录！" << endl;
	}
	for (auto it:vOrd){
		if (it.stuId == this->m_id) {
			cout << "预约日期： 周" << it.date << " ";
			cout << "时段：" << it.interval << " ";
			cout << "机房：" << it.roomId << " ";
			cout << "预约状态：" << management::orderStatus(it.status) << endl;
		}
	}
	system("pause");
	system("CLS");
}
//查看所有预约
void Student::showAllOrder( ) {
	system("CLS");
	cout << "所有记录：" << endl;
	if (vOrd.size( ) == 0) {
		cout << "无预约记录！" << endl;
	}
	for (auto it : vOrd) {
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
//取消预约
void Student::cancelOrder( ) {

}

