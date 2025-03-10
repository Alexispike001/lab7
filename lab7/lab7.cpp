#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    bool activa;
    int intentosFallidos;

public:
    CuentaBancaria(string nombre, double saldoInicial) {
        titular = nombre;
        saldo = saldoInicial;
        activa = true;
        intentosFallidos = 0;
    }

    void depositar(double monto) {
        if (!activa) {
            cout << "La cuenta está bloqueada, no se pueden hacer depósitos.\n";
            return;
        }
        if (monto <= 0) {
            cout << "No se pueden hacer transacciones con montos negativos o cero.\n";
            return;
        }
        saldo += monto;
        cout << "Depósito exitoso. Nuevo saldo: " << saldo << endl;
    }

    void retirar(double monto) {
        if (!activa) {
            cout << "La cuenta está bloqueada, no se pueden hacer retiros.\n";
            return;
        }
        if (monto <= 0) {
            cout << "No se pueden hacer transacciones con montos negativos o cero.\n";
            return;
        }
        if (monto > saldo) {
            cout << "Fondos insuficientes. No puede retirar más dinero del saldo disponible.\n";
            intentosFallidos++;
            if (intentosFallidos >= 3) {
                activa = false;
                cout << "Se ha bloqueado la cuenta por 3 intentos fallidos de retiro.\n";
            }
            return;
        }
        saldo -= monto;
        cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
        if (saldo < 100) {
            cout << "Advertencia: Su saldo es menor a 100.\n";
        }
    }

    void consultarSaldo() {
        cout << "Titular: " << titular << "\nSaldo: " << saldo << "\nEstado: "
            << (activa ? "Activa" : "Bloqueada") << endl;
    }
};

int main() {
    string nombre;
    double saldoInicial;
    int opcion;

    cout << "Ingrese el nombre del titular: ";
    getline(cin, nombre);
    cout << "Ingrese el saldo inicial: ";
    cin >> saldoInicial;

    CuentaBancaria cuenta(nombre, saldoInicial);

    do {
        cout << "\nMENU\n";
        cout << "1. Depositar\n";
        cout << "2. Retirar\n";
        cout << "3. Consultar saldo\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            double monto;
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            cuenta.depositar(monto);
            break;
        }
        case 2: {
            double monto;
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            cuenta.retirar(monto);
            break;
        }
        case 3:
            cuenta.consultarSaldo();
            break;
        case 4:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != 4);

    return 0;
}