#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

//Definici�n de Tasas de Interes
float rates[] = {0.006, 0.007, 0.004, 0.008};

bool stringTypeVerification (string stringValue);
bool floatTypeVerification (float floatValue);
bool intTypeVerification (int integerValue);
bool boolTypeVerification (bool booleanValue);
int loanValidation (string clientType, float loadAmount, int monthsNumber, bool hasCoDebtor);
void totalAmount (string clientType, float loadAmount, int monthsNumber);


int main () {
	
	//Mensaje de inicio para la ejecuci�n del programa 
	cout << "\t\t===== Banco Super Famoso de Colombia =====" << endl << endl;
	cout << "El siguiente programa le ayudar� a determinar si un cliente cumple o no con las condiciones para solicitar un cr�dito de libre inversi�n. En caso de cumplirlas, le entregar� una proyecci�n de la tasa de inter�s y el valor total a pagar. " << endl;
	cout << "========================================================================================================================" << endl << endl;
	cout << "========================================================================================================================" << endl;
	
	//Inicializaci�n del bucle del programa
	bool repetition = true;
	while (repetition) {
		
		//Declaraci�n de variables
		string clientType;
		float loadAmount;
		int monthsNumber;
		bool hasCoDebtor;
		char exit = 'N';
		
		//Ingreso de datos por parte del usuario y verificaci�n de tipos y rangos
		cout << "Ingrese el tipo de cliente que solicita el pr�stamo: " ;
		cin >> clientType;
		
		transform(clientType.begin(), clientType.end(), clientType.begin(), ::toupper);
		if (!stringTypeVerification(clientType)) {
			continue;
		}
		
		cout << "Ingrese el monto del pr�stamo solicitado por el cliente: " ;
		cin >> loadAmount;
		if (!floatTypeVerification(loadAmount)) {
			continue;
		}
		
		cout << "Ingrese el plazo (en meses) para el pago total de las cuotas del pr�stamo: " ;
		cin >> monthsNumber;
		if (!intTypeVerification(monthsNumber)) {
			continue;
		}
		
		cout << "Ingrese si el cliente cuenta con un co-deudor v�lido para solicitar el pr�stamo [1/0]: " ;
		cin >> hasCoDebtor;
		if (!boolTypeVerification(hasCoDebtor)) {
			continue;
		}
		
		//Aprobaci�n o Rechazo del cr�dito socilitado
		int result = loanValidation(clientType, loadAmount, monthsNumber, hasCoDebtor);
		
		//Respuestas hacia el cliente
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		switch(result){
			case 1:
				totalAmount(clientType, loadAmount, monthsNumber);		//Por facilidades para escribir las tasas de inter�s se toma la decisi�n de crear otra funci�n
				break;
			case 2:
				cout << "\t\aRECHAZADO. El plazo excede el m�ximo de tiempo permitido para cr�ditos de montos bajos" << endl << endl;
				break;
			case 3:
				cout << "\t\aRECHAZADO. El plazo excede el m�ximo de tiempo permitido para cr�ditos de montos altos" << endl << endl;
				break;
			case 4:	
				cout << "\t\aRECHAZADO. El monto solicitado excede el l�mite permitido con codeudor" << endl << endl;
				break;
			case 5:
				cout << "\t\aRECHAZADO. El monto solicitado excede el l�mite permitido sin codeudor" << endl << endl;
				break;
			case 6:
				cout << "\t\aRECHAZADO. Si se encuentra en condici�n de desempleo, debe tener un codeudor que soporte responsabilidad por el cr�dito solicitado" << endl << endl;
				break;
			default:
				cout << "\t\aCaso por defecto del switch que no deber�a aparecer en la consola" << endl << endl;
		}
		
		//Confirmaci�n para seguir ejecutando o finalizar el programa
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t�Desea salir del programa? [S/N] ";
		cin >> exit;
		repetition = (exit == 'S') ? false : true;
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	
	return 0;
}




//Declaraci�n de Funciones MUY �tiles

//Verificaci�n de Tipo String
bool stringTypeVerification (string clientType) {
	
	if (clientType == "ESTUDIANTE" || clientType == "EMPLEADO" || clientType == "PENSIONADO" || clientType == "DESEMPLEADO") {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es v�lido, recuerde que solo se admite [Estudiante/Empleado/Pensionado/Desempleado]. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//Verificaci�n de Tipo Float
bool floatTypeVerification (float loadAmount) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es v�lido, recuerde que solo se admite montos entre 1000 - 10000000. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	
	if (loadAmount > 1000 && loadAmount < 10000000) {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tama�o del dato ingresado no es v�lido, recuerde que solo se admite montos entre 1000 - 10000000. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//Verificaci�n de Tipo Integer
bool intTypeVerification (int monthsNumber) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es v�lido, recuerde que solo se admite entre 2 - 48 meses. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	
	if (monthsNumber > 1 && monthsNumber < 48) {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tama�o del dato ingresado no es v�lido, recuerde que solo se admite entre 2 - 48 meses. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//Verificaci�n de Tipo Booleano
bool boolTypeVerification (bool hasCoDebtor) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es v�lido, recuerde que solo se admite [1 = Si, 0 = No]. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	if (hasCoDebtor == true || hasCoDebtor == false) { 
		return true; 
	}
}


/*Validaci�n del Cr�dito
Para efectos pr�cticos y mejor lectura del c�digo, se plantean las siguientes salidas:
1. Resultado satisfactorio para la aprobaci�n del cr�dito CON o SIN co-deudor
2. Rechazo por exceso en el l�mite de tiempo de pago para cr�ditos grandes
3. Rechazo por exceso en el l�mite de tiempo de pago para cr�ditos peque�os
4. Rechazo por exceso en el l�mite de monto permitido para el cr�dito CON co-deudor
5. Rechazo por exceso en el l�mite de monto permitido para el cr�dito SIN co-deudor
6. Rechazo de cliente desempleado por no tener co-deudor*/

int loanValidation (string clientType, float loadAmount, int monthsNumber, bool hasCoDebtor) {
	
	if (clientType == "ESTUDIANTE") {
		if (hasCoDebtor == true) {
			if (loadAmount > 5000000) return 4;
				if (monthsNumber > 24) return 2;
					return 1;
				
		} else {
			if (loadAmount > 2000000) return 5;
				if (monthsNumber > 12) return 3;
					return 1;
		}
	}
	
	if (clientType == "EMPLEADO") {
		if (hasCoDebtor == true) {
			if (loadAmount > 10000000) return 4;
				if (monthsNumber > 48) return 2;
					return 1;
			
		} else {
			if (loadAmount > 5000000) return 5;
				if (monthsNumber > 24) return 3;
					return 1;
		}
	}
	
	if (clientType == "PENSIONADO") {
		if (hasCoDebtor == true) {
			if (loadAmount > 7000000) return 4;
				if (monthsNumber > 48) return 2;
					return 1;
			
		} else {
			if (loadAmount > 3000000) return 5;
				if (monthsNumber > 24) return 3;
					return 1;
		}
	}
	
	if (clientType == "DESEMPLEADO") {
		if (hasCoDebtor == true) {
			if (loadAmount > 2000000) return 4;
				if (monthsNumber > 12) return 3;
					return 1;
			
		} else {
			return 6;
		}
	}
	
	return 6;
}

//Calculo del Monto Total (e Impresi�n en la consola por facilidad)
void totalAmount (string clientType, float loadAmount, int monthsNumber) {
	
	float interestRate = (clientType == "ESTUDIANTE") ? *(rates + 0) : (clientType == "EMPLEADO") ? *(rates + 1) : (clientType == "PENSIONADO") ? *(rates + 2) : (clientType == "DESEMPLEADO") ? *(rates + 3) : 1;
	float loadInterest = loadAmount * interestRate * monthsNumber;
	float totalAmount = loadAmount + loadInterest;
	
	cout << "\tEl pr�stamo solicitado por un monto de $" << fixed << setprecision(2) << loadAmount << " a un plazo de " << monthsNumber << " meses se considera APROBADO con una Tasa del " << setprecision(1) << interestRate * 100 << "%" << endl;
	cout << "\tTotal a pagar: $ " << setprecision(2) << totalAmount << endl << endl;
}
