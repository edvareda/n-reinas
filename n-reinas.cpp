#include <iostream>
#include "casilla.h"
#include "utils.h"
using namespace std;
utils* utilsFile = new utils();
int main()
{
	//utils
	utilsFile->selectnReinas();
	utilsFile->tablero(utilsFile->nReinas);
}
