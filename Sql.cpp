#include <iostream>
#include "Proveedor.h"
using namespace std;


int main()
{
	string nombres, nit, direccion;
	int telefono;

	cout << "Ingrese el nombre del proveedor: ";
	getline(cin, nombres);
	cout << "Ingrese el nit: ";
	getline(cin, nit);
	cout << "Ingrese la direccion del proveedor: ";
	getline(cin, direccion);
	cout << "Ingrese el telefono del proveedor: ";
	cin >> telefono;
	cin.ignore();

	
	proveedor c = proveedor (nombres,direccion,telefono,nit);
	c.crear();
	c.leer();
	system("pause");
	return 0;
}


