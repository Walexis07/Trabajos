#include <iostream>

class carro{
public:
int velocidad;
void acelerar(){
velocidad=velocidad+10;
std::cout <<"velocidad: " << velocidad;
}
};

int main(){

    return 0;
}