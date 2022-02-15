#ifndef CAJERO_H
#define CAJERO_H
#include <arch.h>
#include <cod.h>

void verif_doc(string text, string document);
void guardar_reg(string name, string cc, string clave, int monto);
void ver_saldo(string texto, string document);
string edit_saldo(string text, int saldo,string document,int mul, int dig);
void ret_dinero(string texto, string document, int ret);
void consulta_saldo(string name, long long cc, int clave);
void mod_dinero(string name, long long cc, int clave, int a);
void leer_registros(string name);
bool verifi_doc2(string name);

#endif // CAJERO_H
