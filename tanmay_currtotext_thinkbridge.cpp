/*It is a simple code to convert the given numeric currency to textual format. It include the basic input output header file i.e. iostream library
Another library i.e. bits/stdc++.h is included as I have used fmod function in our program so as to obtain the remainder of the required double.
My code will acurately determine the text of respective currency upto 100 crores i.e. 10^9 and a decimal precision of 2 digits.
*/
#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
void convertintupto99(double a)
{
	char *unit[]={"zero", "one", "two", "three", "four","five", "six", "seven", "eight", "nine"};//an array of pointers to charecters numbered from 0-9
	char *ten1[]={"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};//an array of pointers to charecters numbered from 10-19
	char *ten2[]={"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};//an array of pointers to charecters that are multiple of 10 till 100
	if(a<0)//base case: if a valid input is not entered
	{
		cout<<"enter a valid input";
	}
	if(a>0 && a<10)//case2: if input entered is a single digit
	{
		cout<<unit[int(a)]<<" ";
	}
	if(a>9 && a<20)//case3: if input is between 10-20
	{
		cout<<ten1[int(a-10)]<<" ";
	}	
	if(a>=20 && a<100)//if input is between 20-100
	{
		int m1=a/10;
		int m2=int(a)%10;
		if(m2==0)
		{
			cout<<ten2[m1-2]<<" ";//fetching data from ten2 pointer array
		}
		else
		{
			cout<<ten2[m1-2]<<" ";//fetching data from ten2 pointer array
			cout<<unit[m2]<<" ";//fetching data from unit pointer array
		}
	}
}

void convertdouble(double a)//function to convert the decimal part of the fractional part
{
	double x = a; 
	double y = fmod(x, 1);// fmod gives the remainder when dividing the double by 1
	if(y!=0)
		cout<<y*100<<"/100";
}
void convertintupto999(double a)//function to convert the 3 digit numbers to the currency
{
	int k=a/100;
	char *unit[]={"one", "two", "three", "four","five", "six", "seven", "eight", "nine"};
	cout<<unit[k-1]<<" hundred ";
		if(a/100!=0)
		{
			convertintupto99(int(a)%100);// calling the convertintupto99 function 
		}
}
void convertintupto99999(double a)//function to convert the 4 and 5 digit numbers to the currency
{
	int k=a/1000;
	int m=int(a)%1000;
	convertintupto99(k);// calling the convertintupto99 function 
	cout<<" thousand ";
	if(m<100)
	{
		convertintupto99(m);// calling the convertintupto99 function 
	}
	if(m>99)
	{
	convertintupto999(m);	// calling the convertintupto999 function 
	}
}
void convertintupto9999999(double a)//function to convert the 6 and 7 digit numbers to the currency
{
	int k=a/100000;
	int m=int(a)%100000;
	convertintupto99(k);// calling the convertintupto99 function 
	cout<<" lakh ";
	if(m<99)
	{
		convertintupto99(m);// calling the convertintupto99 function 
	}
	if(m<=999 && m> 99)
	{
		convertintupto999(m);// calling the convertintupto999 function 
	}
	if(m>999)
	{
	convertintupto99999(m);// calling the convertintupto99999 function 
	}
}
void convertintupto999999999(double a)//function to convert the 8 and 9 digit numbers to the currency
{
	int k=a/10000000;
	int m=int(a)%10000000;
	convertintupto99(k);// calling the convertintupto99 function 
	cout<<" crore ";
	if(m<100)
	{
		convertintupto99(m);// calling the convertintupto99 function 
	}
	if(m<1000 && m>99)
	{
		convertintupto999(m);// calling the convertintupto999 function 
	}
	if(m>999 && m<100000)
	{
		convertintupto99999(m);// calling the convertintupto99999 function 
	}
	else
	{
		convertintupto9999999(m);// calling the convertintupto9999999 function 
	}
}
int main()
{
	double a;
	cout<<"Enter a currency value";
	cin>>a;
	//checking for the values of a and then calling the function correspondingly
	cout<<"YOUR Text currency is : Rs ";
	if(a<100)
	{
	convertintupto99(a);
	}
	if(a>99 && a<1000)
	{
		convertintupto999(a);
	}
	if(a>=1000 && a<100000)
	{
		convertintupto99999(a);
	}
	if(a>=100000 && a<10000000)
	{
		convertintupto9999999(a);
	}
	if(a>=10000000 && a<1000000000)
	{
		convertintupto999999999(a);
	}
	//calling the convertdouble() function to convert decimal part to fraction. It returns only if a decimal part is present. Else it doesn't return anything 
	convertdouble(a);
}
