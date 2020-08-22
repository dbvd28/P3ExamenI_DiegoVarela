#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#ifndef PC_H
#define PC_H
class PC
{
private:
    string mascara, ip, nombre;

public:
    PC(string _mascara, string _ip, string _nombre)
    {
        mascara = _mascara;
        ip = _ip;
        nombre = _nombre;
    }
    string getnombre() { return nombre; }
    string getip() { return ip; }
    string getmascara() { return mascara; }
    void toString() { cout << nombre; }
    bool ping(string ip_comunicarse)
    {
        string binario_separador1;
        vector<string> separador_ip1;

        string binario_separador2;
        vector<string> separador_ip2;

        string binario_netmask;
        vector<string> separador_netmask;

        string acum = "";
        string acum1 = "";
        string acum2 = "";

        //separador ip que recibe como parametro
        for (int pos = 0; pos < ip_comunicarse.size(); pos++)
        {
            if (ip_comunicarse[pos] == '.')
            {
                separador_ip1.push_back(acum);
                acum = "";
            }
            else
            {
                acum += ip_comunicarse[pos];
                if (pos == ip_comunicarse.size() - 1)
                {
                    separador_ip1.push_back(acum);
                    acum = "";
                }
            }
        } //separador ip de pc
        for (int pos = 0; pos < ip.size(); pos++)
        {
            if (ip[pos] == '.')
            {
                separador_ip2.push_back(acum1);
                acum1 = "";
            }
            else
            {
                acum1 += ip[pos];
                if (pos == ip.size() - 1)
                {
                    separador_ip2.push_back(acum1);
                    acum1 = "";
                }
            }
        } //separador mascara
        for (int pos = 0; pos < mascara.size(); pos++)
        {
            if (mascara[pos] == '.')
            {
                separador_netmask.push_back(acum2);
                acum2 = "";
            }
            else
            {
                acum2 += mascara[pos];
                if (pos == mascara.size() - 1)
                {
                    separador_netmask.push_back(acum2);
                    acum2 = "";
                }
            }
        } //convertidor de decimal a binario ip mandado como parametro
        for (int i = 0; i < separador_ip1.size(); i++)
        {
            int numero = stoi(separador_ip1[i]);
            if (numero == 0)
            {
                binario_separador1 = "0" + binario_separador1;
            }
            while (numero > 0)
            {
                if (numero % 2 != 0)
                {
                    binario_separador1 = "1" + binario_separador1;
                }
                else
                {
                    binario_separador1 = "0" + binario_separador1;
                }
                numero = (int)numero / 2;
            }
            if (i == separador_ip1.size() - 1)
            {
                binario_separador1 = binario_separador1;
            }
            else
            {
                binario_separador1 = "." + binario_separador1;
            }
        } //convertir a binario el ip de la computadora
        for (int i = 0; i < separador_ip2.size(); i++)
        {
            int numero = stoi(separador_ip2[i]);
            if (numero == 0)
            {
                binario_separador2 = "0" + binario_separador2;
            }
            while (numero > 0)
            {
                if (numero % 2 != 0)
                {
                    binario_separador2 = "1" + binario_separador2;
                }
                else
                {
                    binario_separador2 = "0" + binario_separador2;
                }
                numero = (int)numero / 2;
            }
            if (i == separador_ip2.size() - 1)
            {
                binario_separador2 = binario_separador2;
            }
            else
            {
                binario_separador2 = "." + binario_separador2;
            }

        } //convertir a binario el netmask
        for (int i = 0; i < separador_netmask.size(); i++)
        {
            int numero = stoi(separador_netmask[i]);
            if (numero == 0)
            {
                binario_netmask = "0" + binario_netmask;
            }
            while (numero > 0)
            {
                if (numero % 2 != 0)
                {
                    binario_netmask = "1" + binario_netmask;
                }
                else
                {
                    binario_netmask = "0" + binario_netmask;
                }
                numero = (int)numero / 2;
            }
            if (i == separador_netmask.size() - 1)
            {
                binario_netmask = binario_netmask;
            }
            else
            {
                binario_netmask = "." + binario_netmask;
            }
        } //Sacar los unos de la netmask
        int cont_uno = 0;
        for (int pos = 0; pos < binario_netmask.size(); pos++)
        {
            if (binario_netmask[pos] == '1' || binario_netmask[pos] == '.')
            {
                cont_uno++;
            }
        }
        int cont = 0;
        //comparacion de ip´s
        binario_separador1 = binario_separador1.substr(0, cont_uno);
        binario_separador2 = binario_separador2.substr(0, cont_uno);
        if (binario_separador1 == binario_separador2)
        {
            cout << binario_netmask << endl;
            cout << binario_separador1 << endl;
            cout << binario_separador2 << endl;
            return true;
        }
        else
        {
            cout << binario_netmask << endl;
            cout << binario_separador1 << endl;
            cout << binario_separador2 << endl;
            return false;
        }
    }
};
#endif