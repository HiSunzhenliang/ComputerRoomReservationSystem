/************************************ 
	* @file    : main.cpp
	* @brief   : ³ÌÐòÈë¿Ú
	* @details : 
	* @author  : Alliswell
	* @date    : 2020-1-13
************************************/
#include <iostream>
#include "management.h"
using namespace std;

int main( ) {
	management manage;
	while (true){
		manage.showMainMenu( );
		manage.choseMainMenuOption( );
	}
}