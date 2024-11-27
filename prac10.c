/*
Nombre: Brayan López Mercado
Matrícula: 1280838
Fecha De Entrega: 26 De Noviembre De 2024
Materia: Algoritmos y Estructura De Datos
Grupo: 552
Practica 10: Algoritmos De Ordenamiento
*/
#include <stdio.h>
#include <stdlib.h>

struct Infraccion{
    char placa[16];
    char marca[16];
    char modelo[16];
    char marcaModelo[32];
    int anio;
    int multa;
    char motivoMulta[256];
    char fechaMulta[16];
};

struct Pila{
    int* array;
    int idxPila;
    int size;
};

struct Heap{
    struct Infraccion* array;
    int size;
    int capacidad;
};

struct Pila* crearPila(int size);
struct Heap* crearHeap(int capacidad,struct Infraccion* infracciones);
struct Infraccion extraerMayor(struct Heap* heap);
int vacia(struct Pila* pila);
int llena(struct Pila* pila);
int pop(struct Pila* pila);
int particion(struct Infraccion* array, int posInicio, int posFinal);
int mystrCmp(char* str1, char* str2);
void push(struct Pila* pila,int num);
void quicksort(struct Infraccion* array, int posInicio, int posFinal);
void maxHeap(struct Heap* heap, int idx);
void heapsort(struct Infraccion* array, int size);
void printArray(struct Infraccion* array, int size);
void printMenu();
void limpiarBuffer();
void imprimirMulta(struct Infraccion infra);
void eliminarInfraccion(struct Infraccion* infracciones,int numMultas,char* placaABorrar);

int main(){
    int opt=0;
    int numMultas=0;
    struct Infraccion* infracciones=(struct Infraccion*)malloc((numMultas+1)*sizeof(struct Infraccion));

    sprintf(infracciones[numMultas].placa,"%s","A59-NZC-6");
    sprintf(infracciones[numMultas].marca,"%s","Honda");
    sprintf(infracciones[numMultas].modelo,"%s","Civic");
    infracciones[numMultas].anio=2020;
    infracciones[numMultas].multa=500;
    sprintf(infracciones[numMultas].motivoMulta,"%s","Exceso de velocidad");
    sprintf(infracciones[numMultas].fechaMulta,"%s","08/03/2023");
    sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
    numMultas++;
    infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));

    sprintf(infracciones[numMultas].placa,"%s","EJM-47-40");
    sprintf(infracciones[numMultas].marca,"%s","Nissan");
    sprintf(infracciones[numMultas].modelo,"%s","Pathfinder");
    infracciones[numMultas].anio=2018;
    infracciones[numMultas].multa=600;
    sprintf(infracciones[numMultas].motivoMulta,"%s","Conducir en estado de ebriedad");
    sprintf(infracciones[numMultas].fechaMulta,"%s","07/03/2019");
    sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
    numMultas++;
    infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));

    sprintf(infracciones[numMultas].placa,"%s","3-MM-778");
    sprintf(infracciones[numMultas].marca,"%s","Suzuki");
    sprintf(infracciones[numMultas].modelo,"%s","Scross");
    infracciones[numMultas].anio=2021;
    infracciones[numMultas].multa=400;
    sprintf(infracciones[numMultas].motivoMulta,"%s","Voltear en U");
    sprintf(infracciones[numMultas].fechaMulta,"%s","02/09/2024");
    sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
    numMultas++;
    infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));

    sprintf(infracciones[numMultas].placa,"%s","257-NWD-8");
    sprintf(infracciones[numMultas].marca,"%s","Honda");
    sprintf(infracciones[numMultas].modelo,"%s","Accord");
    infracciones[numMultas].anio=2022;
    infracciones[numMultas].multa=700;
    sprintf(infracciones[numMultas].motivoMulta,"%s","Conducir con dispositivo");
    sprintf(infracciones[numMultas].fechaMulta,"%s","02/01/2024");
    sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
    numMultas++;
    infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));

    sprintf(infracciones[numMultas].placa,"%s","AHA-50-15");
    sprintf(infracciones[numMultas].marca,"%s","Mazda");
    sprintf(infracciones[numMultas].modelo,"%s","Sedan");
    infracciones[numMultas].anio=2019;
    infracciones[numMultas].multa=300;
    sprintf(infracciones[numMultas].motivoMulta,"%s","Verificacion expirada");
    sprintf(infracciones[numMultas].fechaMulta,"%s","03/07/2020");
    sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
    numMultas++;
    infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));

    sprintf(infracciones[numMultas].placa,"%s","YBU-80-66");
    sprintf(infracciones[numMultas].marca,"%s","Suzuki");
    sprintf(infracciones[numMultas].modelo,"%s","Ignis");
    infracciones[numMultas].anio=2021;
    infracciones[numMultas].multa=450;
    sprintf(infracciones[numMultas].motivoMulta,"%s","Estacionarse en Doble Fila");
    sprintf(infracciones[numMultas].fechaMulta,"%s","05/05/2021");
    sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
    numMultas++;
    infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));

    sprintf(infracciones[numMultas].placa,"%s","EMN-71-71");
    sprintf(infracciones[numMultas].marca,"%s","Nissan");
    sprintf(infracciones[numMultas].modelo,"%s","Versa");
    infracciones[numMultas].anio=2020;
    infracciones[numMultas].multa=300;
    sprintf(infracciones[numMultas].motivoMulta,"%s","Conducir sin licencia");
    sprintf(infracciones[numMultas].fechaMulta,"%s","24/12/2018");
    sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
    numMultas++;
    infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));

    do{
        printMenu();
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("Número De Placa: ");
                scanf("%s",infracciones[numMultas].placa);
                printf("Marca Del Vehículo: ");
                scanf("%s",infracciones[numMultas].marca);
                printf("Modelo Del Vehículo: ");
                scanf("%s",infracciones[numMultas].modelo);
                printf("Año Del Vehículo: ");
                scanf("%d",&infracciones[numMultas].anio);
                printf("Multa: ");
                scanf("%d",&infracciones[numMultas].multa);
                printf("Motivo De Multa: ");
                limpiarBuffer();
                fgets(infracciones[numMultas].motivoMulta,256,stdin);
                printf("Fecha De La Multa: ");
                scanf("%s",infracciones[numMultas].fechaMulta);
                sprintf(infracciones[numMultas].marcaModelo,"%s %s",infracciones[numMultas].marca,infracciones[numMultas].modelo);
                numMultas++;
                infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));
                break;
            case 2:
                char placaABorrar[16];
                printf("Placa Del Vehiculo: ");
                scanf("%s",placaABorrar);
                eliminarInfraccion(infracciones,numMultas,placaABorrar);
                numMultas--;
                infracciones=realloc(infracciones,(numMultas+1)*sizeof(struct Infraccion));
                break;
            case 3:
                printf("\n****************************************************Infracciones Ordenadas Por Placa****************************************************\n");
                quicksort(infracciones,0,numMultas-1);
                break;
            case 4:
                printf("\n***********************************************Infracciones Ordenadas Por Marca y Modelo************************************************\n");
                heapsort(infracciones,numMultas);
                break;
        }
    }while(opt!=5);
    return 0;
}

void eliminarInfraccion(struct Infraccion* infracciones,int numMultas,char* placaABorrar){
    int encontrada=-1;
    for(int idx=0;idx<numMultas;++idx){
        if(mystrCmp(infracciones[idx].placa,placaABorrar)==0){
            encontrada=idx;
            break;
        }
    }
    if(encontrada!=-1){
        for(int jdx=encontrada;jdx<numMultas-1;++jdx)
            infracciones[jdx]=infracciones[jdx+1];
        printf("Infraccion Pagada\n");
    }
    else    
        printf("No se encontro la placa\n");
}

void quicksort(struct Infraccion* array, int posInicio, int posFinal){
    struct Pila* pila=crearPila(posFinal-posInicio+1);
    int size=posFinal+1;
    int pivote;
    printArray(array,size);
    push(pila,posInicio);
    push(pila,posFinal);
    while(!vacia(pila)){
        posFinal=pop(pila);
        posInicio=pop(pila);
        pivote=particion(array,posInicio,posFinal);
        if(pivote-1>posInicio){
            push(pila,posInicio);
            push(pila,pivote-1);
        }
        if(pivote+1<posFinal){
            push(pila,pivote+1);
            push(pila,posFinal);
        }
        printf("********************************************************************");
        printf("********************************************************************");
        printArray(array,size);
    }
    printf("********************************************************************");
    printf("********************************************************************");
    printf("\n");
    free(pila);
}

int particion(struct Infraccion* array, int posInicio, int posFinal){
    struct Infraccion aux;
    char* pivote=array[posFinal].placa;
    int indiceMenor=posInicio-1;
    for(int indiceActual=posInicio;indiceActual<=posFinal-1;indiceActual++){
        if(mystrCmp(array[indiceActual].placa,pivote)<0){
            indiceMenor++;
            aux=array[indiceMenor];
            array[indiceMenor]=array[indiceActual];
            array[indiceActual]=aux;
        }
    }
    aux=array[indiceMenor+1];
    array[indiceMenor+1]=array[posFinal];
    array[posFinal]=aux;
    return (indiceMenor+1);
}

void heapsort(struct Infraccion* array, int size){
    struct Infraccion aux;
    struct Heap* heap=crearHeap(size,array);
    printf("********************************************************************");
    while (heap->size){
        array[heap->size-1]=extraerMayor(heap);
        printf("********************************************************************");
        printArray(array,size);
        printf("********************************************************************");
    }
    printf("********************************************************************");
    printf("\n");
}

struct Heap* crearHeap(int capacidad,struct Infraccion* infracciones){
    int idx;
    struct Heap* nuevoHeap=(struct Heap*)malloc(sizeof(struct Heap));
    nuevoHeap->size=0;
    nuevoHeap->capacidad=capacidad;
    nuevoHeap->array=(struct Infraccion*)malloc(capacidad*sizeof(struct Infraccion));
    for(idx=0;idx<capacidad;idx++)
        nuevoHeap->array[idx]=infracciones[idx];
    nuevoHeap->size=idx;
    idx=(nuevoHeap->size-2)/2;
    while(idx>-1){
        maxHeap(nuevoHeap,idx);
        idx--;
    }
    return nuevoHeap;
}

void maxHeap(struct Heap* heap, int idx){
    int izquierdo=idx*2+1;
    int derecho=idx*2+2;
    int max=idx;
    struct Infraccion aux;
    if(izquierdo<heap->size && mystrCmp(heap->array[izquierdo].marcaModelo,heap->array[max].marcaModelo)<0)
        max=izquierdo;
    if(derecho<heap->size && mystrCmp(heap->array[derecho].marcaModelo,heap->array[max].marcaModelo)<0)
        max=derecho;
    if(max!=idx){
        aux=heap->array[max];
        heap->array[max]=heap->array[idx];
        heap->array[idx]=aux;
        maxHeap(heap,max);
    }
}

struct Infraccion extraerMayor(struct Heap* heap){
    struct Infraccion raiz=heap->array[0];
    heap->array[0]=heap->array[heap->size-1];
    heap->size--;
    maxHeap(heap,0);
    return raiz;
}

struct Pila* crearPila(int size){
    struct Pila* nuevaPila=(struct Pila*)malloc(sizeof(struct Pila));
    nuevaPila->array=(int*)malloc(size*sizeof(int));
    nuevaPila->idxPila=-1;
    nuevaPila->size=size;
    return nuevaPila;
}

int vacia(struct Pila* pila){
    return pila->idxPila==-1;
}

int llena(struct Pila* pila){
    return (pila->idxPila-1)==pila->size;
}

void push(struct Pila* pila, int num){
    if(llena(pila))
        return;
    pila->idxPila++;
    pila->array[pila->idxPila]=num;
}

int pop(struct Pila* pila){
    if(vacia(pila))
        return -1;
    else
        return pila->array[pila->idxPila--];
}

int mystrCmp(char* str1, char* str2){
    int cnt=0;
    char c1,c2;
    do{
        c1=*str1++;
        c2=*str2++;
        if(!c1)
            return c1-c2;
    }while(c1 == c2);
    return c1-c2;
}

void printArray(struct Infraccion* array, int size){
    for(int idx=0;idx<size;idx++)
        imprimirMulta(array[idx]);
    printf("\n");
}

void printMenu(){
    printf("1) Agregar Infracción\n");
    printf("2) Saldar Multa\n");
    printf("3) Mostrar Infracciones Ordenadas Por Numero De Placa\n");
    printf("4) Mostrar Infracciones Por Marca Modelo\n");
    printf("5) Salir\n");
    printf("Elige Una Opción: ");
}

void imprimirMulta(struct Infraccion infra){
    printf("\nPlaca: %s ; Marca: %s ; Modelo: %s ; Año: %d ; Multa: %d ; Motivo: %s ; Fecha: %s\n", infra.placa, infra.marca, infra.modelo, infra.anio, infra.multa, infra.motivoMulta, infra.fechaMulta);
}

void limpiarBuffer(){ 
    int c; 
    while ((c = getchar()) !='\n'); 
}