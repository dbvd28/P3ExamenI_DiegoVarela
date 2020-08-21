#include <string>
#include <vector>
#include <cstring>
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
    void tostring(){cout<<nombre;}
    bool ping(string ip_comunicarse)
    {
        string binario_separador1;
        vector<string > separador_ip1;
        separador_ip1.push_back("");
        separador_ip1.push_back("");
        separador_ip1.push_back("");
        separador_ip1.push_back("");
        string binario_separador2;
        vector<string > separador_ip2;
        separador_ip2.push_back("");
        separador_ip2.push_back("");
        separador_ip2.push_back("");
        separador_ip2.push_back("");
        string binario_netmask;
        vector<string > separador_netmask;
        separador_netmask.push_back("");
        separador_netmask.push_back("");
        separador_netmask.push_back("");
        separador_netmask.push_back("");
        int cont = 0;
        int cont1 = 0;
        int cont2 = 0;
        //separador ip que recibe como parametro
        for (int pos = 0; pos < ip_comunicarse.size(); pos++)
        {
            if (ip_comunicarse[pos] == '.')
            {
                cont++;
            }
            else
            {
                separador_ip1[cont] += ip_comunicarse[pos];
            }
        } //separador ip de pc
        for (int pos = 0; pos < ip.size(); pos++)
        {
            if (ip[pos] == '.')
            {
                cont1++;
            }
            else
            {
                separador_ip2[cont1] += ip[pos];
            }
        } //separador mascara
        for (int pos = 0; pos < mascara.size(); pos++)
        {
            if (mascara[pos] == '.')
            {
                cont2++;
            }
            else
            {
                separador_netmask[cont2] += mascara[pos];
            }
        } //convertidor de decimal a binario ip mandado como parametro
        for (int i = 0; i < separador_ip1.size(); i++)
        {
            int numero = stoi(separador_ip1[i]);
            if (numero > 0)
            {
                while (numero > 0)
                {
                    if (numero % 2 == 0)
                    {
                        binario_separador1 += "0";
                    }
                    else
                    {
                        binario_separador1 += "1";
                    }
                    numero = numero / 2;
                }
            }
            else if (numero == 0)
            {
                binario_separador1 += "0";
            }
            if (i == separador_ip1.size() - 1)
            {
                binario_separador1 = binario_separador1;
            }
            else
            {
                binario_separador1 += ".";
            }
        } //convertir a binario el ip de la computadora
        for (int i = 0; i < separador_ip2.size(); i++)
        {
            int numero = stoi(separador_ip2[i]);
            if (numero > 0)
            {
                while (numero > 0)
                {
                    if (numero % 2 == 0)
                    {
                        binario_separador2 += "0";
                    }
                    else
                    {
                        binario_separador2 += "1";
                    }
                    numero = numero / 2;
                }
            }
            else if (numero == 0)
            {
                binario_separador2 += "0";
            }
            if (i == separador_ip2.size() - 1)
            {
                binario_separador2 = binario_separador2;
            }
            else
            {
                binario_separador2 += ".";
            }
        } //convertir a binario el netmask
        for (int i = 0; i < separador_netmask.size(); i++)
        {
            int numero = stoi(separador_netmask[i]);
            if (numero > 0)
            {
                while (numero > 0)
                {
                    if (numero % 2 == 0)
                    {
                        binario_netmask += "0";
                    }
                    else
                    {
                        binario_netmask += "1";
                    }
                    numero = numero / 2;
                }
            }
            else if (numero == 0)
            {
                binario_netmask += "0";
            }
            if (i == separador_netmask.size() - 1)
            {
                binario_netmask = binario_separador1;
            }
            else
            {
                binario_netmask += ".";
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
        //comparacion de ip´s
        binario_separador1 = binario_separador1.substr(0, cont_uno);
        binario_separador2 = binario_separador2.substr(0, cont_uno);
        if (binario_separador1 == binario_separador2)
        {
            return true;
        }else{
            return false;
        }
    }
};
#endif