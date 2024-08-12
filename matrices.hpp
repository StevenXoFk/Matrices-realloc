#ifndef MATRICES_HPP
#define MATRICES_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>

class matrices {
private:
    int fila;
    int columna;
    int** datos;

public:
    matrices(int f, int c) : fila(f), columna(c) {
        // Inicializar el puntero de punteros
        datos = new int*[fila];
        for (int i = 0; i < fila; i++) {
            datos[i] = new int[columna];
            for (int j = 0; j < columna; j++) {
                datos[i][j] = 0;
            }
        }
    }

    ~matrices() {
        for (int i = 0; i < fila; i++) {
            delete[] datos[i];
        }
        delete[] datos;
    }

    void SetRandnum() {
        std::srand(time(nullptr));
        for (int a = 0; a < fila; a++) {
            for (int b = 0; b < columna; b++) {
                datos[a][b] = std::rand() % 1023;
            }
        }
    }

    void SetManual() {
        int num = 0;
        for (int a = 0; a < fila; a++) {
            for (int b = 0; b < columna; b++) {
                while(true) {
                    std::cout << "Fila: " << a << " Columna: " << b << " Ingresa un numero: ";
                    std::cin >> num;

                    if (num > 255) {
                        std::cout << "<Error> Tienes que ingresar un numero que no se pase de 255" << std::endl;
                    } else {
                        break;
                    }
                }
                
                datos[a][b] = num;
            }
        }
    }

    void mostrar() {
        for (int x = 0; x < fila; x++) {
            std::cout << "#####";
        }
        std::cout << std::endl;
            
        for (int a = 0; a < fila; a++) {
            std::cout << "# ";
            for (int b = 0; b < columna; b++) {
                std::cout << datos[a][b] << " ";
            }
            std::cout << "#";
            std::cout << std::endl;
        }
        for (int x = 0; x < fila; x++) {
            std::cout << "#####";
        }
        std::cout << std::endl;
    }
    //Para obtener datos de la matriz lol
    int getFila() { return fila; }
    int getColumnas() { return columna; }

    void Editar(int f, int c, int num) { //Edita la matriz
        datos[f][c] = num;
    }

    int Show(int f, int c) { 
        return datos[f][c];
    }

    bool Tsuperior() {
        for (int f = 0; f < fila; f++) {
            for (int c = 0; c < fila; c++) {
                if (datos[f][c] != 0) return false;
            }
        }
        return true;
    }

    bool TInferior() {
        for (int f = 0; f < fila; f++) {
            for (int c = f +1; c < fila; c++) {
                if (datos[f][c] != 0) return false;
            }
        }
        return true;
    }
};

#endif // MATRICES_HPP
