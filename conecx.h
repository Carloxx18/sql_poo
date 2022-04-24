#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;

class conecx
{
private :	MYSQL* conectar;
public : void abrir_cx() {
			conectar = mysql_init(0);
			conectar = mysql_real_connect(conectar, "localhost", "root", "canella", "bd_empresa", 3306, NULL, 0);
		}
		MYSQL* getconectar() {
			return conectar;
		}
		void cerrar_cx() {
			mysql_close(conectar);
		}
		
};

