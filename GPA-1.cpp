/*

Graded Programming Assignment 1
A rational number is represented as numerator/denominator.  We need to identify whether two rational numbers are equal or not. For example, consider two rational numbers '1/4' and '4/16'. Both of them are equal, as, '4/16' if reduced to lowest terms is '1/4'.

Consider the following structure 'rational' that has member variables 'numerator' and 'denominator'.

struct rational { 
   int numerator; 
   int denominator; 
} ;

The main function is coded as shown below:

int main() { 
   int result; 
   struct rational num1, num2; 
   cout << "Enter Details of Number 1 " << endl; 
   cout << "Enter Numerator :" << endl; 
   cin >> num1.numerator; 
   cout << "Enter Denominator :" << endl; 
   cin >> num1.denominator; 
   cout << "Enter Details of Number 2 " << endl; 
   cout << "Enter Numerator :" << endl; 
   cin >> num2.numerator; 
   cout << "Enter Denominator :" << endl; 
   cin >> num2.denominator; 
   result = isEqual(num1, num2);     //to check rational 'num1' is equal to rational 'num2' 
   if(result == true) 
      cout << "Both rational numbers are equal" << endl; 
   else 
      cout << "Both rational numbers are not equal" << endl;    
   return 0; 
}

You are required to write 2 functions:
To find out whether the two rational numbers are equal or not, we need to write two functions 'reduce' and 'equal', as described below:

Function 1: reduce
This function has two parameters:

struct rational *inputrational: *inputrational is a pointer to the structure rational, which is the actual rational number to be reduced
struct rational *outputrational: *outputrational is a pointer to the structure rational, which will store the rational number in its lowest form
Function 2: isEqual
This function has two parameters:

struct rational num1: 
struct rational num2: 
The function should do the following

This function should call the function 'reduce' twice.
Thereafter, the function should check whether both the rational numbers obtained in the lowest form are equal or not. If yes, then it should return boolean value 'true', else, it should a boolean value 'false'.
In the 'main' program, the function 'isEqual' is called using two arguments, num1 and num2 which are  passed by reference, both of type 'struct rational'

*/

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
