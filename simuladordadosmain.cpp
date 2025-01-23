//Simulador Lanzador de dados para Dungeons and Dragons
//Angel Cervera Ronda
//Version 1.0

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

void estaticadados(int caras, int resultado){
	
	cout << "--Visualizacion de tirada unica--"<< endl << endl;
	if (caras == 2){
		if (resultado == 1){
			cout << "   +++++   "<< endl;
			cout << "  +     +  "<< endl;
			cout << " +       + "<< endl;
			cout << "+  O   O  +"<< endl;
			cout << "+         +"<< endl;
			cout << "+         +"<< endl;
			cout << "+         +"<< endl;
			cout << "+  |___|  +"<< endl;
			cout << " +       + "<< endl;
			cout << "  +     +  "<< endl;
			cout << "   +++++   "<< endl;
		}
		else{
			cout << "   +++++   "<< endl;
			cout << "  +     +  "<< endl;
			cout << " +       + "<< endl;
			cout << "+         +"<< endl;
			cout << "+  *   *  +"<< endl;
			cout << "+    *    +"<< endl;
			cout << "+  *   *  +"<< endl;
			cout << "+         +"<< endl;
			cout << " +       + "<< endl;
			cout << "  +     +  "<< endl;
			cout << "   +++++   "<< endl;
		}
	}
	else if(caras == 4){
		if (resultado == 1){
			cout << "     +     "<< endl;
			cout << "    + +    "<< endl;
			cout << "   +   +   "<< endl;
			cout << "  +  1  +  "<< endl;
			cout << " +       + "<< endl;
			cout << "+++++++++++"<< endl;
		}
		else if (resultado == 2){
			cout << "     +     "<< endl;
			cout << "    + +    "<< endl;
			cout << "   +   +   "<< endl;
			cout << "  +  2  +  "<< endl;
			cout << " +       + "<< endl;
			cout << "+++++++++++"<< endl;
		}
		else if (resultado == 3){
			cout << "     +     "<< endl;
			cout << "    + +    "<< endl;
			cout << "   +   +   "<< endl;
			cout << "  +  3  +  "<< endl;
			cout << " +       + "<< endl;
			cout << "+++++++++++"<< endl;
		}
		else{
			cout << "     +     "<< endl;
			cout << "    + +    "<< endl;
			cout << "   +   +   "<< endl;
			cout << "  +  4  +  "<< endl;
			cout << " +       + "<< endl;
			cout << "+++++++++++"<< endl;
		}
	}
	else if (caras == 6){
		cout << "+++++++" << endl;
		if (resultado == 1){
			cout << "+     +" << endl;
			cout << "+     +" << endl;
			cout << "+  *  +" << endl;
			cout << "+     +" << endl;
			cout << "+     +" << endl;
		}
		else if (resultado == 2){
			cout << "+     +" << endl;
			cout << "+ *   +" << endl;
			cout << "+     +" << endl;
			cout << "+   * +" << endl;
			cout << "+     +" << endl;
		}
		else if (resultado == 3){
			cout << "+   * +" << endl;
			cout << "+     +" << endl;
			cout << "+  *  +" << endl;
			cout << "+     +" << endl;
			cout << "+ *   +" << endl;
		}
		else if (resultado == 4){
			cout << "+     +" << endl;
			cout << "+ * * +" << endl;
			cout << "+     +" << endl;
			cout << "+ * * +" << endl;
			cout << "+     +" << endl;
		}
		else if (resultado == 5){
			cout << "+     +" << endl;
			cout << "+ * * +" << endl;
			cout << "+  *  +" << endl;
			cout << "+ * * +" << endl;
			cout << "+     +" << endl;
		}
		else{
			cout << "+ * * +" << endl;
			cout << "+     +" << endl;
			cout << "+ * * +" << endl;
			cout << "+     +" << endl;
			cout << "+ * * +" << endl;
		}
		cout << "+++++++" << endl;
	}
	cout << endl;
	
}

void lanzador(int numero, string respuesta){
	int caras;
	int min = 1;
	int valortotal = 0;
	srand(time(0));
	vector<int> dados(numero);

	if(respuesta == "n"){

		for (int i = 0; i < numero; i++){

			cout << "Introduce el numero de caras del dado numero "<< i+1 <<": [2,4,6,8,10,12,20]: ";

			cin >> dados[i];
			cout << endl;

			if (cin.fail()){
				cout << "El valor introducido no es un numero" << endl;
				break;
			}


			if(dados[i] != 2 && dados[i] != 4 && dados[i] != 6 && dados[i] != 8 && dados[i] != 10 && dados[i] != 12 && dados[i] != 20)
			{
				cout << "Valor introducido incorrecto" << endl << endl;
				break;
			}
		}
	}

	else if (respuesta == "y"){
		int caras;
		cout << "Introduce el numero de caras de los dados: [2,4,6,8,10,12,20]: ";
		cin >> caras;
		cout << endl;

		if (cin.fail()){
			cout << "El valor introducido no es un numero" << endl;
		}
		else if(caras != 2 && caras != 4 && caras != 6 && caras != 8 && caras != 10 && caras != 12 && caras != 20)
		{
			cout << "Valor introducido incorrecto" << endl;
		}
		else{
			for (int i = 0; i < numero; i++){
				dados[i] = caras;
			}
		}

	}

	if(numero == 1)
	{
		int generado = min + (rand() % (dados[0] - min + 1));
		cout << "Resultado 1d" << dados[0] << " = " << generado << endl << endl;
		estaticadados(dados[0],generado);
	}
	else {
		cout << "--Visualizacion de tirada multiple--"<< endl << endl;
		for (int i = 0; i < numero; i++){
			int generado = min + (rand() % (dados[i] - min + 1));
			cout << "Resultado 1d" << dados[i] << " = " << generado << endl;
			valortotal =  valortotal + generado;
		}
		cout << "Resultado total: " << valortotal << endl;
	}
	
	
	cout << endl << endl;
}
	


int main(){

cout << "Simulador de lanzador de dados para Dungeons and Dragons" << endl << endl;


int numero;
string respuesta = "y";

cout << "Introduce el numero de dados que quieres lanzar: ";
cin >> numero;
cout << endl;

if (cin.fail()){
	cout << "El valor introducido no es un numero" << endl;
}
else{
	if (numero <= 0){
	cout << "El numero da dados ha de ser positivo" << endl;
	}
	else if (numero > 0){

		if (numero > 1){
		cout << "Los dados son del mismo tipo? (y/n): ";
		cin >> respuesta;
		}

		if (respuesta != "y" && respuesta != "n"){
			cout << "Valor introducido incorrecto" << endl;
		}
		else


		lanzador(numero,respuesta);
	}
}

cout << "Presiona Enter para salir..." << endl;
cin.get();

return 0;
}
