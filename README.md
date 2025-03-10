Este programa implementa una clase CuentaBancaria que imula operaciones bancarias con condicionales (if - else) y un menú interactivo con swicth - case.
En los atributos el titular es el nombre de la cuenta; Saldo, indica en dinero disponible en la cuenta; Activa, inidca si la cuenta está operando o inactiva; E intentosFallidos de número de intentos fallidos del retiro. 

Métodos principales:
depositar(double monto). Solo permite depósitos si la cuenta está activa. No acepta montos negativos o cero.
retirar(double monto). Verifica que haya saldo suficiente. Si el usuario intenta retirar más dinero del disponible, acumula intentos fallidos. Si hay 3 intentos fallidos, la cuenta se bloquea. Muestra una advertencia si el saldo baja de 100.
consultarSaldo(). Muestra el titular, saldo actual y estado de la cuenta (activa o bloqueada).

Menú Interactivo con switch-case
Permite al usuario elegir entre las opciones: 1. Depositar. 2. Retirar. 3. Consultar saldo. 4. Salir. Se ejecuta en un bucle do-while hasta que el usuario elija Salir (opción 4).
                                                                                                     
