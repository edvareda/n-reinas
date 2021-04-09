#pragma once
#include <iostream>
#include <stdlib.h>
#include "casilla.h"
using namespace std;
class utils
{
public:
	int nReinas;
	utils() {
		nReinas = 0;
	}

	void selectnReinas() {
		cout << "Ingresa la cantidad de Reinas: ";
		cin >> nReinas;
	}
	void tablero(int nReinasParam) {
		casilla* casillatableroTempH = new casilla(); // x03. Creamos casilla temporal
		casilla* casillatableroIniH = new casilla(); //x02. Creamos casilla inicial
		casilla* casillaTableroAnteH = new casilla(); // 06. Creamos casilla anterior
		casilla* AuxIniV = new casilla(); // x01. Creamos casilla auxiliar
		casilla* AuxIniH = new casilla(); // x01. Creamos casilla auxiliar

		casillatableroTempH = casillatableroIniH; // x02. Hacemos que la casilla temporal, sea la misma quie la inicial, pues
												// la temporal es la que recorrerá todo el vector
		casillaTableroAnteH = NULL;				//NULL. Al iniciar, no hay casilla anterior, por lo tanto ser+ia NULL
		for (int i = 0; i < nReinasParam; i++)
		{
			casilla* casillaTableroActualH = new casilla(); // x04. Creamos el espacio de memoria de cada casilla creada en ese ciclo
			if (i != nReinasParam-1)
			{
			//Este for es para crear la lista 
			casillatableroTempH->r = casillaTableroActualH; // x02 -> x04. Asignamos a la casilla temporal la dirección derecha de la casilla creada en ese bucle
			casillatableroTempH->l = casillaTableroAnteH; // x02 -> NULL. Asignamos a la casilla temporal la dirección izquierda de la casilla creada en ese bucle
			casillaTableroAnteH = casillatableroTempH; // La casilla anterior se mueve a la temporal, o sea que se recorre en una posición a la derecha
			}
			//Siguiente FOR para hacer la Matriz-------------------------------------------------------------------------------------
			casilla* casillatableroTempV = new casilla();//anterior
			casillatableroTempV = casillatableroTempH;

			cout << "VERTICAL, SEGUNDO FOR----------------------------------------------------------------- " << endl;
			for (int j = 1; j < nReinasParam; j++)
			{
				casilla* casillaTableroActualV = new casilla(); //actual
				casillatableroTempV->d = casillaTableroActualV;
				casillaTableroActualV->u = casillatableroTempV;
				casillatableroTempV = casillaTableroActualV;
				//casillaTableroActualV->u = casillatableroTempV; POR SI ACASO MAS ADELANTEEE333E3E3E3

			}
			AuxIniV = casillatableroTempH;
			while (AuxIniV != NULL)
			{
				cout<< AuxIniV->u << " <-" << AuxIniV << "-> " << AuxIniV->d << endl;
				AuxIniV = AuxIniV->d;
			}
			casillatableroTempH = casillaTableroActualH; // x04. La casilla temporal se mueve a la actual, o sea que se recorre una posicíón a la derecha
			casillatableroTempH->l = casillaTableroAnteH; // asignamos la dirección de memoria de la casilla anterior
		}
		cout << "HORIZONTAL, PRIMER FOR----------------------------------------------------------------- " << endl;
		AuxIniH = casillatableroIniH;
		while (AuxIniH != NULL)
		{
			cout << AuxIniH->l << " <-" << AuxIniH << "-> " << AuxIniH->r << endl;
			AuxIniH = AuxIniH->r;
		}


	
	}

};
