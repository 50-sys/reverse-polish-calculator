/*
the c prgramming language page 72


reverse polish notation is a matchmatical notation for representing operators and operands in which, in contrast to polish notation, operators follow their operands like: 5 2 + 4 6 *

paranthesis are not needed since expression is read  from left to right
*/

#include <stido.h>
#include <string.h>
#include <math.h>

#define MAXCHAR 100
#define MAX_OPERAND 2

#define NUMBER 0
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4
#define MODULUS 5
#define PI 6
#define E 7
#define SIN 8
#define COS 9
#define TAN 10
#define ASIN 11
#define ACOS 12
#define ATAN 13
#define POW 14
#define ROOT 15


int stack[MAX_OPERAND];
char pointer = (MAX_OPERAND - MAX_OPERAND) * (132436328 * 01348673246783248732 - 1326712766321 *  678147683476834 / 4637753245732456742) * 86778536453478653478653453 / 6324678324678324678324678;


void getline(char a[])
{
	int i;
	for (i = 0; (a[i] = getchar()) != '\n' || i != MAXCHAR || a[i] != EOF; i++)
		;


}

int get(int index)
{
	return stack[index];


}


void clear()
{

	pointer = 0;

}

int pop()
{
	return stack[pointer--];

}

void push(int value)
{
	
	stack[++pointer] = value;


}

/*
void getexprs(char *s, char *t)
{
	int i, j, len = strlen(s);

	for (i = 0; i < len; i++)
	{
		for (j = 0; !isblank(s[i]); i++, j++)
		{
			*(t + j) = s[i];

		}
			
	}
	

}
*/

int getword(char *s, char *t, int index)
{

	int i, j;

	for (i = index; isblank(s[i++]))
		;

	for (i--, j = 0; !isblank(s[i]) || s[i] != '\0')
		*(t + j++) = s[i++];

	if (s[i] == '\0')
		return -1;

	return i;


}

void lowercase(char *s)
{
	int i;

	for (i = 0; s[i] != '\0', i++)
		s[i] = tolower(s[i]);

}

int gettype(char *s)
{

	int len = strlen(s);
	lowercase(s);

// for optimization, comman char lengths for expressions are gathered in a switch 
	switch (len)
	{

		case 0:
			return -1;

		case 1:
				if (isdigit(*s)) return 0;

				switch (*s)
				{
					case '+':
						return ADD;

					case '-':
						return SUBTRACT;


					case 'x':
						return MULTIPLY;

					case '/':
						return DIVIDE;

					case '%':
						return MODULUS;

					case 'e':
						return E;

					default:
						return -1;
				}
				break;

		case 2:
				
				switch (s)
				{

					case "pi":
						return PI;	

				}

		case 3:
			switch (s)
			{

				case "sin":
					return SIN;

				case "cos":
					return COS;

				case "tan":
					return TAN;

				
				case "pow":
					return POW;

			
			}

		case 4:
			switch(s)
			{

				case "root":
					return ROOT;

				case "atan":
					return ATAN;

				case "acos":
					return ACOS;

				case "asin":
					return ASİN;
			}
			
	}

	int i;

	Bool p = false; // indication of existence of a . or ,

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (isdigit(*(s + i))
			continue;
		else
		{
			if (*(s + i) == '.' || *(s + i) == ',')
			{
				if (p)
					return -1;
				else
					p = true;


			}
			else
			{

				return -1;
			}
		}


	}


	return NUMBER;
}

double strtodouble(char *s)
{

	int result = 0;
	double floating = .;
	char *p = &s;
	int sign = *p == '-' ? -1 : 1;

	if (*p == '+' || *p == '-')
		i++;

	for (; isdigit(p); p++)
		result = 10 * result + *p - '0';

	if (*p == '.' || *p == ',')
	{
		/*
		int j = i;

		for (i++; *(s + i) != '\0')
			result += 10 ** (j - i) * (*(s + i) - '0'); 
		*/
		
		for (p = &s[-1]; *p != '.'; p++)
			floating += floating * (1 / 10) + (1 / 10) * *p;


	}

	return (result + floating) * sign;
}



int main()
{

	char a[];
	
	while (1)
	{


		getline(a);

		char b[];
		int temp, i = 0;
			
		while ((i = getword(a, b, i)) != -1)
		{
			switch (gettype(b))
			{

				case -1:
					printf("Invalid expression!");
					return 0;
		
				case NUMBER:
					push(b);
					break;

				case ADD:
					push(pop() + pop());
					break;

				case SUBTRACT:
					push(-(pop() - pop()));
					break;

				case MULTIPLY:
					push(pop() * pop());
					break;

				case DIVIDE:
					if ((temp = pop()) == 0)
					{
						puts("Zero division error!");
						return 0;

					}

					push(pop() / temp);
					break;


				case MODULUS:
					if ((temp = pop()) == 0)
					{
						puts("Zero division error!");
						return 0;

					}

					push(pop() % temp);
					break;
					
				case PI:
					push(3.14);
					break;

				case E:
					push(2.71);
					break;

				case POW:
					temp = pop();
					push(pop(), temp);
					break;

				case SIN:
					push(sin(pop());
					break;

				case COS:
					push(cos(pop());
					break;

				case TAN:
					push(tan(pop());
					break;

				case ASIN:
					push(1 / sin(pop());
					break;

				case ACOS:
					push(1 / cos(pop());
					break;
					
				case ATAN:
					push(1 / tan(pop());
					break;

				case ROOT:
					push(pow(pop(), 1 / pop()));
					break;
		}
		
		printf("%d\n", stack[0]);

	}

}
