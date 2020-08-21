#include <iostream>
#include <string>
#include "PC.hpp"
#include <vector>
using namespace std;
int main()
{
    vector<PC *> pcs;
    bool vivo = true;
    while (vivo == true)
    {

        int opcion = 0;
        cout << "1) Agregar una PC" << endl
             << "2) Ingresar a PC" << endl;
        cout << "3) Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string nombre, mascara, ip;
            cout << "Ingrese el nombre" << endl;
            cin >> nombre;
            cout << "Ingrese el IP" << endl;
            cin >> ip;
            cout << "Ingrese el mascara de red" << endl;
            cin >> mascara;
            pcs.push_back(new PC(mascara, ip, nombre));
            cout << "Creada con exito" << endl;
        }
        break;
        case 2:
        {
            int opcion2;
            bool exit = false;
            for (int i = 0; i < pcs.size(); i++)
            {
                cout << i << " ";
                pcs[i]->tostring();
                cout << endl;
            }
            cout << "En que computadora desea ingresar:" << endl;
            cin >> opcion2;
            while (exit == false)
            {
                bool ip_encontrada = false;
                string comando;
                cout << pcs[opcion2]->getnombre() << "#";
                cin >> comando;
                int tamano = comando.size();
                string comando_ping;
                comando_ping = comando.substr(0, 4);
                cout << comando_ping << endl;

                if (comando == "show")
                {
                    cout << "IP: " << pcs[opcion2]->getip() << endl;
                    cout << "Netmask: " << pcs[opcion2]->getmascara() << endl;
                }
                else if (comando_ping == "ping")
                {
                    cout<<comando.substr(5, comando.size());
                    for (int i = 0; i < pcs.size(); i++)
                    {
                        if (pcs[i]->getip() == comando.substr(5, comando.size()))
                        {
                            ip_encontrada = true;
                        }
                    }
                    if (ip_encontrada == true)
                    {
                        bool exitoso = pcs[opcion2]->ping(comando.substr(5, comando.size()));
                        if (exitoso == true)
                        {
                            cout << "Pinging to: " << comando.substr(5, comando.size()) << " with 32 bytes of data: " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
                            cout << "Ping statistic for " << comando.substr(5, comando.size()) << " :" << endl;
                            cout << "Packets: Sent = 4,Received = 4, Lost = 0 (0% loss)" << endl;
                        }
                        else if (exitoso == false)
                        {
                            cout << "Pinging to: " << comando.substr(5, comando.size()) << " with 32 bytes of data: " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
                            cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
                            cout << "Ping statistic for " << comando.substr(5, comando.size()) << " :" << endl;
                            cout << "Packets: Sent = 4,Received = 4, Lost = 0 (0% loss)" << endl;
                        }
                    }
                    else
                    {
                        cout << "Pinging to: " << comando.substr(5, comando.size()) << " with 32 bytes of data: " << endl;
                        cout << "Requested tomed out." << endl;
                        cout << "Requested tomed out." << endl;
                        cout << "Requested tomed out." << endl;
                        cout << "Requested tomed out." << endl;
                        cout << "Ping statistic for " << comando.substr(5, comando.size()) << " :" << endl;
                        cout << "Packets: Sent = 4,Received = 0, Lost = 4 (100% loss)" << endl;
                    }
                }
                else if (comando == "exit")
                {
                    exit = true;
                }
            }
        }
        break;
        case 3:
        vivo=false;
        break;
        }
    }
}