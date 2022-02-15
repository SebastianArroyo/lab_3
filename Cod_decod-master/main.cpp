#include "cod.h"
#include "deco.h"
#include "cajero.h"

int main()
{
    int elec=0;
    bool menu=true,menu1=true, menu2=true, menu3=true, menul=true;
    cout << "Bienvenido!" << endl;
    while (menu==true) {
        cout << "1. Codificar y decodificar archivos" << endl;
        cout << "2. Cajero" << endl;
        cout << "3. Salir" << endl;
        cout << endl;
        cout << "Ingrese una opcion: "; cin >> elec; cout<<endl;
        menul=true;
        while (menul==true) {
            switch (elec) {
            case 1: //Codificar o decodificar archivos
            {
                cout<<"1. Si desea trabajar con el metodo 1" << endl;
                cout << "2. Si desea trabajar con el metodo 2" << endl;
                cout << endl;
                cout << "Ingrese una opcion: "; cin >> elec; cout<<endl;
                switch (elec) {
                case 1: //Metodo 1
                {
                        cout<<"1. Si desea codificar" << endl;
                        cout<<"2. Si desea decodificar"<<endl; cout<<endl;
                        cout << "Ingrese una opcion: "; cin >> elec; cout<<endl;
                        switch (elec) {
                        case 1: //Codificar
                        {
                            string nombre;
                            cout << "Ingrese nombre del archivo con la extension: "; cin >> nombre;
                            int n;
                            cout << "Ingrese la semilla n: ";
                            cin >> n;
                            codif(nombre,n,1);
                            cout << endl;
                        }
                        break;

                        case 2: //Decodificar
                        {
                            int n;
                            string arch_cod;
                            cout << "Ingrese nombre del archivo a decodificar: "; cin >> arch_cod;
                            cout << "Ingrese la semilla n: ";
                            cin >> n;
                            decod(arch_cod,n,1);
                        }
                        break;
                        }
                        menul=false;
                }
                break;

                case 2:
                { //Metodo 2
                    cout << "Esto no funciona :c" << endl << endl;
//                    cout<<"1. Si desea codificar";
//                    cout<<endl;
//                    cout<<"2. Si desea decodificar"<<endl; cout<<endl;
//                    cout << "Ingrese una opcion: "; cin >> elec; cout<<endl;
//                    switch (elec) {

//                    case 1:{ //Codificar
//                        string name, file;
//                        cout <<"Ingrese nombre con extension del archivo a codificar: ";
//                        cin >> name; cout<<endl;
//                        unsigned long long tam;
//                        file=leer_txt(name);
//                        tam=file.length();
//                        char *arreglo = new char [tam];
//                        char *arreglo2 = new char [tam*8];
//                        char *arreglo3 = new char [tam*8];

//                        for(unsigned long long i=0;i<tam;i++){   arreglo[i]=file[i];}

//                        texto2bin_in_char(arreglo, arreglo2, tam);cout<<endl;
//                        cout<< "Ingrese la semilla: ";
//                        int n;  cin >>n; cout<<endl;
//                        codificar_char(arreglo2, arreglo3, n, tam); cout<<endl;
//                        charbinario2text(arreglo, arreglo3, tam);
//                        cout<<"Ingrese nombre y extension para guardar el archivo: "; cin >> name; cout<<endl;
//                        ofstream guardar;
//                        guardar.open(name, ios::binary);
//                        guardar << arreglo;
//                        guardar.close();

//                        delete [] arreglo;
//                        delete [] arreglo2;
//                        delete [] arreglo3;

//                        break;
//                    }

//                    case 2:{
//                        string name, file;
//                        cout <<"Ingrese nombre con extension del archivo a decodificar: ";
//                        cin >> name;
//                        unsigned long long tam;
//                        file=leer_txt(name);
//                        tam=file.length();
//                        char *arreglo = new char [tam];
//                        char *arreglo2 = new char [tam*8];
//                        char *arreglo3 = new char [tam*8];

//                        for(unsigned long long i=0;i<tam;i++){
//                            arreglo[i]=file[i];
//                        }
//                        texto2bin_in_char(arreglo, arreglo2, tam); cout<<endl;
//                        cout<< "Ingrese la semilla: ";
//                        int n;  cin >>n; cout<<endl;
//                        descodificar_char(arreglo2, arreglo3, n, tam); cout<<endl;
//                        charbinario2text(arreglo, arreglo3, tam); cout<<endl;
//                        cout<<"Ingrese nombre y extension para guardar el archivo: "; cin>>name; cout<<endl;
//                        cout<<"Archivo correctamente guardado!!"<<endl; cout<<endl;
//                        ofstream guardar2;
//                        guardar2.open(name, ios::out);
//                        guardar2 << arreglo;
//                        guardar2.close();

//                        delete [] arreglo;
//                        delete [] arreglo2;
//                        delete [] arreglo3;
//                    }
//                    break;
//                    }
//                }
                }
                menul=false;
                break;
            }
            }
            break;

            case 2: //cajero --------------------------------------------------------------------
            {
                cout << "Bienvenido al cajero" << endl << endl;
                int n=4,a=0,opcion=0;
                menu1=true;
                while (menu1==true) {
                    string encrip="sudo.txt",todo_doc="",doc;
                    decod(encrip,n,2);
                    todo_doc=leer_txt("Caracteres_finales.txt");
                    string text="";
                    for (int a=0;a<int(todo_doc.length()-2);a++) {
                        text.push_back(todo_doc[a]);
                    }
                    cout << "1. Administrador" << endl;
                    cout << "2. Usuario de sistema" << endl;
                    cout << "3. Volver al menu principal" << endl;
                    cout << "4. Salir" << endl;
                    cout << endl;
                    cout << "Ingrese el rol a emplear: "; cin >> a; cout << endl;
                    menu2=true;
                    while (menu2==true) {
                        switch (a) {
                        case 1:{ //Admin
                            cout << "Ingrese documento de identificacion: "; cin >> doc;
                            verif_doc(text,doc);
                            cout << endl; cout << "Bienvenido!" << endl; cout << endl;
                            menu3=true;
                            while (menu3==true) {
                                cout << "1. Guardar Registro" << endl;
                                cout << "2. Leer Registros" << endl;
                                cout << "3. Salir de Administrador" << endl << endl;
                                cout << "Ingrese una opcion: "; cin >> opcion; cout << endl;
                                switch (opcion) {
                                case 1:{
                                    string cc, clave;
                                    int monto;
                                    cout<<"Ingrese nuevo documento de identificacion: "; cin>>cc;
                                    cout<<"Ingrese nueva clave: "; cin>>clave;
                                    cout<<"Ingrese el dinero: "; cin>> monto; cout << endl;
                                    guardar_reg("Caracteres_finales.txt", cc, clave, monto);
                                    cout<<"Registro exitoso!"; cout << endl << endl;
                                    codif("Caracteres_finales.txt",n,2);
                                    menu2=false;
                                }
                                break;

                                case 2:{
                                    string encrip="sudo.txt",todo_doc="",doc;
                                    decod(encrip,n,2);
                                    todo_doc=leer_txt("Caracteres_finales.txt");
                                    string text="";
                                    for (int a=0;a<int(todo_doc.length()-2);a++) {
                                        text.push_back(todo_doc[a]);
                                    }
                                    cout << text << endl; cout << endl;
                                }
                                break;

                                case 3:
                                {
                                    menu3=false;
                                    menu2=false;
                                }
                                break;

                                default:
                                {
                                    cout << "Ingrese un numero valido" << endl << endl;
                                    break;
                                }
                                break;
                                }
                            }
                        }
                        break;

                        case 2: // Usuario
                        {
                            cout << "Ingrese numero de identificacion: "; cin >> doc;
                            verif_doc(text,doc); cout << endl;
                            menu3=true;
                            while (menu3==true) {
                                cout << "1. Consultar saldo" << endl;
                                cout << "2. Retirar dinero" << endl;
                                cout << "3. Salir de Usuario" << endl << endl;
                                cout << "Ingrese una opcion: "; cin >> opcion; cout << endl;
                                switch (opcion) {
                                case 1:
                                {
                                    int a=0;
                                    cout<<"El Costo de esta transaccion es de $1000. Desea continuar?" << endl;
                                    cout << endl;
                                    cout<<"1. Si"<<endl;
                                    cout<<"2. No"<<endl; cout<<endl;
                                    cout<<"Ingrese opcion: "; cin >> a; cout<<endl;
                                    switch (a) {
                                    case 1:
                                    {
                                        string encrip="sudo.txt",todo_doc="";
                                        decod(encrip,n,2);
                                        todo_doc=leer_txt("Caracteres_finales.txt");
                                        string text="";
                                        for (int a=0;a<int(todo_doc.length()-2);a++) {
                                            text.push_back(todo_doc[a]);
                                        }
                                        ver_saldo(text,doc);
                                    }
                                    break;

                                    case 2:
                                    {
                                        menu3=false;
                                        menu2=false;
                                    }
                                    break;

                                    default:
                                    {
                                        cout << "Ingrese un numero valido" << endl << endl;
                                    }
                                    break;
                                    }
                                }
                                break;

                                case 2:
                                {
                                    int a, retirar=0;
                                    cout<<"El Costo de esta transaccion es de $1000. Desea continuar?" << endl;
                                    cout << endl;
                                    cout<<"1. Si"<<endl;
                                    cout<<"2. No"<<endl; cout<<endl;
                                    cout<<"Ingrese opcion: "; cin >> a; cout<<endl;
                                    switch (a) {
                                    case 1:
                                    {
                                        todo_doc=leer_txt("Caracteres_finales.txt");
                                        string text="";
                                        for (int a=0;a<int(todo_doc.length()-2);a++) {
                                            text.push_back(todo_doc[a]);
                                        }
                                        ver_saldo(text,doc); cout << endl;
                                        cout << "Ingrese valor a retirar: "; cin >> retirar; cout << endl;
                                        ret_dinero(text,doc,retirar);
                                    }
                                    break;

                                    case 2:
                                    {
                                        menu2=false;
                                    }
                                    break;

                                    default:
                                    {
                                        cout << "Ingrese un numero valido" << endl << endl;
                                    }
                                    break;
                                    }
                                }
                                break;

                                case 3:
                                {
                                    menu3=false;
                                    menu2=false;
                                }
                                break;

                                default:
                                {
                                    cout << "Ingrese un numero valido" << endl << endl;
                                }
                                break;
                                }
                            }
                        }
                        break;

                        case 3: //Volver
                        {
                            menu2=false;
                            menu1=false;
                            menul=false;
                        }
                        break;

                        case 4: //Salir
                        {
                            menu2=false;
                            menu1=false;
                            menul=false;
                            menu=false;
                        }
                        break;

                        default:{
                            cout << "Debe ingresar un numero valido" << endl << endl;
                            menu2=false;
                        }
                        break;
                        }
                    }
                }
            }
            break;

            case 3:
            {
                menu=false;
                menul=false;
            }
            break;

            default:{
                cout << "Ingrese un numero valido" << endl << endl;
            }
            }
        }
    }
}
