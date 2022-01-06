#define SIZE 4

int main() {
     int *ptr = calloc(SIZE, sizeof(int));
     func1(ptr);
     func2(ptr);
     free(ptr);
 }
void func1(int* q) {		
     int *p, i = 1;			      
     for (p = q; (p - q) < SIZE; p++)		      
	*p = (i++) * 5;			
}					

void func2(int *q) {
   int *p = q + SIZE;
   while (q < p) {
	*q = p - q; 
	q++;  
   }
}