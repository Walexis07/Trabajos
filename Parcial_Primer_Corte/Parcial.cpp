#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

//Definición de Tasas de Interes
float rates[] = {0.006, 0.007, 0.004, 0.008};

bool stringTypeVerification (string stringValue);
bool floatTypeVerification (float floatValue);
bool intTypeVerification (int integerValue);
bool boolTypeVerification (bool booleanValue);
int loanValidation (string clientType, float loadAmount, int monthsNumber, bool hasCoDebtor);
void totalAmount (string clientType, float loadAmount, int monthsNumber);


int main () {
	
	//Mensaje de inicio para la ejecución del programa 
	cout << "\t\t===== Banco Super Famoso de Colombia =====" << endl << endl;
	cout << "El siguiente programa le ayudará a determinar si un cliente cumple o no con las condiciones para solicitar un crédito de libre inversión. En caso de cumplirlas, le entregará una proyección de la tasa de interés y el valor total a pagar. " << endl;
	cout << "========================================================================================================================" << endl << endl;
	cout << "========================================================================================================================" << endl;
	
	//Inicialización del bucle del programa
	bool repetition = true;
	while (repetition) {
		
		//Declaración de variables
		string clientType;
		float loadAmount;
		int monthsNumber;
		bool hasCoDebtor;
		char exit = 'N';
		
		//Ingreso de datos por parte del usuario y verificación de tipos y rangos
		cout << "Ingrese el tipo de cliente que solicita el préstamo: " ;
		cin >> clientType;
		
		transform(clientType.begin(), clientType.end(), clientType.begin(), ::toupper);
		if (!stringTypeVerification(clientType)) {
			continue;
		}
		
		cout << "Ingrese el monto del préstamo solicitado por el cliente: " ;
		cin >> loadAmount;
		if (!floatTypeVerification(loadAmount)) {
			continue;
		}
		
		cout << "Ingrese el plazo (en meses) para el pago total de las cuotas del préstamo: " ;
		cin >> monthsNumber;
		if (!intTypeVerification(monthsNumber)) {
			continue;
		}
		
		cout << "Ingrese si el cliente cuenta con un co-deudor válido para solicitar el préstamo [1/0]: " ;
		cin >> hasCoDebtor;
		if (!boolTypeVerification(hasCoDebtor)) {
			continue;
		}
		
		//Aprobación o Rechazo del crédito socilitado
		int result = loanValidation(clientType, loadAmount, monthsNumber, hasCoDebtor);
		
		//Respuestas hacia el cliente
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		switch(result){
			case 1:
				totalAmount(clientType, loadAmount, monthsNumber);		//Por facilidades para escribir las tasas de interés se toma la decisión de crear otra función
				break;
			case 2:
				cout << "\t\aRECHAZADO. El plazo excede el máximo de tiempo permitido para créditos de montos bajos" << endl << endl;
				break;
			case 3:
				cout << "\t\aRECHAZADO. El plazo excede el máximo de tiempo permitido para créditos de montos altos" << endl << endl;
				break;
			case 4:	
				cout << "\t\aRECHAZADO. El monto solicitado excede el límite permitido con codeudor" << endl << endl;
				break;
			case 5:
				cout << "\t\aRECHAZADO. El monto solicitado excede el límite permitido sin codeudor" << endl << endl;
				break;
			case 6:
				cout << "\t\aRECHAZADO. Si se encuentra en condición de desempleo, debe tener un codeudor que soporte responsabilidad por el crédito solicitado" << endl << endl;
				break;
			default:
				cout << "\t\aCaso por defecto del switch que no debería aparecer en la consola" << endl << endl;
		}
		
		//Confirmación para seguir ejecutando o finalizar el programa
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t¿Desea salir del programa? [S/N] ";
		cin >> exit;
		repetition = (exit == 'S') ? false : true;
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	
	return 0;
}




//Declaración de Funciones MUY Útiles

//Verificación de Tipo String
bool stringTypeVerification (string clientType) {
	
	if (clientType == "ESTUDIANTE" || clientType == "EMPLEADO" || clientType == "PENSIONADO" || clientType == "DESEMPLEADO") {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es válido, recuerde que solo se admite [Estudiante/Empleado/Pensionado/Desempleado]. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//Verificación de Tipo Float
bool floatTypeVerification (float loadAmount) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es válido, recuerde que solo se admite montos entre 1000 - 99999999. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	
	if (loadAmount > 1000 && loadAmount < 99999999) {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tamaño del dato ingresado no es válido, recuerde que solo se admite montos entre 1000 - 99999999. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//Verificación de Tipo Integer
bool intTypeVerification (int monthsNumber) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es válido, recuerde que solo se admite entre 2 - 50 meses. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	
	if (monthsNumber > 1 && monthsNumber < 50) {
		return true;
	} else {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tamaño del dato ingresado no es válido, recuerde que solo se admite entre 2 - 50 meses. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

//Verificación de Tipo Booleano
bool boolTypeVerification (bool hasCoDebtor) {
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\a>> El tipo de dato ingresado no es válido, recuerde que solo se admite [1 = Si, 0 = No]. Por favor intente nuevamente." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
	if (hasCoDebtor == true || hasCoDebtor == false) { 
		return true; 
	}
}


/*Validación del Crédito
Para efectos prácticos y mejor lectura del código, se plantean las siguientes salidas:
1. Resultado satisfactorio para la aprobación del crédito CON o SIN co-deudor
2. Rechazo por exceso en el límite de tiempo de pago para créditos grandes
3. Rechazo por exceso en el límite de tiempo de pago para créditos pequeños
4. Rechazo por exceso en el límite de monto permitido para el crédito CON co-deudor
5. Rechazo por exceso en el límite de monto permitido para el crédito SIN co-deudor
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

//Calculo del Monto Total (e Impresión en la consola por facilidad)
void totalAmount (string clientType, float loadAmount, int monthsNumber) {
	
	float interestRate = (clientType == "ESTUDIANTE") ? *(rates + 0) : (clientType == "EMPLEADO") ? *(rates + 1) : (clientType == "PENSIONADO") ? *(rates + 2) : (clientType == "DESEMPLEADO") ? *(rates + 3) : 1;
	float loadInterest = loadAmount * interestRate * monthsNumber;
	float totalAmount = loadAmount + loadInterest;
	
	cout << "\tEl préstamo solicitado por un monto de $" << fixed << setprecision(2) << loadAmount << " a un plazo de " << monthsNumber << " meses se considera APROBADO con una Tasa del " << setprecision(1) << interestRate * 100 << "%" << endl;
	cout << "\tTotal a pagar: $ " << setprecision(2) << totalAmount << endl << endl;
}
