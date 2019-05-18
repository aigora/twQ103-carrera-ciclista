/* VUELTA CICLISTA
Para probar el programa: compilar y ejecutar, introducir un nombre, apellido y dni (puede ser un simple numero),
por ejemplo, miguel indurain 123456789, y añadir unos tiempos de carrera,
posteriormente añadir más corredores y sus tiempos, recomendable añadir mas de 3,
al añadir 3 o más se pueden realizar todas los operaciones del menu sin que afecte al codigo,
ya que siendo menos de 3, si queremos eliminar participantes, el podio quedara con participantes eliminados*/

#include<stdio.h>
#include<string.h>
#include <time.h> 
//#include <dos.h>

typedef struct 
{
	int horas;
	int mins;
	int segundos;
}tiempo;

typedef struct
{
	char nombre[20];
	char apellido[20];
	char dni[10];
	char anfitrion[10];
	int dorsal;
	tiempo tiempo;
}Corredores;



void menu();
void print();
void buscar();
void tiempos();
void eliminar();
void clasificaciones();
void ordenar();
void imprimir_tiempos();
void fin();


int main() 
{ 
	double op=0;
	clock_t start, end; 
	start = clock(); 

	int i,a;
	Corredores corredores[100];
	for( i = 0 ; i < 100 ; i++)
	{
		corredores[i].nombre[0] = '\0';
		corredores[i].apellido[0] = '\0';
		corredores[i].dni[0] = '\0';
		corredores[i].dorsal = -1;
		corredores[i].tiempo.horas = 0;
		corredores[i].tiempo.mins = 0;
		corredores[i].tiempo.segundos = 0;
	}
	menu(corredores);
	
	end = clock(); 
	op=(end - start)/ CLK_TCK;
	printf("\n\nLa operacion se ha realizado en : %.2f segundos\n\n", op); 
	system("pause");
	return;
}


void menu(Corredores *corredores)
{
	int opcion;
	int last_dorsal = 1;
	printf("PROGRAMA DE GESTION DE LA VUELTA CICLISTA \n");

	do
	{
		printf("\nELIJA UNA OPCION\n");
		printf("1. REGISTRAR UN CORREDOR\n");
		printf("2. REGISTRAR TIEMPOS\n"); 
		printf("3. REALIZAR UNA BUSQUEDA POR DORSAL\n");             
		printf("4. ELIMINAR CORREDOR POR DNI\n");
		printf("5. CLASIFICACION\n");
		printf("6. IMPRIMIR TIEMPOS EN FORMATO .txt \n");
		printf("7. SALIR DEL PROGRAMA\n\n"); 
		scanf ("%d", &opcion);

		switch(opcion)
		{
			case 1:
			{					
				printf("Seleccion:1. REGISTRAR UN CORREDOR\n");
				printf("Introduzca el nombre:\t\t");
				scanf("%s", corredores[last_dorsal-1].nombre);
				printf("Introduzca Primer Apellido:\t");
				scanf("%s", corredores[last_dorsal-1].apellido);
				printf("Introduzca su DNI:\t\t");
				scanf("%s", corredores[last_dorsal-1].dni);
				corredores[last_dorsal-1].dorsal = last_dorsal;
				printf("Su dorsal es el:\t%d\n", corredores[last_dorsal-1].dorsal);
				printf("\nCorredor registrado correctamente\n\n");
				last_dorsal++;
				break;
			}
			case 2:
			{
				printf("Seleccion:2. REGISTRAR TIEMPOS\n");
				tiempos(corredores);
				break;
			}	
			case 3:
			{
				printf("Seleccion:3. REALIZAR UNA BUSQUEDA POR DORSAL\n");
				buscar(corredores); 
				break;
			}		    
			case 4:
			{
				printf("Seleccion:4. ELIMINAR CORREDOR POR DNI\n");
				eliminar(corredores);
				break;
			}
			case 5:
			{
				printf("Seleccion:5. CLASIFICACION\n");
				clasificaciones(corredores, last_dorsal);
				break;
			}
			case 6:
			{
				printf("Seleccion:6. IMPRIMIR TIEMPOS EN FORMATO .txt \n");
				imprimir_tiempos(corredores, last_dorsal);
				break;
			}
			case 7:
			{
				printf("Seleccion:7. SALIR DEL PROGRAMA\n");
				fin();
				break;
			} 
			default:
			{
				printf("opcion incorrecta\n\n");
			}
			sleep(1);     //permite volver al menu esperando un breve espacio de tiempo
		}
	} while(opcion!=7);
}

 //funciones del programa

void print(Corredores *corredores)
{
	int i;
	printf("Nombre: %s %s\n", corredores[i].nombre, corredores[i].apellido);
	printf("Dorsal: %d \n", corredores[i].dorsal);
	printf("Tiempo: %d h %d min %d s\n", corredores[i].tiempo.horas, corredores[i].tiempo.mins, corredores[i].tiempo.segundos);
	return;
}


void buscar(Corredores *corredores)
{
	int dorsal;
	int i;
	printf("Ingrese el numero de dorsal\n");
	scanf("%d", &dorsal);
	for(i=0;i<=100;i++)
	{
		if(corredores[i].dorsal== dorsal)
		{
			print(corredores);
			return;
		}
	}
	printf("El corredor no ha sido encontrado o ha sido eliminado previamente\n\n");
}
 
 
//selecciona el tiempo en h, mins y s de cada corredor 
void tiempos(Corredores *corredores)
{
	int dorsal;
	int i;
	printf("Introduce el dorsal: ");
	scanf("%d", &dorsal);
	
	for(i=0;i<=100;i++)
	{
		if(corredores[i].dorsal == dorsal)
		{	
			printf("Ingrese los tiempos(horas, minutos, segundos) \n");
			printf("Introduce horas\n ");
			scanf("%d", &corredores[i].tiempo.horas);
			do
			{
				printf("Introduce mins\n ");
				scanf("%d", &corredores[i].tiempo.mins);
				if(corredores[i].tiempo.mins > 60)
				{
					printf("Los minutos deben ser menores de 60\n");
				}
			}while(corredores[i].tiempo.mins > 60);
			
			do
			{
				printf("Introduce segundos\n ");
				scanf("%d", &corredores[i].tiempo.segundos);
				if(corredores[i].tiempo.segundos > 60)
				{
					printf("Los segundos deben ser menores de 60\n");
				}
			} while(corredores[i].tiempo.segundos > 60);
		return;
		}
	}
}


// elimina los datos de los corredores del registro
void eliminar(Corredores *corredores)
{
	char dni[10];
	dni[0] = '\0';
	int i, u;
	printf("Ingrese el dni que desea Eliminar\nLos Datos no seran Recuperados:\n");
	scanf("%s", dni);
		
	for(i=0 ; i < 100 ; i++)
	{
		if (strcmp(corredores[i].dni, dni)==0)
		{
			printf("Se elimino el corredor\n");			
			print(corredores);
			
			corredores[i].nombre[0] = '\0';
			corredores[i].apellido[0] = '\0';
			corredores[i].dorsal= 0;
		}
	}
}


//coge los datos de los corredores y los ordena de menor a mayor segun su tiempo de carrera
void ordenar (Corredores *corredores, int last_dorsal)
{
  int i, j, aux;
  int ob = 0;
  
  for (i = last_dorsal-2; i>= 0+1 ; i--)
  {
    for (j = 0; j<= i-1 ; j++)
    {
		if (corredores[j].tiempo.horas > corredores[j+1].tiempo.horas)
		{
            aux = corredores[j].tiempo.horas;
            corredores[j].tiempo.horas = corredores[j+1].tiempo.horas;
            corredores[j+1].tiempo.horas = aux;
		}
    	else if (corredores[j].tiempo.horas == corredores[j+1].tiempo.horas)
		{
			if(corredores[j].tiempo.mins > corredores[j+1].tiempo.mins)
			{
    		    aux = corredores[j].tiempo.mins;
                corredores[j].tiempo.mins = corredores[j+1].tiempo.mins;
                corredores[j+1].tiempo.mins = aux;;    
			}
			else if(corredores[j].tiempo.mins == corredores[j+1].tiempo.mins)
			{
				if(corredores[j].tiempo.segundos > corredores[j+1].tiempo.segundos)
				{
	    			aux = corredores[j].tiempo.segundos;
					corredores[j].tiempo.segundos = corredores[j+1].tiempo.segundos;
					corredores[j+1].tiempo.segundos = aux;;		  
				}
			}
		}
      ob ++;
    }
  }
}


//imprime en pantalla los datos de los corredorees despues de ordenarlos e identificar el ganador
void clasificaciones(Corredores *corredores, int last_dorsal)
{

	int i, j,contador;
    ordenar(corredores, last_dorsal);
    
    printf("Seleccione el pais anfitrion de la vuelta ciclista\t");
    scanf("%s", corredores[last_dorsal-1].anfitrion);
    printf("\n\tEn este gran premio de %s:", corredores[last_dorsal-1].anfitrion);
    
    for(i = 0 ; i < last_dorsal -2 ; i++ )
	{
		if (corredores[i].dorsal != 0)
		{
    		printf("\n\t\t-%dº -> dorsal: %d ", i+1, corredores[i].dorsal);			
		}	
		else if (corredores[i].dorsal == 0)
		{
			printf("\n\t\t-%dº -> dorsal: %d (corredor eliminado)", i+1, corredores[i].dorsal);	
		}
    }
    
    printf("\n\tEl dorsal del mejor tiempo es: %d", corredores[0].dorsal);
    printf("\n\tEl dorsal del peor tiempo es: %d \n\n", corredores[last_dorsal-2].dorsal);
    
    return;
}


//crea un archivo que recoge los datos de los corredorees despues de ordenarlos
void imprimir_tiempos(Corredores *corredores, int last_dorsal)
{
	FILE *f;
	int i;
	f=fopen("tiempo.txt","w");
	
	if( f==NULL ) 
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		for(i=0; i<last_dorsal -1; i++)
		{
			fprintf(f,"Dorsal: %d\t", corredores[i].dorsal);
			if (corredores[i].dorsal!=0)
			{
				fprintf(f,"\n%d h : ", corredores[i].tiempo.horas);
		    	fprintf(f,"%d min : ", corredores[i].tiempo.mins);
		    	fprintf(f,"%d s\n", corredores[i].tiempo.segundos);
			}
		    else if(corredores[i].dorsal==0)
		    {
				fprintf(f,"(Corredor eliminado)\n");		    	
			}
		}
	}
	fclose(f);
}


//finaliza el programa
void fin()
{
	printf("El programa ha sido finalizado con exito");
	return;
}
