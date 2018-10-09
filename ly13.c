#include <stdio.h>

#include <stdlib.h>

#include<time.h>



///函数原型以及定义

int count;///定义题目数量

int max;///定义最大数字

int ffloat;///选择是否有小数

int file;///选择是否输出为文件

int bracket;///选择是否有括号

int getChoice();

void Menu();

int integer(int);

int decimal(int);

FILE *fp;///定义文件



		 /*

		 用户选择功能

		 返回用户的功能选择

		 choice=1表示加法，2表示减法，3表示乘法，4表示除法，0表示退出

		 */

int getChoice()

{

	int choice;

	scanf("%d", &choice);

	return choice;

}



/*

显示功能菜单

*/

void Menu()

{

	printf("===================================\n");

	printf("\n欢迎使用小学生四则运算练习软件\n");

	printf("\n选项如下:\n");

	printf("\t1、加法练习  (有括号时为加法和除法的复合运算)\n");

	printf("\t2、减法练习  (有括号时为减法和乘法的复合运算)\n");

	printf("\t3、乘法练习  (有括号时为加法和乘法的复合运算)\n");

	printf("\t4、除法练习  (有括号时为减法和除法的复合运算)\n");

	printf("\n===================================\n");

}



/*

整数运算

*/

int integer(int n)

{

	int i, j, m;

	int ranswer1[count];

	int t = 0;                ///临时变量

	char operation;            ///运算符号

	int num1[count];               ///操作数1

	int num2[count];

	int num5[count];               ///操作数2

	srand(time(NULL)); ///初始化随机数种子

	for (j = 1;j <= 2 * count; j++)

	{

		num1[j] = rand() % max + 1;           ///取0—max之间的随机数

		num2[j] = rand() % max + 1;

		num5[j] = rand() % max + 1;

	}



	switch (n)

	{

	case 1:

		operation = '+';

		if (bracket == 1)

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%d %c %d)/ %d = \n", num1[i], operation, num2[i], num5[i]);

				fprintf(fp, "(%d %c %d)/ %d = \n", num1[i], operation, num2[i], num5[i]);

			}

		}

		break;



	case 2:

		operation = '-';

		if (bracket == 1)

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%d %c %d)* %d = \n", num1[i], operation, num2[i], num5[i]);

				fprintf(fp, "(%d %c %d)* %d = \n", num1[i], operation, num2[i], num5[i]);

			}

		}

		break;



	case 3:

		operation = '*';

		if (bracket == 1)

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%d + %d)%c %d = \n", num1[i], num2[i], operation, num5[i]);

				fprintf(fp, "(%d + %d)%c %d = \n", num1[i], num2[i], operation, num5[i]);

			}

		}

		break;



	case 4:

		operation = '/';

		if (bracket == 1)

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%d - %d)%c %d = \n", num1[i], num2[i], operation, num5[i]);

				fprintf(fp, "(%d - %d)%c %d = \n", num1[i], num2[i], operation, num5[i]);

			}

		}

		break;

	}



	///减法操作不够减的时候，交换两个操作数

	for (i = 1;i <= count;i++)

	{

		if ((operation == '-') && (num1[i]<num2[i]))

		{

			t = num1[i];

			num1[i] = num2[i];

			num2[i] = t;

		}



		///除法操作中的除数，即num2为0时就将num2强制置为1

		///将num1的值赋值给num1*num2，防止不能整除

		if (operation == '/')

		{

			if (num2[i] == 0)

			{

				num2[i] = 1;

			}

			num1[i] = num1[i] * num2[i];        ///防止num1不能被num2整除的语句

		}

		if (bracket == 0)

		{

			printf("%d%c%d= \n", num1[i], operation, num2[i]);

			fprintf(fp, "%d%c%d= \n", num1[i], operation, num2[i]);

		}

	}

	///计算并给出正确答案

	printf("正确答案为： \n");

	fprintf(fp, "正确答案为： \n");

	for (i = 1;i <= count;i++)

	{

		switch (operation)

		{

		case '+':

			if (bracket == 1)  ///有括号时正确答案的计算

				ranswer1[i] = (num1[i] + num2[i]) / num5[i];

			else if (bracket == 0) ///无括号时正确答案的计算

				ranswer1[i] = num1[i] + num2[i];

			break;



		case '-':

			if (bracket == 1)

				ranswer1[i] = (num1[i] - num2[i])*num5[i];

			else if (bracket == 0)

				ranswer1[i] = num1[i] + num2[i];

			break;



		case '*':

			if (bracket == 1)

				ranswer1[i] = (num1[i] + num2[i])*num5[i];

			else if (bracket == 0)

				ranswer1[i] = num1[i] + num2[i];

			break;



		case '/':

			if (bracket == 1)

				ranswer1[i] = (num1[i] - num2[i]) / num5[i];

			else if (bracket == 0)

				ranswer1[i] = num1[i] + num2[i];

			break;

		}

		printf("%d  \n", ranswer1[i]);

		fprintf(fp, "%d  \n", ranswer1[i]);

	}

	printf("继续请按1，结束请按0\n");///选择是否结束程序

	scanf("%d", &m);

	if (m == 1)

		return 1;

	else

		return 0;

}



/*

小数运算

*/

int decimal(int n)

{

	int i, j, m;

	float ranswer2[count];

	float t;                ///临时变量

	char operation;            ///运算符号

	float num3[count];               ///操作数1

	float num4[count];             ///操作数2

	float num6[count];

	srand(time(NULL));     ///初始化随机数种子

	for (j = 1;j <2 * count;j++)

	{

		num3[j] = rand() / (double)(RAND_MAX / max) + 1;///产生随机小数

		num4[j] = rand() / (double)(RAND_MAX / max) + 1;

		num6[j] = rand() / (double)(RAND_MAX / max) + 1;

	}



	switch (n)

	{

	case 1:

		operation = '+';

		if (bracket == 1)    ///有括号的情况

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%.2f %c %.2f)/ %.2f = \n", num3[i], operation, num4[i], num6[i]);

				fprintf(fp, "(%.2f %c %.2f)/ %.2f = \n", num3[i], operation, num4[i], num6[i]);

			}

		}

		break;



	case 2:

		operation = '-';

		if (bracket == 1)

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%.2f %c %.2f)* %.2f = \n", num3[i], operation, num4[i], num6[i]);

				fprintf(fp, "(%.2f %c %.2f)* %.2f = \n", num3[i], operation, num4[i], num6[i]);

			}

		}

		break;



	case 3:

		operation = '*';

		if (bracket == 1)

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%.2f + %.2f)%c %.2f = \n", num3[i], num4[i], operation, num6[i]);

				fprintf(fp, "(%.2f + %.2f)%c %.2f = \n", num3[i], num4[i], operation, num6[i]);

			}

		}

		break;



	case 4:

		operation = '/';

		if (bracket == 1)

		{

			for (i = 1;i <= count;i++)

			{

				printf("(%.2f - %.2f)%c %.2f = \n", num3[i], num4[i], operation, num6[i]);

				fprintf(fp, "(%.2f - %.2f)%c %.2f = \n", num3[i], num4[i], operation, num6[i]);

			}

		}

		break;



	}



	for (i = 1;i <= count;i++)

	{

		if ((operation == '-') && (num3[i]<num4[i]))

		{

			t = num3[i];

			num3[i] = num4[i];

			num4[i] = t;

		}

		if (operation == '/')

		{

			if (num4[i] == 0)

			{

				num4[i] = 1;

			}

			num3[i] = num3[i] * num4[i];

		}

		if (bracket == 0)  ///无括号时的输出

		{

			printf("%.2f%c%.2f= \n", num3[i], operation, num4[i]);

			fprintf(fp, "%.2f%c%.2f= \n", num3[i], operation, num4[i]);

		}

	}

	printf("正确答案为： \n");

	fprintf(fp, "正确答案为： \n");

	for (i = 1;i <= count;i++)

	{

		switch (operation)

		{

		case '+':

			if (bracket == 1)

				ranswer2[i] = (num3[i] + num4[i]) / num6[i];

			else if (bracket == 0)

				ranswer2[i] = num3[i] + num4[i];

			break;



		case '-':

			if (bracket == 1)

				ranswer2[i] = (num3[i] - num4[i])*num6[i];

			else if (bracket == 0)

				ranswer2[i] = num3[i] - num4[i];

			break;



		case '*':

			if (bracket == 1)

				ranswer2[i] = (num3[i] + num4[i])*num6[i];

			else if (bracket == 0)

				ranswer2[i] = num3[i] * num4[i];

			break;



		case '/':

			if (bracket == 1)

				ranswer2[i] = (num3[i] - num4[i]) / num6[i];

			else if (bracket == 0)

				ranswer2[i] = num3[i] / num4[i];

			break;

		}

		printf("%.2f  \n", ranswer2[i]);

		fprintf(fp, "%.2f  \n", ranswer2[i]);

	}



	printf("继续请按1，结束请按0\n");

	scanf("%d", &m);

	if (m == 1)

		return 1;

	else

		return 0;

}



///主函数

int main(void)

{

	int a = 1, choice;        ///接收用户的选择

	do      ///循环开始功能

	{

		Menu();                  ///显示菜单

		printf("请输入需要打印题目数量：\n");

		scanf("%d", &count);

		printf("请输入题目中的最大数字：\n");

		scanf("%d", &max);

		printf("请选择是否需要小数(是为1，否为0)：\n");

		scanf("%d", &ffloat);

		printf("请选择是否输出到文件(是为1，否为0)：\n");

		scanf("%d", &file);

		printf("请选择是否需要括号(是为1，否为0)：\n");

		scanf("%d", &bracket);

		printf("请输入你的选择（0--4）：\n");

		if (file == 1)

			fp = fopen("四则运算.txt", "w");

		choice = getChoice();

		if (choice != 0)

		{

			///控制choice的范围

			if (choice<0 || choice>5)

				choice = 1;

			if (ffloat == 0)

			{

				a = integer(choice);

			}

			if (ffloat == 1)

			{

				a = decimal(choice);

			}

		}

		if (choice == 0)

		{

			a = 0;

			if (file == 1)

				fclose(fp);

			break;                ///用户选择0，退出循环（退出系统）

		}

	} while (a == 1);

	printf("感谢使用本软件\n");

	return 0;

}