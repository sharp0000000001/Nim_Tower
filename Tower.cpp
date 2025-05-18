// Tower_Of_Hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Copyright <2021> <JAMES C. WILLIAMS>

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files(the “Software”), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
// following conditions :

// The above copyright notice and this permission notice shall be included in all copies or substantial
// portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
// LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <Windows.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	system("Color 2B");
    std::cout << "*****************************************************************************************************\n";
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>THE TOWER OF HANOI<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	std::cout << "*****************************************************************************************************\n";
	char name[20],D;
	int tally = 0,dud=0;
	std::cout << "\n\nWhat is your name (end with $)?";
	for (int i=0; i < 20; i++)
	{
	std::cin >> D;
		name[i] = D;
			if (D == '$') { tally = i; i = 20; }
	}
	std::cout << "Hello, ";
	for (int i=0; i < tally; i++)
	{
		std::cout << name[i];
	}
	//Text output for rules

	system("Color 6E");
	std::cout << "\n\nWelcome to the Tower of Hanoi, else called the NiM Tower(R)(C)\n";
	std::cout << "\n";
	std::cout << "The rules are simple:\n";
	std::cout << "Move only smaller pieces on top of larger thus moving the whole tower of Hanoi.\n";
	std::cout << "\nEnter a number to continue: ";
	std::cin >> dud;

	//display setup
	int matrix[8][3],a,b,c,d,e,f,flag1,flag2;
	char data[20];
	system("Color 1A");
	for (int j = 0; j < 3; j++)
	{


		for (int i = 0; i < 8; i++)
		{
			matrix[i][j] = 0;
			if (j == 0)
			{
				matrix[i][j] = i+1;
			}
		}
	}
clears:
	for (int i = 0; i < 40; i++)
	{
		std::cout << "\n";
	}
	std::wcout << "         1                   2                   3\n";
	std::wcout << "         |                   |                   |\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 0)
			{
				for (int k = 0; k < 20; k++)
				{
					data[k] = ' ';
				}
			}
			a = 0;
			b = 10 - matrix[i][j];
			c = 10 + matrix[i][j];
			for (int k=a; k < b; k++)
			{
				data[k] = ' ';
			}
			for (int k = b; k < c; k++)
			{
				data[k] = '#';
			}
			for (int k = c; k < 20; k++)
			{
				data[k] = ' ';
			}
			for (int k = 0; k <20; k++)
			{
				std::cout << data[k];
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	moves:
	std::cout << "Move from: ";
	std::cin >> a;
	std::cout << "   Move to: ";
	std::cin >> b;
	if ((a < 4) && (a > 0) && (b < 4) && (b > 0))
	{
		a = a - 1;
		b = b - 1;
		c = 7;
		e = 0;
		d = 7;
		f = 0;
		flag1 = 0;
		flag2 = 0;
		for (int i = 0; i < 8; i++)
		{
			if ((i == 7) && (matrix[i][a] == 0))
			{
				flag1 = 1;
				c = i;
				e = matrix[i][a];
			}

			if (matrix[i][a] != 0)
			{
				c = i;
				e = matrix[i][a];
				i = 8;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if ((i == 7) && (matrix[i][b] == 0))
			{
				flag2 = 1;
				d = i;
				f = matrix[i][b];
			}
			if (matrix[i][b] != 0)
			{
				d = i;
				f = matrix[i][b];
				i = 8;
			}
		}
		if (((e > f) && (flag2 == 0)) || flag1 == 1)
		{
			std::cout << "\aIllegal move\n";
			goto moves;
		}
		matrix[c][a] = 0;
		if ((flag2 == 0) && (d > 0))
		{
			matrix[d - 1][b] = e;
		}
		if ((flag2 == 1))
		{
			matrix[7][b] = e;
		}
		goto clears;
	}
	else
	return 0;
}




