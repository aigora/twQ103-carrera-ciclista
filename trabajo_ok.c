
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
