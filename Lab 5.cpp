#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

int sumaNumerosParesImpares(int numero, bool sumarPares);
int factorial(int numero);
int contadorDigitos(int numero);
void ordenamientoAscendente(int &num1, int &num2, int &num3);
int sumaDigitos(int numero);

int main() {
    int opc;
    srand(time(NULL));

    do {
        gotoxy(35, 1);
        cout << "MENU" << endl;
        cout << "1- Suma de numeros pares o impares." << endl;
        cout << "2- Factorial." << endl;
        cout << "3- Contador de digitos." << endl;
        cout << "4- Ordenamiento de numeros." << endl;
        cout << "5- Suma de digitos de un numero." << endl;
        cout << "6- Salir del menu." << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
            case 1: {
                system("cls");

                int num;
                char tipo;

                cout << "Ingrese un numero: ";
                cin >> num;

                cout << "¿Sumar pares (p) o impares (i)? ";
                cin >> tipo;

                int resultado = sumaNumerosParesImpares(num, tipo == 'p');
                cout << "La suma es: " << resultado << "\n";

                system("pause");
                cout << endl;
                break;
            }
            case 2: {
                system("cls");

                int num;
                cout << "Ingrese un numero: ";
                cin >> num;

                int resultado = factorial(num);
                cout << "El factorial es: " << resultado << "\n";

                system("pause");
                cout << endl;
                break;
            }
            case 3: {
                system("cls");

                int num;
                cout << "Ingrese un numero: ";
                cin >> num;

                int cantidadDigitos = contadorDigitos(num);
                cout << "El numero tiene " << cantidadDigitos << " digitos.\n";

                system("pause");
                cout << endl;
                break;
            }
            case 4: {
                system("cls");

                int num1, num2, num3;
                cout << "Ingrese tres numeros separados por espacios: ";
                cin >> num1 >> num2 >> num3;

                ordenamientoAscendente(num1, num2, num3);
                cout << "Numeros ordenados: " << num1 << ", " << num2 << ", " << num3 << "\n";

                system("pause");
                cout << endl;
                break;
            }

            case 5: {
                system("cls");

                int num;
                cout << "Ingrese un numero: ";
                cin >> num;

                int resultado = sumaDigitos(num);
                cout << "La suma de los digitos es: " << resultado << "\n";

                system("pause");
                cout << endl;
                break;
            }

            default:
                break;
        }

        system("cls");

    } while (opc != 6);

    cout << "Fuera del programa";

    return 0;
}

int sumaNumerosParesImpares(int numero, bool sumarPares) {
    int suma = 0;

    for (int i = 1; i <= numero; i++) {
        if ((i % 2 == 0 && sumarPares) || (i % 2 != 0 && !sumarPares)) {
            suma += i;
        }
    }

    return suma;
}

int factorial(int numero) {
    int resultado = 1;
    int i = 1;

    while (i <= numero) {
        resultado *= i;
        i++;
    }

    return resultado;
}

int contadorDigitos(int numero) {
    int contador = 0;

    do {
        numero /= 10;
        contador++;
    } while (numero != 0);

    return contador;
}

void ordenamientoAscendente(int &num1, int &num2, int &num3) {
    if (num1 > num2) {
        swap(num1, num2);
    }
    if (num2 > num3) {
        swap(num2, num3);
    }
    if (num1 > num2) {
        swap(num1, num2);
    }
}

int sumaDigitos(int numero) {
    int suma = 0;

    while (numero != 0) {
        suma += numero % 10;
        numero /= 10;
    }

    return suma;
}

