#include <iostream>
#include <string>

using namespace std;

int main() {
    int nota, asistencia;
    string comportamiento;

    
    cout << "Ingrese la nota final (0-100): ";
    cin >> nota;

    cout << "Ingrese el porcentaje de asistencia (0-100): ";
    cin >> asistencia;

    cout << "Ingrese el comportamiento (Excelente, Bueno, Aceptable, Deficiente): ";
    cin >> comportamiento;


    if (nota < 0 || nota > 100 || asistencia < 0 || asistencia > 100 ||
        (comportamiento != "Excelente" && comportamiento != "Bueno" &&
         comportamiento != "Aceptable" && comportamiento != "Deficiente")) {
        
        cout << "Error: Datos invalidos" << endl;
    } 
    else {
 
	    
        if (nota >= 70 && asistencia >= 85) {

            if (comportamiento == "Excelente" || comportamiento == "Bueno") {
                cout << "Resultado: Aprobado con excelencia" << endl;
            } 
            else if (comportamiento == "Aceptable") {
                cout << "Resultado: Aprobado con observacion" << endl;
            } 
            else {
                cout << "Resultado: Reprobado por conducta" << endl;
            }

        } 
        else {
            cout << "Resultado: Reprobado por rendimiento" << endl;
        }
    }

    return 0;
}
