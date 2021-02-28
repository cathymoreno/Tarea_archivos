using namespace std;
#include <iostream>
#include <fstream> //guardar fichero


int main()
{
    int id,opcion,Bid,telefono,Ntelefono,Nnombre,Napellido;
    char nombre[10],apellido[10];
    ofstream Guardar;
    ifstream Leer;
    fstream Temp; //referencia aun archivo temporal
    Guardar.open("Fichero.txt",ios::app);
    while(true)
    {
        cout<<"%%%%%%%%%%%%%%%%%"<<endl;
        cout<<"1 GUARDAR"<<endl;
        cout<<"2 LEER"<<endl;
        cout<<"3 BUSCAR"<<endl;
        cout<<"4 MODIFICAR"<<endl;
        cout<<"5 ELIMINAR"<<endl;
        cout<<"6 SALIR"<<endl;
        cout<<"%%%%%%%%%%%%%%%%%"<<endl;
        cout<<endl;
        cout<<"Elija una opcion:"<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                {
                    system("cls");
                    cout<<"Ingrese Nombre: ";
                    cin>>nombre;
                    cout<<"Ingrese Apellido: ";
                    cin>>apellido;
                    cout<<"Ingrese Numero de Telefono: ";
                    cin>>telefono;
                    cout<<"Ingrese el id:  ";
                    cin>>id;
                    Guardar<<nombre<<" "<<apellido<<" "<<telefono<<" "<<id<<endl;
                    break;
                }
            case 2:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");
                    Leer>>nombre>>apellido>>telefono;
                    while(!Leer.eof())
                    {
                        Leer>>id;
                        cout<<"----------------------------"<<endl;
                        cout<<"Nombre:    "<<nombre<<endl;
                        cout<<"Apellido:  "<<apellido<<endl;
                        cout<<"Telefono:  "<<telefono<<endl;
                        cout<<"ID:    "<<id<<endl;
                        cout<<"----------------------------"<<endl;
                        cout<<endl;
                        Leer>>nombre>>apellido>>telefono;
                    }
                    Leer.close();
                    break;
                }
            case 3:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");
                    Leer>>nombre>>apellido>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese el numero de ID para buscar"<<endl;
                    cin>>Bid;
                    while(!Leer.eof())
                    {
                        Leer>>id;
                        if(id==Bid)
                        {
                            encontrado=true;
                            cout<<"----------------------------"<<endl;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"ID:    "<<id<<endl;
                            cout<<"----------------------------"<<endl;
                            cout<<endl;
                        }
                        Leer>>nombre>>apellido>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"ID no encontrado"<<endl;
                    }
                    Leer.close();
                    break;
                }

            case 4:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");//abre fichero original
                    Temp.open("Temp.txt");//abrimos el temporal tambn
                    Leer>>nombre>>apellido>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese clave a modificar"<<endl;
                    cin>>Bid;
                    while(!Leer.eof())
                    {
                        Leer>>id;
                        if(id==Bid)
                        {
                            encontrado=true;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"ID:    "<<id<<endl;
                            cout<<endl;
                            cout<<"Ingrese su Nombre a modificar"<<endl;
                            cin>>Nnombre;
                            cout<<"Ingrese su Apellido a modificar"<<endl;
                            cin>>Napellido;
                            cout<<"Ingrese nuevo numero de telefono"<<endl;
                            cin>>Ntelefono;
                            Temp<<Nnombre<<" "<<Napellido<<" "<<Ntelefono<<" "<<id<<endl;
                            cout<<endl;
                            cout<<"Modificado"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<telefono<<" "<<id<<endl;
                        }
                        Leer>>nombre>>apellido>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"ID no encontrado"<<endl;
                    }
                    Leer.close();
                    Temp.close();
                    remove("Fichero.txt");
                    rename("Temp.txt","Fichero.txt");
                    break;
                }

            case 5:
                {
                    system("cls");
                    Leer.open("Fichero.txt");
                    Temp.open("Temp.txt");
                    Leer>>nombre>>apellido>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese ID a eliminar"<<endl;
                    cin>>id;
                    while(!Leer.eof())
                    {
                        Leer>>id;
                        if(id==Bid)
                        {
                            encontrado=true;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"ID:    "<<id<<endl;
                            cout<<endl;
                            cout<<"Eliminado"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<telefono<<" "<<id<<endl;
                        }
                        Leer>>nombre>>apellido>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"ID no encontrado"<<endl;
                    }
                    
                    remove("Fichero.txt");
                    rename("Temp.txt","Fichero.txt");

                    break;
                }

            case 6:
                {
                    system("cls");

                    break;
                }   
        }   
    }
    return 0;
}
