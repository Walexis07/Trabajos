#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>

using namespace std;

float ageDiscount (float ticketCost, int customerAge, string isStudent);
float dayDiscount (float ticketCost, string weekDay);
float countDiscount (float ticketCost, int ticketsNumber);

int main() {
	
	int age, countTickets;
	string isStudent, weekDay;
	float basicTicketCost = 100, modifiedTicketCost;

	cout << "\n\t/-/-/CINE ESTUDIANTE UP/-/-/" << endl;
	cout << "Ingrese su edad: ";
	cin >> age;
	cout << "¿Eres un estudiante universitario? ";
	cin >> isStudent;
	cout << "Ingrese el día de la semana: ";
	cin >> weekDay;
	cout << "Ingrese la cantidad de entradas que va a comprar: ";
	cin >> countTickets;
	modifiedTicketCost = ageDiscount(basicTicketCost, age, isStudent);
	modifiedTicketCost = dayDiscount(modifiedTicketCost, weekDay);
	modifiedTicketCost = countDiscount(modifiedTicketCost, countTickets);
	
	float totalCost = modifiedTicketCost * countTickets;
	
	cout << "\nEl precio final total a pagar por " << countTickets << " entradas es de: $" << fixed << setprecision(2) << totalCost << endl << endl;

	return 0;

}


float ageDiscount (float ticketCost, int customerAge, string isStudent) {
	
	if (customerAge > 0 && customerAge < 5) {
		ticketCost -= (ticketCost * 0.6);	
	}
	if (customerAge >= 5 && customerAge <= 12) {
                ticketCost -= (ticketCost * 0.5);
        }
	if (customerAge >= 13 && customerAge <= 17) {
                ticketCost -= (ticketCost * 0.3);
        }
	if (customerAge >= 18 && customerAge <= 64) {
                transform(isStudent.begin(), isStudent.end(), isStudent.begin(), ::toupper);
		
		if (isStudent == "SI") {
			if (customerAge <= 25) {
				ticketCost -= (ticketCost * 0.55);
			}
        	}
	}
	if (customerAge >= 65 && customerAge <= 120) {
		ticketCost -= (ticketCost * 0.4);
	}

	return ticketCost;
}


float dayDiscount (float ticketCost, string weekDay) {

	transform(weekDay.begin(), weekDay.end(), weekDay.begin(), ::toupper);

	if (weekDay == "LUNES" || weekDay == "MARTES" || weekDay == "MIERCOLES" || weekDay == "JUEVES") {
		ticketCost -= (ticketCost * 0.1);
	}

	return ticketCost;
}


float countDiscount (float ticketCost, int ticketsNumber) {

	if (ticketsNumber > 3) {
		ticketCost -= (ticketCost * 0.05);
	}

	return ticketCost;
}

