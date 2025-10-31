#include <iostream>
using namespace std;

class DispositivoInteligente {
    private: 
        string nombre;
        bool estado;
        bool bloqueado;
        float consumoEnergia;
        

    public:
        DispositivoInteligente(string nom, float consumo) 
            : nombre(nom), estado(false), consumoEnergia(consumo) {}
        
        string nomb() {
            return nombre;
        }

        void encender() {
            if (bloqueado) {
                cout << nombre << " está bloqueado y no puede encender" << endl;
                return;
            }
            else {
            estado = true;
            cout << nombre << " encendido" << endl;
        }
        }        

        void apagar() {
            if (bloqueado) {
                cout << nombre << " está bloqueado y no puede apagar" << endl;
                return;
            }
            else {
            estado = false;
            cout << nombre << " apagado" << endl;
        }
        }


        float obtenerConsumoEnergia(float horas) {
            return consumoEnergia * horas;
        }

        void bloquearControlRemoto() {
            bloqueado = true;
            cout << nombre << " bloqueado" << endl;
        }

        void desbloquearControlRemoto() {
            bloqueado = false;
            cout << nombre << " desbloqueado" << endl;
        }

 };

 int main(){
    DispositivoInteligente ob1("Lámpara ", 0.05);
    ob1.desbloquearControlRemoto();
    ob1.encender();
    cout <<ob1.nomb()<< "consume " << ob1.obtenerConsumoEnergia(10) << " kWh" << endl;
    ob1.bloquearControlRemoto();
    ob1.apagar();
    ob1.desbloquearControlRemoto();
    ob1.apagar();
    return 0;
 }