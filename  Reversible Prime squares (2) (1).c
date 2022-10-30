
#include <stdio.h>
#include <stdbool.h>
#include<math.h>

//Function Declarations
int reverse(int x);          //returns the reverse of a number e.g 123 becomes 321
bool primechecker(int x);    //checks whether a number is prime or nit i.e it has 1 and itself as its factors
bool isPerfect(long int x);  //checks if a number is perfect i.e if the number is equal to the sum of its positive integers
bool not_palindrome(int x);  //checks whether the reverse of the number is not equal to the number itself

//Function main
int main()
{
	int a,b,c,d;
	int y = 0;
	
	for(a=0;a>=0;a++)
	{
		b = reverse(a);
		
		if(isPerfect(a) == true && isPerfect(b) == true){
			
			c = sqrt(a);
			d = sqrt(b);
			
			if(primechecker(c) == 1 && primechecker(d)){
				
				if(not_palindrome(a)){
					printf("%d \n",a);
					y++;
					if(y==10){
						break;
					}
				}
			}
		}
	}
	return 0;
}

//FUNCTIONS


int reverse(int x)
{
	int rem;
	int reverse=0;
	
	while(x!=0)
	{
		rem = x%10;
		reverse = (reverse*10)+rem;
		x/=10;
	}
	return reverse;
	
}

bool primechecker(int x)
{
		int i;
	bool isPrime=true;
	
	if(x==0 && x==1 )
	{
		isPrime=false;
	}
	
	for(i=2;i<=(x)/2;i++)
	{
		if(x%i == 0)
		{
			isPrime=false;
			break;
		}
		
	}
	return isPrime;
}

bool isPerfect(long int x)
{
	long int sum = 1;
	long int i;
	
	for(i=2; i*i<=x; i++)
	{
		if (x%i==0)
		{
			if(i*i!=x){
				sum = sum + i + x/i;
			}
			else{
				sum+=i;
			}
		}
	}
	
	if(sum == x && x != 1){
		return true;
	}
	return false;
}

bool not_palindrome(int x)
{
	bool isPalindrome = true;
	if(reverse(x) == x){
		isPalindrome = false;
	}
	return isPalindrome;
}
