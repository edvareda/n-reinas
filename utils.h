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

	void crearMatriz() {
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
			if (i != nReinasParam - 1)
			{
				//Este for es para crear la lista 
				casillatableroTempH->r = casillaTableroActualH; // x02 -> x04. Asignamos a la casilla temporal la dirección derecha de la casilla creada en ese bucle
	//--- este pudo ser omitido, es lo que decias porque se repite en la linea 59			casillatableroTempH->l = casillaTableroAnteH; // x02 -> NULL. Asignamos a la casilla temporal la dirección izquierda de la casilla creada en ese bucle
				casillaTableroAnteH = casillatableroTempH; // La casilla anterior se mueve a la temporal, o sea que se recorre en una posición a la derecha
			}
			//Siguiente FOR para hacer la Matriz-------------------------------------------------------------------------------------
			casilla* casillatableroTempV = new casilla();//temporal
			casillatableroTempV = casillatableroTempH;

			for (int j = 1; j < nReinasParam; j++)
			{
				casilla* casillaTableroActualV = new casilla(); //actual
				casillatableroTempV->d = casillaTableroActualV;
				casillaTableroActualV->u = casillatableroTempV;

				if (casillatableroTempV->l != NULL)
				{
					//Referenciando a la izquierda en ambos sentidos
					casillaTableroActualV->l = casillatableroTempV->l->d;
					casillaTableroActualV->l->r = casillaTableroActualV;
					//Referenciando a la izquierda superior en ambos sentidos
					casillaTableroActualV->eul = casillatableroTempV->l;
					casillaTableroActualV->eul->edr = casillaTableroActualV;
					//Referenciando a la derecha superior en ambos sentidos
					casillaTableroActualV->l->eur = casillatableroTempV;
					casillatableroTempV->edl = casillaTableroActualV->l;
				}

				//casillaTableroActualV->u = casillatableroTempV; POR SI ACASO MAS ADELANTEEE333E3E3E3
				casillatableroTempV = casillaTableroActualV;
			}
			AuxIniV = casillatableroTempH;
			/*
			while (AuxIniV != NULL)
			{
				cout<< AuxIniV->u << " <-" << AuxIniV << "-> " << AuxIniV->d << endl;
				AuxIniV = AuxIniV->d;
			}
			*/
			casillatableroTempH = casillaTableroActualH; // x04. La casilla temporal se mueve a la actual, o sea que se recorre una posicíón a la derecha
			casillatableroTempH->l = casillaTableroAnteH; // asignamos la dirección de memoria de la casilla anterior
		}

		AuxIniH = casillatableroIniH;
		/*
		while (AuxIniH != NULL)
		{
			cout << AuxIniH->l << " <-" << AuxIniH << "-> " << AuxIniH->r << endl;
			AuxIniH = AuxIniH->r;
		}
		*/

		/*
		AuxIniH = casillatableroIniH->r->r->d;
		cout << "\n---------------CASILLA TOTAL----------------------------------------------------------------- \n" << endl;
			cout << "   eul  " << " |" << "   u    " << "  | " << "   eur" << endl;
			cout << AuxIniH->eul << " <-" << AuxIniH->u << "-> " << AuxIniH->eur << endl;
			cout << AuxIniH->l << " <-" << AuxIniH << "-> " << AuxIniH->r << endl;
			cout << AuxIniH->edl << " <-" << AuxIniH->d << "-> " << AuxIniH->edr << endl;
			cout << "   edl  " << " |" << "   d    " << "  | " << "   edr" << endl;
		*/
		//comprobacion(casillatableroIniH);
		crearReinas(casillatableroIniH);
	}
	bool esCasillaSegura(casilla* casillatableroIniH) {
		casilla* aux = casillatableroIniH;
		casilla* auxU = aux;
		casilla* auxD = aux;
		casilla* auxL = aux;
		casilla* auxR = aux;
		casilla* auxEUL = aux;
		casilla* auxEUR = aux;
		casilla* auxEDL = aux;
		casilla* auxEDR = aux;

		/*while (auxU != NULL)
		{
			if (auxU->getEstado())
			{
				seguro = false;
			}
			auxU = auxU->u;
		}
		while (auxD != NULL)
		{
			if (auxD->getEstado())
			{
				seguro = false;
			}
			auxD = auxD->u;
		}*/
		/*while (auxR != NULL)
		{
			if (auxR->getEstado())
			{
				seguro = false;
			}
			auxR = auxR->u;
		}*/
		/*while (auxEUR != NULL)
		{
			if (auxEUR->getEstado())
			{
				seguro = false;
			}
			auxEUR = auxEUR->u;
		}
		while (auxEDR != NULL)
		{
			if (auxEDR->getEstado())
			{
				seguro = false;
			}
			auxEDR = auxEDR->u;
		}*/
		while (auxEUL != NULL)
		{
			if (auxEUL->getEstado())
			{
				return false;
			}
			auxEUL = auxEUL->eul;
		}
		while (auxL != NULL)
		{
			if (auxL->getEstado())
			{
				return false;
			}
			auxL = auxL->l;
		}
		while (auxEDL != NULL)
		{
			if (auxEDL->getEstado())
			{
				return false;
			}
			auxEDL = auxEDL->edl;
		}
		return true;

	}
	void crearReinas(casilla* casillaInicial) {
		casilla* reinaTemp = new casilla();
		reinaTemp = casillaInicial;
		while (reinaTemp != NULL)
		{ 
			cout << "\nReina temporal: " << reinaTemp << endl;
			cout << "Reina->u: " << reinaTemp->u << endl;
			cout << "Reina->d: " << reinaTemp->d << endl;
			reinaTemp->sr = reinaTemp->d;
			if (reinaTemp->sr != NULL)
			{
				reinaTemp->sr->ar = reinaTemp;
			}
			cout << "Reina->sr: " << reinaTemp->sr << endl;
			reinaTemp->setEstado(1);
			reinaTemp->ar = reinaTemp->u;
			if (reinaTemp->ar!=NULL)
			{
				reinaTemp->ar->sr = reinaTemp;
			}
			cout << "Reina->ar: " << reinaTemp->ar << endl;
			reinaTemp = reinaTemp->d;


			cout << "---------------------" << endl;
		}
		//this->imprimirTablero(casillaInicial);
		resolver(obtenerUltEle(casillaInicial), casillaInicial);
	}

	void imprimirTablero(casilla* casillaInicial) {
		casilla* casillaTempV = new casilla();
		casillaTempV = casillaInicial;
		while (casillaTempV != NULL)
		{
			casilla* casillaTempH = new casilla();
			casillaTempH = casillaTempV;
			//cout << casillaTempV->getEstado();
			while (casillaTempH != NULL)
			{
				if (casillaTempH->r == NULL)
				{
					cout << casillaTempH->getEstado() <<" "<< endl;
				}
				else
				{
					cout << casillaTempH->getEstado() << " ";
				}
				casillaTempH = casillaTempH->r;
			}
			casillaTempV = casillaTempV->d;
		}
	}

	casilla* obtenerUltEle(casilla* casillaInicial) {
		casilla* aux = new casilla();
		aux = casillaInicial ;
		while (aux->d != NULL)
		{
			aux = aux->d;
		}
		return aux;
	}

	bool resolver(casilla* reinaIni, casilla* casillaInicial) {	
		casilla* reinaTemp = new casilla();
		casilla* reinaIniTempAux = new casilla();
		reinaIniTempAux = reinaIni;
		if (reinaIni!= NULL && reinaIni->r==NULL)
		{
			cout << "BOCA" << endl;
			while (reinaIniTempAux->l)
			{
				reinaIniTempAux = reinaIniTempAux->l;
			}
			reinaIniTempAux->ar = reinaIni->ar;
			reinaIniTempAux->sr = reinaIni->sr;
			if (reinaIniTempAux->ar)
				reinaIniTempAux->ar->sr = reinaIniTempAux;
		
			if (reinaIniTempAux->sr!=NULL)
				reinaIniTempAux->sr->ar = reinaIniTempAux;
			reinaIni->ar = NULL;
			reinaIni->sr = NULL;
		}
		
		cout<<"BOCA" << reinaIniTempAux << endl;
			int i=1;
		for (casilla* j = reinaIniTempAux; j != NULL; j=j->r) 
		{
			cout << j->ar << endl;
			//cout << reinaIni <<"------------------------"<< endl;

			if (j->ar != NULL)
			{
				cout << i << endl;
			i++;
				resolver(j->ar, casillaInicial);
			}
				//cout << "BOCA" << endl;
			/*if (reinaIni->ar!=NULL)
			{
				resolver(reinaIni->ar, casillaInicial);
			}*/



			/*
			||||||||||||||||||||||||||||||||||||||||||||||||||||||
			|||CREEMOS QUE EL ERROR ESTÁ EN LA REFERENCIA J->AR|||
			||||||||||||||||||||||||||||||||||||||||||||||||||||||
			*/
			if (reinaTemp != NULL)
			{
				if (reinaTemp->getEstado() == 1)
					reinaTemp->setEstado(0);

				j->ar = reinaTemp->ar;

				if (reinaTemp->ar != NULL)
					reinaTemp->ar->sr = j;

				reinaTemp->ar = NULL;

				j->sr = reinaTemp->sr;

				if (reinaTemp->sr != NULL)
					reinaTemp->sr->ar = j;

				reinaTemp->sr = NULL;
				reinaTemp = j;
				//cout << j->ar << endl;
			}
			
			
			j->setEstado(1);
			cout << "---------------" << endl;
			imprimirTablero(casillaInicial);
			/*
			if (j->r == NULL)
			{
				j->setEstado(0);

			}*/

		}


		return true;
	}
};