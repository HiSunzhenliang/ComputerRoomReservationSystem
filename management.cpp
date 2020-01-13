/************************************
	* @file    : management.cpp
	* @brief   : 全局管理类的定义
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


//显示主菜单
void management::showMainMenu( ) {
	cout << "======================  欢迎使用机房预约系统  =====================" << endl;
	cout << "\n\n";
	cout << "\t\t ===============================\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t ===============================\n";
}
//选择主菜单选项
void management::choseMainMenuOption( ) {
	cout << "请输入你的选择：" ;
	cin >> this->select;
	switch (select) {
		//学生
	case 1:
		if (Identity *student=this->LogIn(STUDENT_FILE, 1)){
			this->studentMenu(student);
		}
		break;
		//老师
	case 2:
		if (Identity *teacher =this->LogIn(TEACHER_FILE, 2)){
			this->teacherMenu(teacher);
		}
		break;
		//管理员
	case 3:
		if (Identity *manager =this->LogIn(ADMIN_FILE, 3)){
			this->managerMenu(manager);
		}
		break;
		//退出系统
	case 0:
		this->exitSys( );
		break;
	default:
		cout << "输入有误，请重新选择！" << endl;
		system("pause");
		system("CLS");
		break;
	}
}
//登录功能(对应操作文件，对应子类)
Identity* management::LogIn(string filename, int identity) {
	Identity *person = nullptr;

	ifstream readFile;
	readFile.open(filename, ios::in);

	//如果文件不存在
	if (!readFile.is_open( )) {
		cout << "文件不存在！" << endl;
		readFile.close( );
		return person;
	}

	int id = 0;
	string name;
	string pwd;
	while (identity == 1 || identity == 2) {
		cout << "请输入编号：" << endl;
		cin >> id;
		break;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	switch (identity) {
	case 1:
		//学生登录验证
	{
		int fid;
		string fname;
		string fpwd;
		while (readFile >> fid && readFile >> fname && readFile >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "学生账号登录成功！" << endl;
				system("pause");
				system("CLS");
				person = new Student(id, name, pwd);
				return person;
			}
		}
	}
	break;
	case 2:
		//老师登录验证
	{
		int fid;
		string fname;
		string fpwd;
		while (readFile >> fid && readFile >> fname && readFile >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "老师账号登录成功！" << endl;
				system("pause");
				system("CLS");
				person = new Teacher(id, name, pwd);
				return person;

			}
		}
	}
	break;
	case 3:
		//管理员登录验证
	{
		string fname;
		string fpwd;
		while (readFile >> fname && readFile >> fpwd) {
			if (name == fname && pwd == fpwd) {
				cout << "管理员账号登录成功！" << endl;
				system("pause");
				system("CLS");
				person = new Manager(name, pwd);
				return person;

			}
		}
	}
	break;
	}
	cout << "验证失败！" << endl;
	system("pause");
	system("CLS");
	return person;
}

//学生选项
void management::studentMenu(Identity* &student) {
	while (true){
		//显示学生菜单
		student->showSecondMenu( );
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			//申请预约
			stu->applyOrder( );
			break;
		case 2:
			//查看自己预约
			stu->showMyOrder();
			break;
		case 3:
			//查看全部预约
			stu->showAllOrder();
			break;
		case 4:
			//取消预约
			stu->cancelOrder();
			break;
		case 0:
			//注销
			delete student;
			cout << "注销成功" << endl;
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
//教师选项
void management::teacherMenu(Identity* &teacher) {

}
//管理员选项
void management::managerMenu(Identity* &manager) {
	while (true) {
		//显示管理员菜单
		manager->showSecondMenu( );
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			//添加账号
			man->addUser( );
			break;
		case 2:
			//查看账号
			man->showUser( );
			break;
		case 3:
			//查看机房
			man->showRoom( );
			break;
		case 4:
			//清空预约
			man->cleanFile( );
			break;
		case 0:
			//注销
			delete manager;
			cout << "注销成功" << endl;
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

//退出系统功能
void management::exitSys( ) {
	system("CLS");
	cout << "\n\n欢迎下次使用！\n\n" << endl;
	system("pause");
	exit(0);
}

