#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<locale.h>
#include<wchar.h>

void portada();
void menu();
void terminar();
void error();

int op;		//opcion del menú


int main(){
     portada();
      do{
		menu();
		
		switch (op){
			case 1:
				calcularCeqSerie();				
			break;
			case 2:
				calcularCeqParalelo();
			break;
			case 3:
				calcularReqSerie();				
			break;
			case 4:
				calcularReqParalelo();
			break;
			case 5:
			break;
			default:
				printf("La opción que ingreso es invalida, por favor pruebe con otra opcion\n");	
			break;			
		}
		system("pause");
		system("cls");
	}while(op!=5);
}

void portada(){
	setlocale(LC_ALL,"");
	printf("\n\n\n");
	printf("\t\t  INSTITUTO POLITECNICO NACIONAL\n\n");
	printf("\t\t\t    UPIICSA\n\n");
	printf("\t\t    Fisica para informaticos\n\n");
	printf("\t\t    CALCULO DE CAPACITANCIAS Y \n");	
	printf("\t\t    RESISTENCIAS EQUIVALENTES \n\n");
	printf("\t\t\t    1NM13\n\n");
	printf("\t\t   AUTOR:Omar Duran Pineda\n\n");


	system("pause");
	system("cls");
}
void menu(){	
	printf("\n\n");
	printf("\t\t  Bienvenido\tAutor:Omar Duran \n");
	printf("\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t\n");
	printf("\t\t\tCalculo de Ceq y Req\t\n");
	printf("\t\t\t\t\t\t\n");
	printf("\t\t\t1.Ceq en serie\t\t\n");
	printf("\t\t\t2.Ceq en paralelo\t\t\n");
	printf("\t\t\t3.Req en serie \t\t\n");
	printf("\t\t\t4.Req en paralelo\t\t\t\n"); 
	printf("\t\t\t5.Salir\t\t\t\n"); 
	printf("\t\t\t\t\t\t\n");	
	printf("\t\t   Elija una opción (1-5): ");
	scanf("%i",&op);
	printf("\n\n");
	system("pause");
	
}

void calcularReqSerie(){
	int numeroResistencias;
	float voltajeTotal;
	float resistencias[50];
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t\t \n");
	printf("\t\t\tCalcular Req en Serie\t\t\n");

	printf("\t\t\t\t\t\t \n");
	printf("\t Cuanto voltaje fluye en este circuito(Volts)?\t");
	scanf("%f",&voltajeTotal);
	printf("\n");

	printf("\t Cuantas resistencias se utilizaran?\t");
	scanf("%d",&numeroResistencias);	
	
		
	printf("\t Unidad de medida (ohms)\t\n");

	printf("\n");
	
	int cont;
	float suma=0;
	for(cont=1;cont<=numeroResistencias;cont++) {
		printf("\t Introduce el valor de la resistencia R%d\t", cont);
		scanf("%f",&resistencias[cont]);
		suma+=resistencias[cont];	
	}
	
	float intensidadTotal;
	float potenciaTotal;
	
	intensidadTotal= voltajeTotal / suma;
	potenciaTotal= voltajeTotal*intensidadTotal;
	
	printf("\t La Req es: %.2f ohms\t\n",suma);
	//	printf("\n");

	printf("\t La intensidad total es: %.2f A\t\n",intensidadTotal);
	printf("\t La potencia total disipada es: %.2f W\t\n",potenciaTotal);
	
	for(cont=1;cont<=numeroResistencias;cont++) {
	printf("\t La I%d = %.2f A\t\n", cont, intensidadTotal);
	}
			
			for(cont=1;cont<=numeroResistencias;cont++) {
			
			float voltaje= intensidadTotal * resistencias[cont];
			
			printf("\t El V%d = %.2f V\t\n", cont, voltaje);
	}
			
			
				for(cont=1;cont<=numeroResistencias;cont++) {
			
			float potencia= (intensidadTotal*intensidadTotal) * resistencias[cont];
			
			printf("\t El P%d = %.2f W\t\n", cont, potencia);
	}		
		
}
void calcularCeqParalelo(){
		int numeroCapacitores;
	float voltajeTotal;
	float capacitores[50];
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t\t \n");
	printf("\t\t\tCalcular Ceq en paralelo\t\t\n");

	printf("\t\t\t\t\t\t \n");
	printf("\t Cuanto voltaje fluye en este circuito(Volts)?\t");
	scanf("%f",&voltajeTotal);
	printf("\n");

	printf("\t Cuantos capacitores se utilizaran?\t");
	scanf("%d",&numeroCapacitores);	
	
		
	printf("\t Unidad de medida (farads F)\t\n");

	printf("\n");
	
	int cont;
	float suma=0;
	for(cont=1;cont<=numeroCapacitores;cont++) {
		printf("\t Introduce el valor de la capacitancia C%d\t", cont);
		scanf("%f",&capacitores[cont]);
		suma+=capacitores[cont];	
	}
	
		printf("\t La Ceq es: %.12f F\t\n",suma);
		
		
		float cargaTotal;

	cargaTotal = suma*voltajeTotal;
	
	printf("\t La carga total es: %.15f C\t\n",cargaTotal);
			
			
	float energiaTotal;
				energiaTotal = cargaTotal * voltajeTotal * 0.5;


		printf("\t Energia almacenada total (energia potencial)es: %.14f J\t",energiaTotal);		
			
			
			for(cont=1;cont<=numeroCapacitores;cont++) {
		printf("\t El V%d = %.5f V\t\n", cont, voltajeTotal);
	}	



	for(cont=1;cont<=numeroCapacitores;cont++) {
			
			float carga= voltajeTotal * capacitores[cont];
			
			printf("\t El q%d = %.14f C\t\n", cont, carga);
	}
		
		
			for(cont=1;cont<=numeroCapacitores;cont++) {
			
		
		//	float energia= (cargaTotal*cargaTotal) / (2*capacitores[cont]);
		
		float energia= ((voltajeTotal*voltajeTotal) * capacitores[cont]) / 2;
			
			printf("\t La U%d = %.14f J\t\n", cont, energia);
	}	

		
}
	
void calcularCeqSerie(){
int numeroCapacitores;
	float voltajeTotal;
	
	float capacitores[50];
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t\t \n");
	printf("\t\t\tCalcular Ceq en Serie\t\t \n");
	printf("\t\t\t\t\t\t \n");
//		printf("\t\t\tUnidad de medida (ohms)\t\t \n\n");
		
	printf("\t Cuanto voltaje fluye en este circuito(Volts)?\t");
	scanf("%f",&voltajeTotal);	
		printf("\n");
		

	printf("\t Cuantos capacitores se utilizaran?\t");
	scanf("%d",&numeroCapacitores);	
	
	
	printf("\t Unidad de medida (farads F)\t\n");

	printf("\n");
	
	int cont;
	float suma=0;
	for(cont=1;cont<=numeroCapacitores;cont++) {
		printf("\t Introduce el valor de la capacitancia C%d\t", cont);
		scanf("%f",&capacitores[cont]);
		suma+=(1/capacitores[cont]);			
	}	
	
	printf("\t La Ceq es: %.14f F\t\n", pow (suma, -1)); 

	float cargaTotal;
	

		cargaTotal= voltajeTotal * pow (suma, -1);
		
		printf("\t La carga total es: %.14f C\t\n",cargaTotal);
		
		
			float energiaTotal;
				energiaTotal = cargaTotal * voltajeTotal * 0.5;


		printf("\t Energia almacenada total (energia potencial)es: %.14f J\t",energiaTotal);


		for(cont=1;cont<=numeroCapacitores;cont++) {
	printf("\t La q%d = %.14f C\t\n", cont, cargaTotal);
	}


	for(cont=1;cont<=numeroCapacitores;cont++) {
			
			float voltaje= cargaTotal / capacitores[cont];
			
			printf("\t El V%d = %.14f V\t\n", cont, voltaje);
	}


				for(cont=1;cont<=numeroCapacitores;cont++) {
			
			float energia= (cargaTotal*cargaTotal) / (2*capacitores[cont]);
			
			printf("\t La U%d = %.14f J\t\n", cont, energia);
	}	

}


void calcularReqParalelo(){
	
	int numeroResistencias;
	float voltajeTotal;
	
	float resistencias[50];
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t\t \n");
	printf("\t\t\tCalcular Req en Paralelo\t\t \n");
	printf("\t\t\t\t\t\t \n");
//		printf("\t\t\tUnidad de medida (ohms)\t\t \n\n");
		
	printf("\t Cuanto voltaje fluye en este circuito(Volts)?\t");
	scanf("%f",&voltajeTotal);	
		printf("\n");
		

	printf("\t Cuantas resistencias se utilizaran?\t");
	scanf("%d",&numeroResistencias);	
	
	
	printf("\t Unidad de medida (ohms)\t\n");

	printf("\n");
	
	int cont;
	float suma=0;
	for(cont=1;cont<=numeroResistencias;cont++) {
		printf("\t Introduce el valor de la resistencia R%d\t", cont);
		scanf("%f",&resistencias[cont]);
		suma+=(1/resistencias[cont]);			
	}
	
		float intensidadTotal;
		float potenciaTotal;

	
	intensidadTotal= voltajeTotal / pow (suma, -1);
	potenciaTotal= voltajeTotal*intensidadTotal;


	printf("\t La Req es: %.2f ohms\t\n", pow (suma, -1)); 

	printf("\t La intensidad total es: %.2f A\t\n",intensidadTotal);
	printf("\t La potencia total disipada es: %.2f W\t\n",potenciaTotal);
	
	
	for(cont=1;cont<=numeroResistencias;cont++) {
		printf("\t El V%d = %.2f V\t\n", cont, voltajeTotal);
	}


		for(cont=1;cont<=numeroResistencias;cont++) {
			
			float intensidad= voltajeTotal / resistencias[cont];
			
			printf("\t El I%d = %.2f A\t\n", cont, intensidad);
	}
	
			for(cont=1;cont<=numeroResistencias;cont++) {
			
			float potencia= (voltajeTotal*voltajeTotal) / resistencias[cont];
			
			printf("\t El P%d = %.2f W\t\n", cont, potencia);
	}

}


