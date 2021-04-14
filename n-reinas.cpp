#include <iostream>
#include "casilla.h"
#include "utils.h"
using namespace std;
utils* utilsFile = new utils();
int main()
{
	utilsFile->crearMatriz();
	utilsFile->tablero(utilsFile->nReinas);
}
