//Made by Anna Kravets, K-22
#include <iostream>
#include "E:\2 курс\Lab1\my_random\my_random.h"
#include <string>
using namespace std;

void printMenu() {
	string methods[10] = { "Linear", "Square", "Fibbo", "Reverse",
	"Combination", "3-sigma", "Polar coordinates", "Fraction",
	"Logarithm", "Arens'" };
	for (int i = 0; i < 10; i++) {
		cout << "Enter " << i + 1 << " to use " << methods[i] << " method\n";
	}
}

//pre: 0<v<6
void histogram(int v) {
	int x = 23, y = 55866, z=x;
	double g[100] = {}, zDouble;
	for (int i = 0; i < nElem; i++) {
		switch (v) {
		case 1:
			z=nextLinear();
			break;
		case 2:
			z=nextSquare(z);
			break;
		case 3:
			z=nextFibbo(x,y);
			break;
		case 4:
			z=nextReverseCongruent(z);
			break;
		case 5:
			z=nextCombination(x,y);
			break;
		case 6:
			zDouble = nextSigmaMethod(x);
			break;
		case 7:
			zDouble = nextPolar();
			break;
		case 8:
			zDouble = nextFraction();
			break;
		case 9:
			zDouble = nextLogarithmMethod();
			break;
		case 10:
			zDouble = nextArens();
			break;
		default:
			throw exception("Mistake: You can enter only 1, 2.. 10\n");
		}
		if (v>0 && v<6)
			g[int(z * 10. / m)] += 1.;
		else if (v > 5 && v<9) {
			if (zDouble >= -3. && zDouble <= 3) {
				g[int((zDouble+3.) * 10.)] += 1.;
			}
		}
		else {
			g[int(zDouble)] += 1.;
		}
	}
	for (int i = 0; i < 60; i++)
		g[i] = g[i] / nElem*100.;
	if (v > 0 && v < 6)
		printHistogram(g, 10, 0., 0.1);
	else if (v > 5 && v < 9)
		printHistogram(g, 60, -3., 0.1);
	else
		printHistogram(g, 100, 0., 1.);
}

int main()
{
	try {
		printMenu();
		int v;
		while (cin >> v) {
			histogram(v);
			printMenu();
		}
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
	catch(...) {
		cout << "Sorry, there is a MISTAKE\n";
	}
    return 0;
}



