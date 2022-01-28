/* An algorithm of multiplication based on the ancient Egyptian method. It uses a recursive function to determine which doubles of a number to be summed up. 
The first number goes through a series of finding logarithms to the base two. Each time first number logarithm to the base two is calculated, the remainder goes through 
the same operation until it reaches the base case; log2(1). For example, if the function finds out that the second number is to be multiplied by its forth double, 
then the solution is: Second number * 2^4. The function will produce a result of 4 when the first number is 16. */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int log2Series(int number1, int number2);
bool is_integer(float k);
vector<int> exponents;


int main(){
	int num1, num2;
	cout<<"Please enter a number: ";
	cin>>num1;
	cout<<"Please enter another number: ";
	cin>>num2;
	cout<<"The product is: ";
	cout<<log2Series(min(num1, num2), max(num1 ,num2))<<endl; //Finding the logarithms of the smaller number to speed up operation.
}


// Recursive function to find the exponents of two to be multiplied by the second number and sum all terms

int log2Series(int number1, int number2){
		int product = 0;
	if (is_integer(log2(number1))){
		exponents.push_back(log2(number1));
		for (int exp = 0; exp < exponents.size(); exp++)
		product += (number2 * pow(2, exponents[exp])); //Summing all terms
		return product;
		}
		
	else{
		exponents.push_back(floor(log2(number1)));
		log2Series(number1 - pow(2, floor(log2(number1))), number2);
	}
}

// Function to check if a number is integer

bool is_integer(float k){
  return floor(k) == k;
}
