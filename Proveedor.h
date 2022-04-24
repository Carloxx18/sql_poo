#include <mysql.h>
#include "persona.h"
#include <iostream>
#include "conecx.h"
#include<string>
class proveedor : persona
{
private: string nit;
	   
public:
	proveedor() {
	}
	proveedor(string nom, string ape, string dir, int tel, string fn, string n) : persona(nom, ape, dir, tel, fn) {
		nit = n;
	}

	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	

	string getNit() { return nit; }
	string getNombres() { return nombres; }
	
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	
	
	void crear() {
		int q_estado;
		conecx cn = conecx();
		cn.abrir_cx();
		if (cn.getconectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO proveedor(proveedor,nit,direccion,telefono)VALUES('" + nombres + "','" + nit + "','" + direccion + "',"+t+");";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado)
			{
				cout<<"Se ingreso correctramente" << endl;
			}
			else {
				cout<< "No ingreso correctramente" << endl;
			}

		}
		else
		{
			cout << "error al conectar" << endl;
		}
		cn.cerrar_cx();

		
	}

	void leer() 
	{
		int q_estado;
		conecx cn = conecx();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_cx();
		if (cn.getconectar()) {
			string consulta = "select * from proveedor";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado)
			{
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << endl;
				}

			}
			else {
				cout << "consulta fallida" << endl;
			}
		}
		else
		{
			cout << "error al conectar" << endl;
		}
		cn.cerrar_cx();
	}
};
