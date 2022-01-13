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

	printf("開始遊戲 要與誰玩\n");
	printf("1 與電腦玩 2兩個人玩 0退出遊戲\n");
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
			printf("電腦的牌 : X  \n");
			printf("你的牌 :   %c \n", face[you.tims[0] - 1]);

			addcard();

			i = 1;
			while (ans == 1)
			{
				getcard(you, i);

				printf("\n你的牌 : %c \n", face[you.tims[i] - 1]);
				i++;

				if (you.total <= 10.5 && you.tims[4] != 0)
				{
					show(you);
					printf("你過五關\n=====You Win=====\n");
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


			printf("輪到電腦\n");


			if (computer.total < 10)
			{
				i = 1;

				while (computer.total < 8)
				{
					getcard(computer, i);

					printf("\n電腦的牌 : %c \n", face[computer.tims[i] - 1]);
					i++;

					if (computer.total <= 10.5 && computer.tims[4] != 0)
					{
						show(computer);
						printf("電腦過五關 \n*****Computer Win*****\n");
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

			printf("\n攤牌\n\n");

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
			printf("玩家1的牌 :    %c  \n", face[you.tims[0] - 1]);


			addcard();

			i = 1;

			while (ans == 1)
			{
				getcard(you, i);

				printf("\n你的牌 : %c \n", face[you.tims[i] - 1]);
				i++;


				if (you.total <= 10.5 && you.tims[5] != 0)
				{
					show(you);
					printf("你過五關\n=====玩家1 Win=====\n");
					again();
				}
				if (you.total > 10.5)
				{
					show(you);
					printf("\n*****玩家2 Win*****\n");
					again();
				}

				addcard();
			}

			system("cls");
			//=======================================================
			printf("輪到玩家2\n");
			i = 0;
			getcard(you2, i);


			printf("D = 10\n");
			printf("玩家2的牌 :    %c  \n", face[you2.tims[0] - 1]);

			addcard();

			i = 1;

			while (ans == 1)
			{
				getcard(you2, i);

				printf("\n你的牌 : %c \n", face[you2.tims[i] - 1]);
				i++;


				if (you2.total <= 10.5 && you2.tims[5] != 0)
				{
					show(you2);
					printf("你過五關\n=====玩家2 Win=====\n");
					again();
				}
				if (you2.total > 10.5)
				{
					show(you2);
					printf("\n*****玩家1 Win*****\n");
					again();
				}

				addcard();
			}

			printf("\n攤牌\n\n");

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

			puts("輸入錯誤，再輸入一次");
			printf("1 與電腦玩 2兩個人玩 0退出遊戲\n");
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

	printf("\n是否再來一局   1是   2否 ");
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
			printf("再輸入一次");
			printf("\n是否再來一局   1是   2否 ");
			scanf(" %d", &agn);
		}
	}
}


void addcard()
{
	printf("\n是否要加牌   1是   2否 ");
	scanf(" %d", &ans);

	while ((ans != 1) && (ans != 2))
	{
		printf("再輸入一次\n");
		printf("\n是否要加牌   1是   2否 ");
		scanf(" %d", &ans);
	}
}

void show(player x)
{
	int i;
	if (x.name == 'c')
	{

		printf("電腦所有的牌 : ");

		for (i = 0; i < 5; i++)
		{
			printf("%c ", face[computer.tims[i] - 1]);
		}

		printf("電腦的總和 : %.1f \n", computer.total);
	}
	else if (x.name == 'y')
	{

		printf("你所有的牌 : ");

		for (i = 0; i < 6; i++)
		{
			printf("%c ", face[you.tims[i] - 1]);
		}

		printf("你的總和 : %.1f \n", you.total);
	}
	else if (x.name == 'q')
	{

		printf("玩家2所有的牌 : ");

		for (i = 0; i < 6; i++)
		{
			printf("%c ", face[you2.tims[i] - 1]);
		}

		printf("玩家2的總和 : %.1f \n", you2.total);
	}
}

void showwhowin(player x, player z)
{
	if ((x.total = you.total) && (z.total = computer.total))
	{
		if ((x.total > z.total) && (x.total <= 10.5) && (z.total <= 10.5))
		{
			printf("\n=====玩家1 Win=====\n");
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
			printf("\n=====玩家1 Win=====\n");
		}
		else if ((z.total > x.total) && (z.total <= 10.5) && (x.total <= 10.5))
		{
			printf("\n*****玩家2 Win*****\n");
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