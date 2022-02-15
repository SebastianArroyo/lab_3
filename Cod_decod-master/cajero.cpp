#include "cajero.h"
#include "cod.h"

void verif_doc(string text, string document)
{
    bool act=true,cl=false;
    while (act==true) {
        string partido="",clave;
        bool ban=false;
        for (unsigned long long int i=0, cop_i=0;i<text.length() && ban==false;i++) {
            if (text[i]==' ' || text[i]=='\n') {
                partido.clear();
            }
            else {
                partido.push_back(text[i]);
                if (partido.length()==10) {
                    if (partido==document) {
                        i+=2;
                        cop_i=i;
                        while (cl==false) {
                            cout << "Ingrese su clave: "; cin >> clave;
                            for (partido="";text[i]!=' ';i++) {
                                partido.push_back(text[i]);
                            }
                            if (partido==clave) {
                                cout << "Clave correcta." << endl;
                                cl=true;
                            }
                            else {
                                cout << "Clave incorrecta." << endl;
                                i=cop_i;
                            }
                        }
                        ban=true;
                    }
                    partido.clear();
                }
            }
        }
        if (ban==false) {
            cout << "Documento no encontrado." << endl;
            cout << "Ingrese nuevamente su documento: "; cin >> document;
        }
        else {
            act=false;
        }
    }

}

void guardar_reg(string name, string cc, string clave, int monto)
{
    fstream k(name,fstream::app);
    k << '\n' << cc << ' ' << clave << " $" << monto;
    k.close();
}

void ver_saldo(string text, string document)
{
    bool act=true;
    while (act==true) {
        string partido="",monto="";
        for (unsigned long long int i=0;i<text.length();i++) {
            if (text[i]==' ' || text[i]=='\n') {
                partido.clear();
            }
            else {
                partido.push_back(text[i]);
                if (partido.length()==10) {
                    if (partido==document) {
                        for (;text[i]!='\n';i++) {
                            if (text[i]=='$') {
                                i++;
                                monto.clear();
                                monto.push_back(text[i]);
                                i++;
                            }
                            monto.push_back(text[i]);
                        }
                        int valor=0,mul=1,dig=0;
                        for (int o=monto.length()-1;o>=0;o--) {
                            valor+=(int(monto[o])-48)*mul;
                            dig++;
                            mul*=10;
                        }
                        mul/=10;
                        valor-=1000;
                        cout << "Su saldo es: " << valor << endl; cout << endl;
                        text=edit_saldo(text,valor,document,mul,dig);
                        escr_txt("Caracteres_finales.txt",text);
                        codif("Caracteres_finales.txt",4,2);
                        act=false;
                        break;
                    }
                    partido.clear();
                }
            }
        }
    }
}

string edit_saldo(string text, int saldo, string document,int mul, int dig)
{
    string partido,n_text,parte;
    int cd;
    for (;mul>0;mul/=10) {
        cd=(saldo-(saldo%mul))/mul;
        saldo-=(cd*mul);
        parte.push_back(char(cd+48));
    }
    for (unsigned long long int i=0;i<text.length();i++) {
        n_text.push_back(text[i]);
        if (text[i]==' ' || text[i]=='\n') {
            partido.clear();
        }
        else {
            partido.push_back(text[i]);
            if (partido.length()==10) {
                if (partido==document) {
                    i++;
                    for (;text[i]!='\n';i++) {
                        if (text[i]=='$') {
                            n_text.push_back('$');
                            i++;
                            for (int o=0;o<int(parte.length());o++) {
                                n_text.push_back(parte[o]);
                            }
                            i+=(dig-1);
                            break;
                        }
                        n_text.push_back(text[i]);
                    }
                }
            }
        }
    }
    return n_text;
}

void ret_dinero(string text, string document, int ret)
{
    bool act=true;
    while (act==true) {
        string partido="",monto="";
        for (unsigned long long int i=0;i<text.length();i++) {
            if (text[i]==' ' || text[i]=='\n') {
                partido.clear();
            }
            else {
                partido.push_back(text[i]);
                if (partido.length()==10) {
                    if (partido==document) {
                        for (;text[i]!='\n';i++) {
                            if (text[i]=='$') {
                                i++;
                                monto.clear();
                                monto.push_back(text[i]);
                                i++;
                            }
                            monto.push_back(text[i]);
                        }
                        int valor=0,mul=1,dig=0;
                        for (int o=monto.length()-1;o>=0;o--) {
                            valor+=(int(monto[o])-48)*mul;
                            dig++;
                            mul*=10;
                        }
                        mul/=10;
                        valor-=1000;
                        while (valor<ret) {
                            cout << "No tiene fondos suficientes." << endl;
                            cout << "Ingrese valor a retirar: "; cin >> ret;
                        }
                        valor-=ret;
                        cout << "Su saldo es: " << valor << endl; cout << endl;
                        text=edit_saldo(text,valor,document,mul,dig);
                        escr_txt("Caracteres_finales.txt",text);
                        codif("Caracteres_finales.txt",4,2);
                        act=false;
                        break;
                    }
                    partido.clear();
                }
            }
        }
    }
}

//void consulta_saldo(string name, long long cc, int clave){
//    long long ced, cash;
//    int pass; bool encontrado = false;
//    ifstream leer;
//    leer.open(name, ios::in);
//    leer>>ced;
//    while(!leer.eof()){
//        leer>>pass;
//        if(ced==cc && pass==clave){
//            encontrado = true;
//            leer>> cash;
//            cout <<"Su saldo actual es: "<<cash<<endl;
//        }
//        leer>> cash;
//        leer>>ced;
//    }
//    if(!encontrado){
//        cout<<"Cedula o contrasenia incorrecta"<<endl;
//    }
//    leer.close();
//}


//void mod_dinero(string name, long long cc, int clave, int a){

//    ifstream leer; ofstream temp;
//    long long ced, cash, cash2;
//    int pass; bool encontrado = false;
//    leer.open(name);
//    temp.open("temp.txt");
//    leer>>ced;
//    if(a==1){
//        while(!leer.eof()){
//            leer>>pass;
//            leer>>cash;
//            if(ced==cc && pass==clave){
//                encontrado=true;
//                cout<<"Ingrese el monto que desea retirar: "; cin>> cash2; cout<<endl;
//                if(cash2>cash){cout<<"Saldo insuficiente"<<endl; temp.close(); leer.close(); break;}
//                temp<< ced << " " << pass << " " << (cash-cash2)<<endl;
//                cout<<"Retiro de forma exitosa!"<<endl; cout <<endl;
//                cout<<"Costo transaccion: "<<"$0"<<endl;
//                cout<<"Monto retirado: "<<"$"<<cash2<<endl;
//                cout<<"Nuevo saldo: "<<"$"<<(cash-cash2)<<endl;
//            }
//            else{temp<< ced << " " << pass << " " << cash<<endl;
//            }
//            leer>>ced;
//        }
//        if(!encontrado){cout<<"Cedula o contrasenia incorrecta"<<endl;}
//    }
//    else if(a==2){
//        while(!leer.eof()){
//            leer>>pass;
//            leer>>cash;
//            if(ced==cc && pass==clave){
//                encontrado=true;
//                cash2=1000;
//                if(cash2>cash){cout<<"Saldo insuficiente"<<endl;  temp.close(); leer.close(); break;}
//                temp<< ced << " " << pass << " " << (cash-cash2)<<endl;
//                cout<<"Su saldo actual es: "<< "$" <<(cash-cash2)<<endl;
//            }
//            else{temp<< ced << " " << pass << " " << cash<<endl;
//            }
//            leer>>ced;
//        }
//        if(!encontrado){cout<<"Cedula o contrasenia incorrecta"<<endl;}

//    }

//    leer.close();
//    temp.close();
//    remove("sudo.txt");
//    rename("temp.txt","sudo.txt");
//}


//void leer_registros(string name){
//    long long ced, cash;
//    int pass; bool encontrado = false;
//    ifstream leer;
//    leer.open(name);
//    leer>>ced;
//    while (!leer.eof()) {
//        leer>>pass;
//        leer>> cash;
//        cout<<"Cedula: "<< ced<<endl;
//        cout<<"Clave: "<< pass<<endl;
//        cout<<"Saldo: $"<< cash<<endl;
//        cout<<endl;
//        leer>>ced;
//    }
//}


//bool verifi_doc2(string name){
//    long long cc; int clave;
//    cout<<"Ingrese documento de identificacion: "; cin>>cc;
//    cout<<"Ingrese clave: "; cin>>clave;
//    long long ced, cash;
//    int pass; bool encontrado = false;
//    ifstream leer;
//    leer.open(name, ios::in);
//    leer>>ced;
//    while(!leer.eof()){
//        leer>>pass;
//        leer>> cash;
//        if(ced==cc && pass==clave){
//            encontrado = true;
//        }
//        leer>>ced;
//    }
//    leer.close();

//    return encontrado;
//}

