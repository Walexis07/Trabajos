#include <iostream>

/* 
*
*Implementacion del Doxygen
*@brief Crear clase de tipo Car y subir velocidad
*@param speed es variable de velocidad
*@return Retorma velocidad + 10
*/

class car{
public:
int speed;
void acelerate(){
speed=speed+10;
std::cout <<"velocidad: " << speed;
}
};

int main(){
 car carro;
    return 0;
}