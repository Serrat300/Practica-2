#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Usuario
{
protected:
    string nombre;
    string telefono;
    int edad;
    string password;

public:
    Usuario(string _nombre, string _telefono, int _edad, string _password)
    {
        nombre = _nombre;
        telefono = _telefono;
        edad = _edad;
        password = _password;
    }

    void datos()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Edad: " << edad << endl;
    }

    bool Login(string _nombre, string _password)
    {
        cout << "Ingrese nombre: ";
        cin >> _nombre;
        cout << "Ingrese contrasenia: ";
        cin >> _password;
        if (_nombre == nombre && _password == password)
        {
            cout << "Login exitoso" << endl;
            datos(); // Mostrar los datos del usuario
            return true;
        }
        else
        {
            cout << "Nombre o contrasenia incorrecta " << endl;
            return false;
        }
    }

    virtual void Logout()
    {
        cout << "Logout exitoso" << endl;
    }

    virtual void CambiarPassword()
    {
        string nuevaPassword;
        cout << "Ingrese la contrasenia nueva: ";
        cin >> nuevaPassword;
        password = nuevaPassword;
        cout << "Su contrasenia ha sido cambiada exitosamente" << endl;
    }
};

class Cliente : public Usuario
{
public:
    Cliente(string _nombre, string _telefono, int _edad, string _password) : Usuario(_nombre, _telefono, _edad, _password) {}

    void comprar()
    {
        cout << nombre << " realizo una compra " << endl;
    }

    void reclamar()
    {
        cout << nombre << " reclamo un producto " << endl;
    }

    void devolucion()
    {
        cout << nombre << " devolvio un producto " << endl;
    }
};

class Vendedor : public Usuario
{
public:
    Vendedor(string _nombre, string _telefono, int _edad, string _password) : Usuario(_nombre, _telefono, _edad, _password) {}

    void vender()
    {
        cout << nombre << " vendio un producto " << endl;
    }

    void actualizarinv()
    {
        cout << nombre << " actualizo el inventario " << endl;
    }
};

int main()
{
    Cliente C1("Karla", "telefono", 23, "contra");
    if (C1.Login("", ""))
    {
        C1.comprar();
        C1.reclamar();
        C1.devolucion();
    }
    else
    {
        exit(0);
    }

    system("pause");
    return 0;
}