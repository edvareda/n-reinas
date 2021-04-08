#pragma once
#include <iostream>
using namespace std;
class casilla
{
	public:
		casilla* u;
		casilla* eul;
		casilla* eur;
		casilla* r;
		casilla* edr;
		casilla* d;
		casilla* edl;
		casilla* l;

		casilla() {
			this->u = NULL; //up = arriba
			this->eul = NULL; //eul = esquina up left = esquina superior izquierda
			this->eur = NULL;//eur = esquina up right = esquina superior derecha
			this->r = NULL; //r = right = derecha
			this->edr = NULL; // edl = esquina down left =esquina inferior derecha
			this->d = NULL; //down = abajo
			this->edl = NULL; //edl = esquina down left = esquina inferior izquierda
			this->l = NULL; //left = izquierda
			this->estado = 0;
		}
		void setEstado(bool estadoParam) {
			this->estado = estadoParam;
		}

		bool getEstado() {
			return this->estado;
		}
	private:
		bool estado;

		
};

