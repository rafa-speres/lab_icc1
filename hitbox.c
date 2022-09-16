//[2 - Condicional] Hitbox
//Rafael Scalon Peres Conti
#include <stdio.h>

int main(void) {
  long long int x1, y1, l1, a1, x2, y2, l2, a2;
  scanf("%lld ", &x1);
  scanf("%lld ", &y1);
  scanf("%lld ", &l1);
  scanf("%lld ", &a1);
  scanf("%lld ", &x2);
  scanf("%lld ", &y2);
  scanf("%lld ", &l2);
  scanf("%lld", &a2);

  long long int hor1 = x1+l1;
  long long int hor2 = x2+l2;
  long long int ver1 = y1+a1;
  long long int ver2 = y2+a2;

  //identificando se haÂ¡ HIT ou MISS
  if(((x1 <= x2 && x2 <= hor1) || (x2 <= x1 && x1 <= hor2)) && ((y1 <= y2 && y2 <= ver1) || (y2 <= y1 && y1 <= ver2))){
    
    //para x da interseccao
    long long int xInt;
    if(x1 >= x2){
        xInt = x1;
    } else{
        xInt = x2;
    }

    //para y da interseccao
    long long int yInt;
    if(y1 >= y2){
        yInt = y1;
    } else{
        yInt = y2;
    }

    //para largura da interseccao
    long long int lInt;
    if(hor1 >= hor2){
        lInt = hor2 - xInt;
    } else{
        lInt = hor1 - xInt;
    }

    //para altura da interseccao
    long long int aInt;
    if(ver1 >= ver2){
        aInt = ver2 - yInt;
    } else{
        aInt = ver1 - yInt;
    }

    printf("HIT: %lld %lld %lld %lld\n", xInt, yInt, lInt, aInt);

  } else{
    printf("MISS");
  }
  
  return 0;
}
