#include "TTree.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	TTree T;
	T.fromFileToThree();
	T.searchTree();
	return 0;
}