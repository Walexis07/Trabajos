#include <iostream>
#include <string>

int main() {
    int peso, costo = 0;
    std::string destino, region;
    char frecuente;
    int cantidad;

  
    std::cout << "Ingrese el peso del paquete (kg): ";
    std::cin >> peso;

 
    if (peso < 1)
        costo = 50;
    else if (peso < 5)
        costo = 100;
    else if (peso < 10)
        costo = 150;
    else
        costo = 200;

    std::cout << "Ingrese el destino (nacional/internacional): ";
    std::cin >> destino;


    // recargo
    if (destino == "internacional") {
        std::cout << "Ingrese la region (America, Europa, Asia): ";
        std::cin >> region;

        if (region == "America")
            costo = costo + (costo * 0.15);
        else if (region == "Europa")
            costo = costo + (costo * 0.25);
        else
            costo = costo + (costo * 0.40);
    }

    std::cout << "Es cliente frecuente? (s/n): ";
    std::cin >> frecuente;


    // descuento cliente frecuente 
    if (frecuente == 's' || frecuente == 'S')
        costo = costo - (costo * 0.10);

    std::cout << "Ingrese la cantidad de paquetes: ";
    std::cin >> cantidad;

    int total = costo * cantidad;


    // descuento cantidad
    if (cantidad > 3)
        total = total - (total * 0.05);


    std::cout << "Costo total a pagar: $" << total << std::endl;

    return 0;
}
