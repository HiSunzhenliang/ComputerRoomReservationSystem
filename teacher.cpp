/************************************ 
	* @file    : teacher.cpp
	* @brief   : 教师类定义
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include <string>
#include "teacher.h"
#include "identity.h"

Teacher::Teacher( ) {

}

Teacher::Teacher(int empId, string name, string password) {
	this->m_empId = empId;
	this->m_Name = name;
	this->m_Password = password;
}

void Teacher::showSecondMenu( ) {

}

void Teacher::showAllOrder( ) {

}

void Teacher::checkOrder( ) {

}

