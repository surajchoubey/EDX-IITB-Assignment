#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

struct rational { 
   int numerator; 
   int denominator; 

} ;

  
   void reduce(rational *inputrational , rational *outputrational){
   		int GCD = gcd(inputrational->numerator, inputrational->denominator);
   		
   		inputrational->numerator = ( inputrational->numerator ) / GCD;
  		inputrational->denominator = ( inputrational->denominator ) / GCD;
   		
   		GCD = gcd(outputrational->numerator, outputrational->denominator);
   		
   		outputrational->numerator = ( outputrational->numerator ) / GCD;
   		outputrational->denominator = ( outputrational->denominator ) / GCD;
   		
   }

   
   bool isEqual( rational *num1 , rational *num2 ){
   
   		reduce(num1,num2);
      	
   		if(num1->numerator == num2->numerator && num1->denominator == num2->denominator ) return true;
   		else return false;
   }




int main() { 
   bool result = false; 
   rational *num1 = new rational, *num2 = new rational;
   num1 = new rational; 
   cout << "Enter Details of Number 1 " << endl; 
   cin >> num1->numerator >> num1->denominator;

   num2 = new rational;
   cout << "Enter Details of Number 2 " << endl; 
   cin >> num2->numerator >> num2->denominator; 

   result = isEqual(num1, num2); 
   delete num1, num2;

   
   if(result == true) 
      cout << "Both rational numbers are equal" << endl; 
   else 
      cout << "Both rational numbers are not equal" << endl;    
   return 0; 
}
