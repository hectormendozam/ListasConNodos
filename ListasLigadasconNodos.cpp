#include <iostream>
using namespace std;

class Nodo
{
public:
    int info;
    Nodo* sig;
public:
    Nodo();
    Nodo(int dato);
};

Nodo::Nodo()
{
    info = 0;
    sig = NULL;
}

Nodo::Nodo(int dato)
{
    info = dato;
    sig = NULL;
}

class ListaLigada
{
private:
    Nodo* raiz;
public:
    ListaLigada();
    bool esVacia();
    void insertarInicio(int e);
    void insertarFinal(int e);
    int eliminarInicio();
    int eliminarFinal();
    void insertarPosicion(int e, int p);
    void mostrarLista();
};

ListaLigada::ListaLigada() { raiz = NULL; }

bool ListaLigada::esVacia()
{
    return (raiz == NULL);
}

void ListaLigada::insertarInicio(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        raiz = nuevo;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

void ListaLigada::mostrarLista()
{
    Nodo* aux = raiz;

    if (!esVacia())
    {
        cout << "raiz" << " --> ";
        while (aux != NULL)
        {
            cout << aux->info << " --> ";
            aux = aux->sig;
        }
        cout << "NULL" << endl;
    }
    else
    {
        cout << "\nLa lista esta vacia!\n";
    }
}

void ListaLigada::insertarFinal(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        raiz = nuevo;
    }
    else
    {
        Nodo* aux = raiz;

        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
}

int ListaLigada::eliminarInicio()
{
    int dato = INT_MAX;

    if (!esVacia())
    {
        Nodo* aux = raiz;

        if (aux->sig == NULL)
        {
            raiz = NULL;
        }
        else
        {
            raiz = aux->sig;
            aux->sig = NULL;
        }
        dato = aux->info;
        delete aux;
    }

    return dato;
}

int ListaLigada::eliminarFinal()
{
    int dato = INT_MAX;

    if (!esVacia())
    {
        Nodo* anterior, * siguiente;
        siguiente = raiz;
        anterior = siguiente;

        if (siguiente->sig == NULL)
        {
            raiz = NULL;
        }
        else
        {
            while (siguiente->sig != NULL)
            {
                anterior = siguiente;
                siguiente = siguiente->sig;
            }

            anterior->sig = NULL;
        }

        dato = siguiente->info;
        delete siguiente;
    }

    return dato;
}

void ListaLigada::insertarPosicion(int dato, int posicion)
{
    if (posicion < 0) // Si la posición es menor a cero no puede existir
    {
        cout << "Posicion invalida." << endl;
        return;
    }

    Nodo* nuevo = new Nodo(dato);

    if (posicion == 0) // Si solo hay un elemento directamente lo inserta y recorre el elemento
    {
        nuevo->sig = raiz;
        raiz = nuevo;
        return;
    }

    Nodo* aux = raiz;
    int contador = 0;

    while (contador < posicion - 1 && aux != NULL)
    {
        aux = aux->sig;
        contador++;
    }

    if (aux == NULL)
    {
        cout << "Posicion fuera de rango." << endl;
        delete nuevo;
        return;
    }

    nuevo->sig = aux->sig;
    aux->sig = nuevo; // Sustitucion de los datos
}

// IMPRIMIR LISTA ENLAZADA EN ORDEN INVERSO
void ListaLigada::imprimirReversa(Nodo* nodo)
{
    if (nodo == NULL)
    {
        return;
    }

    imprimirReversa(nodo->sig);
    cout << nodo->info << " --> ";
}

void ListaLigada::imprimirReversa()
{
    cout << "NULL" << " <--- ";
    imprimirReversa(raiz);
    cout << "raiz" << endl;
}

int main()
{
    ListaLigada l1;
    int menu, elemento, posicion;

    do {
        cout << "\n ------ PROGRAMA - LISTAS LIGADAS ------ " << endl;
        cout << "\nElija la opcion que desea usar:\n" << endl;
        cout << "1) Insertar dato al inicio " << endl;
        cout << "2) Insertar dato al final " << endl;
        cout << "3) Eliminar inicio " << endl;
        cout << "4) Eliminar final " << endl;
        cout << "5) Insertar posicion " << endl;
        cout << "6) Mostrar lista " << endl;
        cout << "7) Salir " << endl;

        cout << "Opcion elegida: ";

        cin >> menu;

        switch (menu) {
        case 1:
            cout << "Ingrese el dato que quiere insertar: ";
            cin >> elemento;
            l1.insertarInicio(elemento);
            break;
        case 2:
            cout << "Ingrese el dato que quiere insertar: ";
            cin >> elemento;
            l1.insertarFinal(elemento);
            break;
        case 3:
            l1.eliminarInicio();
            break;
        case 4:
            l1.eliminarFinal();
            break;
        case 5:
            cout << "Ingrese el elemento que quiere insertar: ";
            cin >> elemento;
            cout << "Ingrese la posicion donde desea insertarlo: ";
            cin >> posicion;
            l1.insertarPosicion(elemento, posicion);
            break;
        case 6:
            cout << "La lista es la siguiente: " << endl;;
            l1.mostrarLista();
            break;
        case 7:
            cout << "Saliendo... " << endl;
            break;
        default:
            cout << "Elija una opcion valida del 1 al 7 " << endl;
        }
    } while (menu != 7);

    return 0;
}
