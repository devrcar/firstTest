#include <stdio.h>
#include <time.h>

void unsort();     //Toma un array y lo desordena
void swap();       //Toma un array y segun los indices pasados intercambia los elementos 
void printarray();      //Imprime un array

int main() {

  int arr[] = {10,9,8,7,6,5,4,3,2,1};
  int n =sizeof(arr)/sizeof(arr[0]);      //calcula el tamaño del array
    
  unsort(arr,n);
    
  printarray(arr,n);

  return 0;
    
}

void unsort (char array[], int n){
  srand(time(NULL));            //planta una semilla para generar el numero aleatorio
  int t, i;
  
  for (i=0;i<(n-1);i++){
    t = rand()%2;               //genera un numero aleatorio entre 0 o 1 y de acuerdo a este
    if(t==1){                   //se decide si intecambiar elementos o no
      swap(array,i,n-1);
    }
  }
}

void swap (int arr[], int a, int b) {
  int tmp;
  tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void printarray(int array[], int n){
  for(int i=0; i<n-1; i++){
    printf(" %d",array[i]);
  }
  printf("\n");
}
