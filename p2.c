#include <stdio.h>

_Bool match();    //funcion que regresa 0 si no coinciden las bebidas y llama a shift, de lo contrario regresa 1
void shift();     //funcion que hace un corrimiento en el arreglo de acuerdo a un indice

int index=0;      //indice para correr el arreglo y llevar un conteo de parejas

int main()
{
    int n, res, count=0;            //res es cuantas parejas quedan sin casarse
    _Bool aux = 0;
    
    printf("\nDame un numero n y las bebidas de las parejas: \n");
    scanf("%d",&n);
    char d_brides[n], d_grooms[n];
    res=n;                          //se inicializa res = n
    scanf("%s",d_brides);           //se escanean los arrays de bebidas
    scanf("%s",d_grooms);
    
    while(res > 0){         //si de acuerdo a las bebidas todos pueden encontrar pareja res llega a cero y es la respuesta
      while(aux == 0){      //si aux regresa 0 vuelve a entrar al ciclo
        aux = match(d_brides,d_grooms,n);         //si encuentra pareja sale del ciclo y actualiza valores
        count++;                                   //variable que no ayuda a saber si ya no hay novios que coincidan con la novia
        if(count == res && aux == 0) {            //si ya corrio el arreglo el numero de veces de objetos que hay en el
          printf("\nres: %d\n",res);              //termina pues ya no hay mas parejas a casar y regresa el valor de las 
          return 0;                               //parejas restantes.
        }
      }
      aux=0;                //se re-inicializan valores
      count=0;
      index++;              //se actualizan valores
      res--;
    }
    
    printf("\nres: %d\n",res);        //se imprime si todas las parejas se cazan
    
    return 0;
    
}

_Bool match(char d_brides[], char d_grooms[], int n) {

  if (d_brides[index] != d_grooms[index]){
    shift(d_grooms,index,n);
    return 0;
  }
  else {
    return 1;
  }
}

void shift (char array[], int x, int n){
  char tmp;
  int i;
  tmp = array[x];
  for (i=x;i<(n-1);i++){
    array[i] = array[i+1];
  }
  array[n-1] = tmp;
}

