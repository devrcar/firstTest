#include <stdio.h>

int pot();

int main()
{
    int n, i, num=0;
    
    printf("\nDame un numero n: \n");
    scanf("%d",&n);
    
    for (i=0; i<n; i++) {
      num = num + (pot(10,i));
    }
    num= pot(num,2);
    printf("\n%d\n",num);
    return 0;
    
}

int pot(int b, int n) {
  int res=1;
  if(n==0) return res;
  else{
    for(int i=0; i<n; i++){
      res=res*b;
    }
  }
  return res;
}
