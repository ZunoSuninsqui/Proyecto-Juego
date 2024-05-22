#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <utility> // Para std::pair
#include <cctype> // Para isdigit
#include <cstdlib> // Para system("pause") y system("cls")

using namespace std;

void AtajoBiblioteca(){
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorno Atajo biblioteca" << endl;
		cout << "1. Ardilla" << endl;
		cout << "2. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					//Ardilla
					system("pause");
					break;
				case 2:
					cout<<"Volviendo"<<endl;
					system("pause");
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
		}
	} while (f);
}

void Colegio(){
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorno Colegio" << endl;
		cout << "1. Camino a la biblioteca" << endl;
		cout << "2. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					//Interaccion estudiante
					system("pause");
					break;
				case 2:
					cout<<"Volviendo"<<endl;
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
		}
	} while (f);
}

void FacultadDeDerecho(){
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorno Facultad de derecho" << endl;
		cout << "1. Secretaria" << endl;
		cout << "2. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					//Secretaria
					system("pause");
					break;
				case 2:
					cout<<"Volviendo"<<endl;
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
		}
	} while (f);
}

void BloqueM(){
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorn Bloque M" << endl;
		cout << "1. Estudiante" << endl;
		cout << "2. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					//Interaccion estudiante
					system("pause");
					break;
				case 2:
					cout<<"Volviendo"<<endl;
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
		}
	} while (f);
}

void EscalasALosM(){
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorno Escaleras a los M" << endl;
		cout << "1. Colegio" << endl;
		cout << "2. Facultad de derecho" << endl;
		cout << "3. Bloque M" << endl;
		cout << "4. Volver"<<endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					Colegio();
					system("pause");
					break;
				case 2:
					FacultadDeDerecho();
					system("pause");
					break;
				case 3:
					BloqueM();
					system("pause");
					break;
				case 4:
					cout<<"Volviendo"<<endl;
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
		}
	} while (f);
}

void Elevador(){
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorno Elevador" << endl;
		cout << "1. Oficinas" << endl;
		cout << "2. Ultimo piso" << endl;
		cout << "3. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					//Oficinas();
					system("pause");
					break;
				case 2:
					//Ultimo piso
					system("pause");
					break;
				case 3:
					cout<<"Volviendo"<<endl;
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
			
		}
	} while (f);
}

void FacultadAgronomia(){
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorno Facultad Agronomia" << endl;
		cout << "1. Informacion facultad" << endl;
		cout << "2. Escalas a los M" << endl;
		cout << "3. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					//Informacion facultad
					system("pause");
					break;
				case 2:
					EscalasALosM();
					system("pause");
					break;
				case 3:
					cout<<"Volviendo"<<endl;
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
		}
	} while (f);
}

void BancasConPedales() {
	bool f= true;
	do {
		system("cls");
		char g;
		cout << "Entorno Bancas con pedales" << endl;
		cout << "1. Mejora de Stats" << endl;
		cout << "2. Escalas a los M" << endl;
		cout << "3. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					//Mejora de Stats
					system("pause");
					break;
				case 2:
					EscalasALosM();
					system("pause");
					break;
				case 3:
					cout<<"Volviendo"<<endl;
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
			
		}
	} while (f);
}

void bloqueE() {
	bool f=true;
	do {
		system("cls");
		char g;
		cout << "Entorno bloque E" << endl;
		cout << "1. Bancas Con pedales" << endl;
		cout << "2. Facultad agronomia" << endl;
		cout << "3. Volver" << endl;
		cin>>g;
		cin.ignore();
		if (isdigit(g)) {
			int g1 = g-'0';
			switch (g1) {
				case 1:
					BancasConPedales();
					system("pause");
					break;
				case 2:
					FacultadAgronomia();
					system("pause");
					break;
				case 3:
					cout<<"Volviendo"<<endl;
					system("pause");
					f= false;
					break;
				default:
					cout<<"seleccione opcion valida"<<endl;
					system("pause");
					break;
			}
		}
	} while (f);
}

void innovamater() {
	system("cls");
	bool f = true;
	do {
		system("cls");
		char v;
		cout << "Entorno Innovamater" << endl;
		cout << "1. Hablar con la recepcionista" << endl;
		cout << "2. Elevador" << endl;
		cout << "3. Volver" << endl;
		cin>>v;
		cin.ignore();
		if (isdigit(v)) {
			int v1 = v-'0';
			switch (v1) {
				case 1:
					//InteraccionRecepcionista();
					break;
				case 2:
					Elevador();
					break;
				case 3:
					f = false;
					break;

				default:

					break;
			}
		}

	} while(f);
}

void porteriaInnovamater() {
	bool f = true;
	system("cls");
	cout << "*Llegas a la universidad, miras a tu alrededor*" << endl;
	system("pause");
	do {
		system("cls");
		char a;
		cout << "1.Bloque E" << endl;
		cout << "2.Innovamater" << endl;
		cout << "3. Quit" << endl;
		cin >> a;
		cin.ignore();
		if (isdigit(a)) {
			int a1 = a-'0';
			switch (a1){
				case 1:
					bloqueE();
					break;
				case 2:
					innovamater();
					break;
				case 3:
					f = false;
					cout<<"Saliendo del juego"<<endl;
					system("pause");
			}
		} else {
			cout << "Ingrese una opción válida." << endl;
		}
	} while (f); // Cambia la condición de salida según necesites
}

void jugar() {
	porteriaInnovamater();
}

void menu() {
	bool SalirMenu = true;
	do {
		system("cls");
		char opcion;
		cout << "'Menu juego'" << endl;
		cout << "1. Jugar" << endl;
		cout << "2. Config" << endl;
		cout << "3. Salir" << endl;
		cin >> opcion;
		if (isdigit(opcion)) {
			int opcion1 = opcion - '0';
			switch (opcion1) {
				case 1:
					jugar();
					break;
				case 2:
					// Lógica para la configuración
					break;
				case 3:
					cout << "Saliendo del programa" << endl;
					system("pause");
					SalirMenu = false;
					break;
				default:
					cout << "Ingrese opción válida" << endl;
					system("pause");
					break;
			}
		} else {
			cout << "Ingrese opción válida" << endl;
			system("pause");
		}
	} while (SalirMenu);
}

int main() {
	
	menu();

	return 0;
}
