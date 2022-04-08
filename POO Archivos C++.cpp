#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void leer();
void crear();
void actualizar();
void eliminar();

const char *nom_arch="archivo.dat";
const char *temp="temporal.dat";

struct Estudiante{
	int n;
	int codigo;
	char nombre[50];
	char apellido[50];
	char direccion[50];
	int telefono;
};
main(){
	int n=0;
	char con;
	do{
			system("cls");
			cout<<"Seleccione una Opcion:\n1.Ver Estudiantes\n2.Ingresar Estudiantes\n3.Actualizar Estudiantes\n4.Eliminar Estudiantes\n";
			cin>>n;
		switch(n){
			case 1:
				leer(); break;
			case 2:
				crear(); break;
			case 3:
				actualizar(); break;
				case 4:
			eliminar(); break;
			default:
				cout<<"El numero seleccionado no es una opcion, vuelva a intentarlo";			
		}
		
			cout<<"Realizar otra accion? (s/n): ";
			cin>>con;
	}while(con=='s'||con=='S');
	

}

void leer(){
	system("cls");
	FILE* archivo=fopen(nom_arch,"rb");
	if(!archivo){
		archivo=fopen(nom_arch,"w+b");
	}
	Estudiante estudiante;
	int id_nombre=0;
	cout<<"Id |Codigo |    Nombre    |    Apellido   |  Dreccion  |  Telefono  \n";
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
	cout<<id_nombre<<"  | "<<estudiante.codigo<<"   |    "<<estudiante.nombre<<" |   "<<estudiante.apellido<<" |  "<<estudiante.direccion<<"  |  "<<estudiante.telefono<<endl;

	fread(&estudiante, sizeof(Estudiante), 1, archivo);
	id_nombre++;
	} while (feof(archivo)== 0);
	fclose(archivo);
}	

void crear(){
	char continuar;
	FILE* archivo=fopen(nom_arch, "ab");
	
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
	fflush(stdin);
			
	cout<<"Ingrese el Codigo:";
	cin>>estudiante.codigo;
    cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
	strcpy(estudiante.apellido, apellido.c_str()); 
	
	cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
	strcpy(estudiante.direccion, direccion.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agragar Otro Estudiante ? (s/n): ";
		cin>>continuar;
	}while(continuar=='s'||continuar=='S');
	fclose(archivo);
}

void actualizar(){

	FILE* archivo=fopen(nom_arch,"r+b");
	int id;
	char con;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
		system("cls");
		leer();
	cout << "Ingrese el ID que desea Modificar: ";
    	cin >> id;
    	fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
	
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
	fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"Desea Modificar Otro Estudiante? (s/n): ";
	cin>>con;
	}while(con=='s'||con=='S');
		
	fclose(archivo);
}


void eliminar(){
 	
	FILE *archivo, *archivo_temp; 	
	Estudiante estudiante; 
	archivo_temp=fopen(temp,"w+b");
	archivo=fopen(nom_arch,"rb"); 
	system("cls");
	leer();
	int id=0,i=0;
	cout<<"Ingrese El Id Para Eliminar:"; 
	cin>>id; 	                      				                
	                                                                                
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){ 	
	if (i != id){
	fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
	} 
	i++;
	}
	fclose(archivo_temp); 
	fclose(archivo);                 
	archivo_temp=fopen(temp,"rb"); 
	archivo=fopen(nom_arch,"wb");
	while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
	fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
	}
	                
	fclose(archivo_temp);
	fclose(archivo); 
	leer();	
}	


