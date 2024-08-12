#include <iostream>
#include "matrices.hpp"
#include "lista.hpp"
#include "node.hpp"


void MenuPrincipal();
void Menu_CMatrices();
void Menu_reflexiva();
void Menu_SumaMatrices();
void Menu_TReflexiva();

list *lista_matrices = new list();


int main() {
    MenuPrincipal();
    return 0;
}



void MenuPrincipal() {
    int opcion;
    bool salir = false;
    while(true) {
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "1. Crear matrice" << std::endl;
        std::cout << "2. Suma de matrices" << std::endl;
        std::cout << "3. Triangulacion reflexiva" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "Elije una de las opciones: ";
        std::cin >> opcion;

        if (opcion == 1) {
            Menu_CMatrices();
            break;
        } else if (opcion == 2) {
            Menu_SumaMatrices();
            break;
        } else if (opcion == 3) {
            Menu_TReflexiva();
            break;
        } else if (opcion == 4) {
            break;
        } else {
            std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << "<Error> Tienes que elegir una de las opciones que estan en pantalla" << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
        }
    }
    
}

void Menu_CMatrices() {
    int opcion;
    int f;
    int c;
    while (true) {
        std::cout << "Ingresa la cantidad de filas: ";
        std::cin >> f;

        std::cout << "\nIngresa la cantidad de columnas: ";
        std::cin >> c;

        if (f < 2 || f > 20 || c < 2 || c > 20) {
            std::cout << "<Error> Ingresastes un largo de matriz incorrecto, la matriz tiene que ser minimo de 2x2 y maximo de 20x20\n";
        } else {
            break;
        }
    }
    


    matrices *m = new matrices(f, c);
    while(true) {
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "1. Generador automatico" << std::endl;
        std::cout << "2. Ingreso manual" << std::endl;
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "Elije una de las opciones: ";
        std::cin >> opcion;
        if (opcion == 1) {

            m->SetRandnum();
            lista_matrices->insert(m); //Se guarda en la lista
            node *test = lista_matrices->search(m); //se busca en la lista
            matrices *mama = test->getData(); //obtiene los datos de la matriz loll

            mama->mostrar();

            MenuPrincipal();
            break;

        } else if (opcion == 2) {
            m->SetManual();

            lista_matrices->insert(m); //Se guarda en la lista
            node *test = lista_matrices->search(m); //se busca en la lista
            matrices *mama = test->getData(); //obtiene los datos de la matriz loll
            mama->mostrar();

            MenuPrincipal();
            break;
        } else {
            std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << "<Error> Tienes que elegir una de las opciones que estan en pantalla" << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
        }
        
    }
    
}

void Menu_SumaMatrices() {
    if (lista_matrices->len() < 2) {
        std::cout << "<ERROR> Debes de crear al menos 2 matrices para hacer la suma de ellas" << std::endl;
        MenuPrincipal();
    } else {
        matrices *m1;
        matrices *m2;


        node *d1 = lista_matrices->indices(0); 
        matrices *t1 = d1->getData();

        node *d2 = lista_matrices->indices(1);
        matrices *t2 = d2->getData();

        if (t2->getFila() > t1->getFila() || t2->getColumnas() > t1->getColumnas()) {
            m1 = d2->getData();
            m2 = d1->getData();

        } else if (t1->getFila() > t2->getFila() || t1->getColumnas() > t2->getColumnas()) {
            m1 = d1->getData();
            m2 = d2->getData();
        } else {
            m1 = d1->getData();
            m2 = d2->getData();
        }

        std::cout << std::endl << "MATRIZ 1:" << std::endl;
        m1->mostrar();
        std::cout << std::endl << "MATRIZ 2:" << std::endl;
        m2->mostrar();

        int num1;
        int num2;

        //Recorrerá a la matriz 1 (la que es más grande) con las filas y columnas de la matriz 2
        for (int f = 0; f < m2->getFila(); f++) {
            for (int c = 0; c < m2->getColumnas(); c++) {
                num1 = m1->Show(f,c); //matriz 1
                num2 = m2->Show(f,c); //matriz 2
                m1->Editar(f,c,num1 + num2); // aca se va editando a la matriz 1 sumandole (es una funcion muy mala sorry )
            }
        }

        std::cout << std::endl << "RESULTADO:" << std::endl;
        m1->mostrar(); // Muestra el resultado de la suma de las 2 matrices
        std::cout << std::endl << std::endl;

        //Las elimino de la lista para dar espacio a las otras creadas 
        lista_matrices->remove(m1);
        lista_matrices->remove(m2);
        MenuPrincipal();
    }
}

void Menu_TReflexiva() {
    if (lista_matrices->len() < 2) {
        std::cout << "<ERROR> Debes de crear al menos 2 matrices para usar este menú" << std::endl;
        MenuPrincipal();
    } else {

        matrices *m1;
        matrices *m2;

        node *d1 = lista_matrices->indices(0); 
        matrices *t1 = d1->getData();

        node *d2 = lista_matrices->indices(1);
        matrices *t2 = d2->getData();

        m1 = d1->getData();
        m2 = d2->getData();
        
        std::cout << std::endl << "MATRIZ 1:" << std::endl;
        m1->mostrar();
        std::cout << std::endl << "MATRIZ 2:" << std::endl;
        m2->mostrar();


        //Comprobador
        if ((m1->Tsuperior() != m2->Tsuperior()) || (m1->TInferior() != m2->TInferior()) || (m1->getColumnas() != m2->getColumnas() || m1->getFila() != m2->getFila()) || (m1->getColumnas() != m1->getFila() || m2->getColumnas() != m2->getFila())) {
            std::cout << std::endl << "Las matrices no son triangulares reflexivas" << std::endl;
        } else std::cout << std::endl << "Las matrices son triangulares reflexivas" << std::endl;

        lista_matrices->remove(m1);
        lista_matrices->remove(m2);
        MenuPrincipal();
    }
}