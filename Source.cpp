#include<iostream>
using namespace std;
 
short a, b, c,d,e,f,X,Y,A,B,C,D;

int main()
{
	cout << "This program solves the system" << endl;
	cout << "aX + bY =c" << endl;
	cout << "dX + eY =f" << endl;
	cout << "Enter the values of a,b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d,e, and f: ";
	cin >> d >> e >> f;

	_asm //Solve for X
	{
		//Numerator
		mov ax, c;			//ax=c(1)
		imul e;				//ax=c(1)*e(-2), ax=1*(-2)
		mov bx, ax;			//bx=ax(1*(-2))
		mov ax, b;			//ax =b(1)
		imul f;				//ax=b(1)*f(5), ax=1*5
		sub bx, ax;			//bx=bx-ax, bx= (1*(-2))-(1*5)
		mov A, bx;			//A=-7

		//Denominator
		mov ax, a;			//ax=a(3)
		imul e;				//ax=c(3)*e(-2), ax=3*(-2)
		mov bx, ax;			//bx=ax(3*(-2)), ax is now free
		mov ax, b;			//ax =b(1)
		imul d;				//ax=b(1)*d(1), ax=1*1
		sub bx, ax;			//bx=bx-ax, bx= (3*(-2))-(1*1)
		mov B, bx;			//B=-7

		//Solve for X
		mov ax, A;			//ax=A, (1*(-2))-(1*5)
		cwd;				//16bit to 32bit
		idiv B;			//ax=ax/B, ((1*(-2))-(1*5))/((3*(-2))-(1*1))
		mov X, ax;
	}
	cout << "X = " << X << endl;
	_asm //Solve for Y
	{
		//Numerator
		mov ax, a;			//ax=a(3)
		imul f;				//ax=c(3)*e(5), ax=3*(5)
		mov bx, ax;			//bx=ax(3*5), ax is now free
		mov ax, c;			//ax =c(1)
		imul d;				//ax=c(1)*d(1), ax=1*1
		sub bx, ax;			//bx=bx-ax, bx= (3*5)-(1*1)
		mov C, bx;			//A=14

		//Denominator
		mov ax, a;			//ax=a(3)
		imul e;				//ax=c(3)*e(-2), ax=3*(-2)
		mov bx, ax;			//bx=ax(3*(-2)), ax is now free
		mov ax, b;			//ax =b(1)
		imul d;				//ax=b(1)*d(1), ax=1*1
		sub bx, ax;			//bx=bx-ax, bx= (3*(-2))-(1*1)
		mov D, bx;			//B=-7

		//Solve for Y
		mov ax, C;			//ax=A, (1*(-2))-(1*5)
		cwd;				//16bit to 32bit
		idiv D;				//ax=ax/B, ((1*(-2))-(1*5))/((3*(-2))-(1*1))
		mov Y, ax;
	}
	cout << "Y = " << Y << endl;
	system("pause");
}
/*------------Output-------------------
Programer: Tauney Mack
This program solves the system
aX + bY =c
dX + eY =f
Enter the values of a,b, and c: 3 1 1
Enter the values of d,e, and f: 1 -2 5
X = 1
Y = -2
Press any key to continue . . .
--------------------------------------*/