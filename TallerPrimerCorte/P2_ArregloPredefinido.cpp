#include <iostream>

using namespace std;

int findNumber (int selectedNumber, int array[], int sizeOfArray);

int main() {

	int array[] = {1, 3, 5, 3, 7, 3, 9, 3, 2, 3};
	int selectedNumber, size = sizeof(array)/sizeof(array[0]), numberOfRepetitions = 0;

	cout << "\nArreglo: ";
	for (int value : array) {
		cout << value << " ";
	}
	
	cout << "\nIngrese el número en el arreglo que desea buscar: ";
	cin >> selectedNumber;

	numberOfRepetitions = findNumber(selectedNumber, array, size);

	if (numberOfRepetitions == 0) {
		cout << "El número " << selectedNumber << " no se encuentra en el arreglo." << endl << endl;
	} else { 
		cout << "El número " << selectedNumber << " aparece " << numberOfRepetitions << " veces en el arreglo." << endl << endl;
	}
    
	return 0;
}



int findNumber (int number, int array[], int sizeOfArray) {
	
	int repetitions = 0;
	for (int i = 0; i < sizeOfArray; i++) {
		if (array[i] == number) {
			repetitions++;
		}
	}

	return repetitions;
}
