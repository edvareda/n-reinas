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
			casilla* casillatableroTemp = new casilla(); // x03
			casilla* casillatableroIni = new casilla(); //x02
			casilla* casillaTableroAnte = new casilla(); // 06
			casilla* AuxIni = new casilla(); // x01
			cout << "Crear casilla tablero: "<< casillatableroIni << endl;
			casillatableroTemp = casillatableroIni; // x02 
			casillaTableroAnte = NULL;
			for (int i = 1; i < nReinasParam; i++)
			{
				casilla* casillaTableroActual = new casilla(); // x04
				casillatableroTemp->r = casillaTableroActual; // x04
				casillatableroTemp->l = casillaTableroAnte; // Null
				casillaTableroAnte = casillatableroTemp;
				casillatableroTemp = casillaTableroActual; // x04
				cout << casillatableroTemp << endl;
			}
			AuxIni = casillatableroIni;
			cout << "---------------------- Termino el FOR ------------------------" << endl;
			cout << AuxIni << endl;
			cout << casillatableroIni << endl;
			cout << "---------------------- Antes del while ------------------------" << endl;
			while (AuxIni != NULL)
			{
				cout << AuxIni->l << "<-"<< AuxIni << "-> "<< AuxIni->r << endl;
				AuxIni = AuxIni->r;
			}
		}

};

