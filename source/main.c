#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _player
{
	char name;
	int tims[6];
	float total;
}player;
player computer;
player you;
player you2;


const char face[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K' };   // 0~12, D = 10
int remain[13] = { 4 };
int ans;
const char* flower[4] = { "Hearts","Diamonds","Clubs","Spades" };


void getcard(player x, int a);
void again();
void addcard();
void show(player x);
void showwhowin(player x, player z);


int main()
{

	int who, i;

	computer.total = 0;
	you.total = 0;
	you2.total = 0;

	computer.name = 'c';
	you.name = 'y';
	you2.name = 'q';


	for (i = 0; i < 6; i++)
	{
		computer.tims[i] = 0;
		you.tims[i] = 0;
		you2.tims[i] = 0;
	}

	printf("�}�l�C�� �n�P�֪�\n");
	printf("1 �P�q���� 2��ӤH�� 0�h�X�C��\n");
	scanf_s("%d", &who);
	srand(time(NULL));

	do
	{
		switch (who)
		{
		case 1:
			i = 0;
			getcard(computer, i);
			getcard(you, i);

			printf("D = 10\n");
			printf("�q�����P : X  \n");
			printf("�A���P :   %c \n", face[you.tims[0] - 1]);

			addcard();

			i = 1;
			while (ans == 1)
			{
				getcard(you, i);

				printf("\n�A���P : %c \n", face[you.tims[i] - 1]);
				i++;

				if (you.total <= 10.5 && you.tims[4] != 0)
				{
					show(you);
					printf("�A�L����\n=====You Win=====\n");
					again();
				}
				if (you.total > 10.5)
				{
					show(you);
					printf("\n*****Computer Win*****\n");
					again();
				}

				addcard();
			}


			printf("����q��\n");


			if (computer.total < 10)
			{
				i = 1;

				while (computer.total < 8)
				{
					getcard(computer, i);

					printf("\n�q�����P : %c \n", face[computer.tims[i] - 1]);
					i++;

					if (computer.total <= 10.5 && computer.tims[4] != 0)
					{
						show(computer);
						printf("�q���L���� \n*****Computer Win*****\n");
						again();
					}
					if (computer.total > 10.5)
					{
						show(computer);
						printf("\n=====You Win=====\n");
						again();
					}
				}
			}

			printf("\n�u�P\n\n");

			show(computer);
			show(you);

			showwhowin(you, computer);

			printf("\n");

			again();
			break;

		case 2:
			i = 0;
			getcard(you, i);


			printf("D = 10\n");
			printf("���a1���P :    %c  \n", face[you.tims[0] - 1]);


			addcard();

			i = 1;

			while (ans == 1)
			{
				getcard(you, i);

				printf("\n�A���P : %c \n", face[you.tims[i] - 1]);
				i++;


				if (you.total <= 10.5 && you.tims[5] != 0)
				{
					show(you);
					printf("�A�L����\n=====���a1 Win=====\n");
					again();
				}
				if (you.total > 10.5)
				{
					show(you);
					printf("\n*****���a2 Win*****\n");
					again();
				}

				addcard();
			}

			system("cls");
			//=======================================================
			printf("���쪱�a2\n");
			i = 0;
			getcard(you2, i);


			printf("D = 10\n");
			printf("���a2���P :    %c  \n", face[you2.tims[0] - 1]);

			addcard();

			i = 1;

			while (ans == 1)
			{
				getcard(you2, i);

				printf("\n�A���P : %c \n", face[you2.tims[i] - 1]);
				i++;


				if (you2.total <= 10.5 && you2.tims[5] != 0)
				{
					show(you2);
					printf("�A�L����\n=====���a2 Win=====\n");
					again();
				}
				if (you2.total > 10.5)
				{
					show(you2);
					printf("\n*****���a1 Win*****\n");
					again();
				}

				addcard();
			}

			printf("\n�u�P\n\n");

			show(you);
			show(you2);

			showwhowin(you, you2);
			printf("\n");

			again();
			break;
		case 0:

			exit(EXIT_SUCCESS);
			break;

		default:

			puts("��J���~�A�A��J�@��");
			printf("1 �P�q���� 2��ӤH�� 0�h�X�C��\n");
			scanf_s("%d", &who);
			break;
		}
	} while (who <= 2);
	return 0;
}




//=======================================================================

void getcard(player x, int a)
{
	int i;
	if (x.name == 'c')
	{
		for (i = a; i <= a; i++)
		{
			computer.tims[i] = rand() % 13 + 1;
			if (computer.tims[i] > 10)
			{
				computer.total = computer.total + 0.5;
			}
			else
			{
				computer.total = computer.total + computer.tims[i];
			}
			remain[computer.tims[i] - 1]--;
		}
	}
	else if (x.name == 'y')
	{
		for (i = a; i <= a; i++)
		{
			you.tims[i] = rand() % 13 + 1;

			if (you.tims[i] > 10)
			{
				you.total = you.total + 0.5;
			}
			else
			{
				you.total = you.total + you.tims[i];
			}
			remain[you.tims[i] - 1]--;
		}
	}
	else if (x.name == 'q')
	{
		for (i = a; i <= a; i++)
		{
			you2.tims[i] = rand() % 13 + 1;

			if (you2.tims[i] > 10)
			{
				you2.total = you2.total + 0.5;
			}
			else
			{
				you2.total = you2.total + you2.tims[i];
			}
			remain[you2.tims[i] - 1]--;
		}
	}
}

void again()
{
	int agn;

	printf("\n�O�_�A�Ӥ@��   1�O   2�_ ");
	scanf(" %d", &agn);

	while ((agn != 1) || (agn != 2))
	{
		if (agn == 1)
		{
			system("cls");
			main();
		}
		else if (agn == 2)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("�A��J�@��");
			printf("\n�O�_�A�Ӥ@��   1�O   2�_ ");
			scanf(" %d", &agn);
		}
	}
}


void addcard()
{
	printf("\n�O�_�n�[�P   1�O   2�_ ");
	scanf(" %d", &ans);

	while ((ans != 1) && (ans != 2))
	{
		printf("�A��J�@��\n");
		printf("\n�O�_�n�[�P   1�O   2�_ ");
		scanf(" %d", &ans);
	}
}

void show(player x)
{
	int i;
	if (x.name == 'c')
	{

		printf("�q���Ҧ����P : ");

		for (i = 0; i < 5; i++)
		{
			printf("%c ", face[computer.tims[i] - 1]);
		}

		printf("�q�����`�M : %.1f \n", computer.total);
	}
	else if (x.name == 'y')
	{

		printf("�A�Ҧ����P : ");

		for (i = 0; i < 6; i++)
		{
			printf("%c ", face[you.tims[i] - 1]);
		}

		printf("�A���`�M : %.1f \n", you.total);
	}
	else if (x.name == 'q')
	{

		printf("���a2�Ҧ����P : ");

		for (i = 0; i < 6; i++)
		{
			printf("%c ", face[you2.tims[i] - 1]);
		}

		printf("���a2���`�M : %.1f \n", you2.total);
	}
}

void showwhowin(player x, player z)
{
	if ((x.total = you.total) && (z.total = computer.total))
	{
		if ((x.total > z.total) && (x.total <= 10.5) && (z.total <= 10.5))
		{
			printf("\n=====���a1 Win=====\n");
		}
		else if ((z.total > x.total) && (z.total <= 10.5) && (x.total <= 10.5))
		{
			printf("\n*****Computer Win*****\n");
		}
		else if ((z.total == x.total) && (z.total <= 10.5) && (x.total <= 10.5))
		{
			printf("\n-----Tie-----\n");
		}
		else
		{
			printf("XXXXX No One Win XXXXX\n");
		}
	}

	else if ((x.total = you.total) && (z.total = you2.total))
	{
		if ((x.total > z.total) && (x.total <= 10.5) && (z.total <= 10.5))
		{
			printf("\n=====���a1 Win=====\n");
		}
		else if ((z.total > x.total) && (z.total <= 10.5) && (x.total <= 10.5))
		{
			printf("\n*****���a2 Win*****\n");
		}
		else if ((z.total == x.total) && (z.total <= 10.5) && (x.total <= 10.5))
		{
			printf("\n-----Tie-----\n");
		}
		else
		{
			printf("XXXXX No One Win XXXXX\n");
		}
	}

}