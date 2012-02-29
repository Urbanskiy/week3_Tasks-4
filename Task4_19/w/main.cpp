#include <conio.h>
#include <stdio.h>
class Vector{

  double *coord;

public:
int size;
Vector();
  Vector(int n);
  Vector (Vector &a);

};
Vector:: Vector(){
 size=0;
 coord=new double[size];
// printf("Without ");
// printf("%p %s",this," * ");
}
Vector:: Vector(int n){
 if (n>=0){
  size=n;
  coord=new double[size];
  for(int i=0;i<size;++i){
   coord[i]=1;

  }
 } else printf("%s","Size must be greater than 0");
}
Vector::Vector(Vector &a ){
    printf("awdawd");
 this->size=a.size;
 this->coord=new double[a.size];
 for(int i=0;i<size;++i){
  this->coord[i]=a.coord[i];
 }

}


int main()
{


 Vector * a = new Vector();
 Vector * b = new Vector(1);
 *b = *a;

    printf("%d",(b->size));
 getch();

}
