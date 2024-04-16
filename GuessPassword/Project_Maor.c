#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
The program acquires a code and the user has to guess it in the attempts he has,
each stage has a different number of attempts if he fails to guess and finishes 
the attempts prints a loss message if he 
manages to guess then a victory message is printed
**/
enum level{Easy=1,Moderate,Hard,Crazy};
void printRules();
void randNumber();
void checkNumber();
void printOpening(); 
void printLevel();
void choice();
void guessing();
void guessingCrazy();
void misses(int number,int index);
void checkGus(int guess,int index);
void finish();
void loser();
void winer();

int randNum=0;
int miss=0;
int hits=0;
int numberGu=0;
int levelCh=0;

int main()
{
	srand(time(NULL));
	printOpening();
	printRules();
	printLevel();
	randNumber();
	choice();
	if (levelCh==Crazy)
	{
		guessingCrazy();
	}
	else
	{
		guessing();
	}
	finish();
	return 0;
}

/*
The function prints the purpose of the game
input:none
output:none
*/
void printOpening()
{
	printf("Welcome to \"MAGSHIMIM CODE-BREAKER\"!!!\n\nA secret password was chosen to protect the credit card of Pancratius,\nthe descendant of Antiochus.\nYour mission is to stop Pancratius by revealing his secret password.\n\n");
}

/*
The function prints the rules
input:none
output:none
*/
void printRules()
{
	printf("The rules are as follows:\n1. In each round you try to guess the secret password (4 distinct digits)\n2. After every guess you'll receive two hints about the password\n   HITS:   The number of digits in your guess which were exactly right.\n   MISSES: The number of digits in your guess which belongs to\n   \tthe password but were miss-placed.\n3. If you'll fail to guess the password after a certain number of rounds\n   Pancratius will buy all the gifts for Hanukkah!!!\n");
}

/*
The function prints the options (levels)
input:none
output:none
*/

void printLevel()
{
	printf("\nPlease choose the game level:\n1 - Easy (20 rounds)\n2 - Moderate (15 rounds)\n3 - Hard (10 rounds)\n4 - Crazy (random number of rounds 5-25)\n");
}

/*
The function picks up the level and checks that it is standard and then it checks by choice 
how many guesses there are and gives as a parameter to the function
input:none
output:none
*/

void choice()
{
	int choose=0;
	char chooseB=' ';
	do 
	{
		printf("Make a choice:");
		chooseB=getch();
		putchar(chooseB);
		levelCh=(int)(chooseB-'0');
		printf("\n");

	}while(levelCh!=4&&levelCh!=3&&levelCh!=2&&levelCh!=1);

	//levelCh=choose;
	switch(levelCh)
	{
		case Easy:
		{
			printf("Write your guess (only 1-6, no ENTER is needed)\n20 guesses left\n");
			numberGu=20;
			break;
		}
		case Moderate:
		{
			printf("Write your guess (only 1-6, no ENTER is needed)\n15 guesses left\n");
			numberGu=15;
			break;
		}
		case Hard:
		{
			printf("Write your guess (only 1-6, no ENTER is needed)\n10 guesses left\n");
			numberGu=10;
			break;
		}
		case Crazy:
		{
			printf("Write your guess (only 1-6, no ENTER is needed)\nCRAZY MODE!!!\n");
			numberGu=(rand() % (25 - 5 + 1) + 5);
			break;
		}
	}

}
/*
The function receives a guess from the user and returns to him how much is counted exactly and 
how many parts and if he has 4 accurate guesses he calls the function winer and if he loses it calls the loser function
input:none 
output:none
*/
void guessing()
{

	int count=0;
	int i=0;
	int j=0;
	char guess =' ';
	int guessI=0;
	for(i=1;i<=numberGu;i++)
	{
		count =0;
		miss=0;
		hits=0;
		for (j=1;j<=4;j++)
		{
			guess=getch();
			putchar(guess);
			guessI=(int)(guess-'0');
			if (guessI>6||guessI<1)
			{
				count++;
			}
			checkGus(guessI,j);
		}
		printf("\n");
		if (count>=1)
		{
			i--;
			printf("Only 1-6 are allowed, try again!\nWrite your guess (only 1-6, no ENTER is needed)\n%d guesses left!!!\n",numberGu-i);	
		}
		else
		{
			if (hits==4)
			{
				printf(" 4 HITS YOU WON!!!\n\nIt took you only %d guesses, you are a professional code breaker!\n",i);
				winer();
				break;
			}
			else if (i<numberGu)
			{
				printf("you got\t\t%d HITS\t\t%d MISSES\n",hits,miss);
				printf("Write your guess (only 1-6, no ENTER is needed)\n%d guesses left\n",numberGu-i);
			}
		}

	}
	if (i>=numberGu)
	{
		printf("you got\t\t%d HITS\t\t%d MISSES\n\n",hits,miss);
		printf("OOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts.\nNothing left for you...\nThe secret password was %d\n",randNum);
		loser();
	}


}


/*
The function (exists only for the crazy option) receives a guess from the user and returns to him exactly how many writers and how many parts 
and if he has 4 accurate guesses he calls the Winer function and if he loses it calls the losing function
input:none 
output:none
*/
void guessingCrazy()
{
	int count=0;
	int i=0;
	int j=0;
	char guess =' ';
	int guessI=0;
	for(i=1;i<=numberGu;i++)
	{
		count =0;
		miss=0;
		hits=0;
		for (j=1;j<=4;j++)
		{
			guess=getch();
			putchar(guess);
			guessI=(int)(guess-'0');
			if (guessI>6||guessI<1)
			{
				count++;
			}
			checkGus(guessI,j);
		}
		printf("\n");
		if (count>=1)
		{
			i--;
			printf("Only 1-6 are allowed, try again!\nWrite your guess (only 1-6, no ENTER is needed)\n Crazy mode!!!\n");	
		}
		else
		{
			if (hits==4)
			{
				printf(" 4 HITS YOU WON!!!\n\nIt took you only %d guesses, you are a professional code breaker!\n",i);
				winer();
				break;
			}
			else if (i<numberGu)
			{
				printf("you got\t\t%d HITS\t\t%d MISSES\n",hits,miss);
				printf("Write your guess (only 1-6, no ENTER is needed)\nCrazy mode!!!\n");
			}
		}

	}
	if (i>=numberGu)
	{
		printf("you got\t\t%d HITS\t\t%d MISSES\n\n",hits,miss);
		printf("OOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts.\nNothing left for you...\nThe secret password was %d\n",randNum);
		loser();
	}



/*
The function checks how many numbers it is 
guessing accurately and adds to the global variable hits
input:He gets as a parameter the guess he needs to check and he gets the position of (units, tens, hundreds or thousands)(guess,index)
output:none
*/
}

void checkGus(int guess,int index)
{
	int check=0;
	check=randNum;
	switch(index)
	{
		case 1:
		{
			if (guess==(check/1000))
			{
				hits++;
			}
			else
			{
				misses(guess,index);
			}
			break;
		}
		
		case 2:
		{
			if (guess==((check/100)%10))
			{
				hits++;
			}
			else
			{
				misses(guess,index);
			}
			break;
		}
		
		case 3:
		{
			if (guess==((check/10)%10))
			{
				hits++;
			}
			else
			{
				misses(guess,index);
			}
			break;
		}
		
		case 4:
		{
			if (guess==(check%10))
			{

				hits++;
			}
			else
			{
				misses(guess,index);
			}
			break;
		}

	}
}

/*
The function checks how much it is partially guessed and wrong in position,
and adds 1 (for every mistake)to the global variable miss
input:He gets as a parameter the guess he needs to check and he gets the position of (units, tens, hundreds or thousands)(guess,index)
output:none
*/
void misses(int number,int index)
{
	
	int x =0;
	int k =0;
	int y=0;
	int check=0;
	check=randNum;
	switch(index)
	{
		case 1:
		{
			x=1;
			y=10;
			for(k=1;k<=3;k++)
			{
				if (number==((check%y)/x))
				{
					miss++;
				}
				x*=10;
				y*=10;
			}
			break;
		}
		
		case 2:
		{
			if (number==(check/1000))
			{
				miss++;
			}
			x=1;
			y=10;
			for(k=1;k<=2;k++)
			{
				if (number==((check%y)/x))
				{
					miss++;
				}
				x*=10;
				y*=10;
			}

			break;
		}
		
		case 3:
		{
			x=100;
			y=1000;
			if (number==(check%10))
			{
				miss++;
			}
			for(k=1;k<=2;k++)
			{
				if (number==((check%y)/x))
				{
					miss++;
				}
				x*=10;
				y*=10;
			}
			break;
		}
		
		case 4:
		{
			x=10;
			y=100;
			for(k=1;k<=3;k++)
			{
				if (number==((check%y)/x))
				{
					miss++;
				}
				x*=10;
				y*=10;
			}
			break;
		}

	}
}

/*
The function checks if the same number appears several times and if so invites the function so that it can generate a new number
input:none
output:none
*/

void checkNumber()
{
	int flag=0;
	int num=0;
	int backup=0;
	int compare =0;
	int count=0;
	int bc=0;
	backup=randNum;
	compare=randNum;
	while(backup!=0)
	{
		num=backup%10;
		backup=backup/10;
		while(compare!=0)
		{
			bc=compare%10;
			compare=compare/10;
			if(num==bc)
			{
				count++;
			}

		}
		if(count>=2)
		{
			flag=1;
			backup=0;
		}
		compare=randNum;
		count=0;
	}
	if (flag==1)
	{
		randNumber();
	}
	
}

/*
The function will generate a number between 1000-6666 and all digits will be between 1-6
input:none
output:none
*/
void randNumber()
{

	do
	{
		randNum=rand() % (6666 - 1111 + 1) + 1111;
	}while(((((randNum/100)%10)>6)||(((randNum/100)%10)<=0))||((((randNum/10)%10)>6)||(((randNum/10)%10)<=0))||(((randNum%10)>6)||((randNum%10)<=0)));
	checkNumber();
	

}


/*
The function prints the victory message in ascii characters
input:none
output:none
*/
void winer()
{
	printf("      ___           ___           ___                    ___                       ___   \n");
	printf("     |\\__\\         /\\  \\         /\\__\\                  /\\__\\          ___        /\\__\\  \n");
	printf("     |:|  |       /::\\  \\       /:/  /                 /:/ _/_        /\\  \\      /::|  | \n");
	printf("     |:|  |      /:/\\:\\  \\     /:/  /                 /:/ /\\__\\       \\:\\  \\    /:|:|  | \n");
	printf("     |:|__|__   /:/  \\:\\  \\   /:/  /  ___            /:/ /:/ _/_      /::\\__\\  /:/|:|  | \n");
	printf("     /::::\\__\\ /:/__/ \\:\\__\\ /:/__/  /\\__\\          /:/_/:/ /\\__\\  __/:/\\/__/ /:/ |:| /\\__\\ \n");
	printf("    /:/~~/~    \\:\\  \\ /:/  / \\:\\  \\ /:/  /          \\:\\/:/ /:/  / /\\/:/  /    \\/__|:|/:/  / \n");
	printf("   /:/  /       \\:\\  /:/  /   \\:\\  /:/  /            \\::/_/:/  /  \\::/__/         |:/:/  / \n");
	printf("   \\/__/         \\:\\/:/  /     \\:\\/:/  /              \\:\\/:/  /    \\:\\__\\         |::/  / \n");
	printf("                  \\::/  /       \\::/  /                \\::/  /      \\/__/         /:/  / \n");
	printf("                   \\/__/         \\/__/                  \\/__/                     \\/__/ \n");

	printf("                                             ^....~..^\n");
	printf("                                     ^....^.-:;;+=io*!?%%?e*=;-.\n");
	printf("                                  :i*i+:~^`^-;;+==io*!?$$$%?!e*oi=\n");
	printf("                                  ieeo+:~^`^-;;+==ioe!?$$%%?!e*iii     \n");
	printf("                         ^~~~.    =eeo+:~^`^-;++==ioe!?$$%%?!e*iii    .~~~  \n");
	printf("                        -=iiioo;. +eeo+:~^`^-;;+==io*!?$$%%?!e*iii`^;ioiii=-    \n");
	printf("                       .ii_``.;o*:+eeo+:~^`^-;;+==io*!?$$%%?!e*iii_**+~``_ii~       \n");
	printf("                       :i+     .oe*eeo+:~^`^-;;+==io*!?$$%%?!e*ii*!*~    `;i;     \n");
	printf("                       ;i_      .!?eeo+:~^`^-;;+==io*!?$$%%?!e*ii?!~      _i+       \n");
	printf("                       :o_       i%?eo+:~^`^-;;+==io*!?$$%%?!e*i*$o       -i:            \n");           
	printf("                       ~o:       -$?eo+:~^`^-;;+===ie!?$$%%?!e*ie$:       _o- \n");
	printf("                       ^o=       ^%!eo+:~^`^-;;++++oe!?$$%%?!e*i*%.       +o. \n");
	printf("                        io^    ^.~?!eo+:~^`^-;;+;++oe!?$$%%?!e*io?-^^     oo\n");
	printf("                        :e_    ~?!!*eo+:~^`^-;i*=+;oe!?$$%%?!e*oi!!?-    -e;\n");
	printf("                        ^e*    .!*_=eo+:~^`^-;;+++;oe!?$$%%?!e*oi_*!.    oe^\n");
	printf("                         +?_    ^  +eo+:~^`^-;;+++;oe!?$$%%?!e*i=  ^    -?= \n");
	printf("                         .?!`      ;eo+:~^`^-;;+++;oe!?$$%%?!e*o;       e%~      \n");                   
	printf("                          =$:      _eo+:~^`^-;;+++;oe!?$$%%?!e*i-      _%i     \n");
	printf("                          ^!e`     -eo+:~^`^-;;+++;oe!?$$%%?!e*i^     `*!^     \n");
	printf("                           _!+     .*o+:~^`^-;;+++;oe!?$$%%?!e*i      ;e:      \n");
	printf("                            =*~     oo+:~^`^-;;+++;oe!?$$%%?!e*=     .o=       \n");
	printf("                            ^i=^    +o+:~^`^-;;+++;oe!?$$%%?!e*;    `+i.      \n");
	printf("                             ~=;    _o+:~^`^-;;+++;oe!?$$%%?!e*-    :=-       \n");
	printf("                              :+_   `i+:~^`^-;;+++;oe!?$$$%?!e*^   -+:\n");
	printf("                               :;~   ;+:~^`^-;;++++ie!?$$$%?!ei   .;;\n");
	printf("                               ^:_^  ~+:~^`^-;;++;;+i*?$$$%?!e;  ^_:^ \n");
	printf("                                ^_~` `+:~^`^-;io***ee!%$O$%?!e~ `~_^\n");
	printf("                                  -^  ::~^`^-;;++=ioe!?$$$%?!*` ^-^\n");
	printf("                                   .  -_~^`^-;;+==io*!?$$$%?!+  .\n");
	printf("                                    ^ .:~^`^-;;+==io*!?$$$%?!-`^\n");                             
	printf("                                    ^^^-~^`^-;;+==io*!?$$$%?o^.^\n");
	printf("                                     ^.~~^`^-;;+==io*!?$$$%?_.^\n");
	printf("                                      ^~-^`^-;;+==io*!?$$$%\e~^ \n");
	printf("                                    ^.^-;^`^-;;+==io*!?$$%%=-^.^\n");
	printf("                                     ~:+_~`^-;;+==io*!?$$$e~=:-\n");
	printf("                                     .:_ -`^-;;+==io*!?$$%- _:~\n");
	printf("                                         ^-^-;++==io*!?$$o`\n");                         
	printf("                                          ~~-;;+==io*!?$%.\n");
	printf("                                           __;;+==io*!?$;\n");
	printf("                                            ;;++==io*!?i\n");
	printf("                                             ++++=io*!=\n");
	printf("                                             ^+;;=ioi_\n");
	printf("                                              ;~-+*$?_\n");
	printf("                                              ;~-+*$?-     \n");  
	printf("                                              .--;=oe.       \n");
	printf("                                              `.~;=o!`      \n");
	printf("                                              `.~;=oe`      \n");
	printf("                                              `.~;=oe`      \n");
	printf("                                              `.~;=o!`      \n");
	printf("                                              ^.~;=o?^           \n");                                   
	printf("                                              ~.~;=o?-\n");
	printf("                                              -^~;=o?+\n");
	printf("                                              :.~;=o?e\n");
	printf("                                             -;.~;=o?$-\n");
	printf("                                           ^~o;.~;=o?$*.^\n");
	printf("                                        _+io!*;.~+=o?$?*oi+:.\n");
	printf("                                       :ioo*e!i~-;=o!%!**oii=`    \n");                                  
	printf("                                       +=+i*eee!!!!e!ee**o**o^       \n");
	printf("                                      -o=:~.~;ioo*ee!!?%%?!eo:^       \n");
	printf("                                     ^ii=:~^`-;++=ioe?$$%?!eoi-       \n");
}


/*
The function prints the loss message in ascii characters
input:none
output:none
*/
void loser()
{
	printf("      ___           ___           ___                    ___       ___           ___           ___      \n");
	printf("     |\\__\\         /\\  \\         /\\__\\                  /\\__\\     /\\  \\         /\\  \\         /\\  \\     \n");
	printf("     |:|  |       /::\\  \\       /:/  /                 /:/  /    /::\\  \\       /::\\  \\       /::\\  \\    \n");
	printf("     |:|  |      /:/\\:\\  \\     /:/  /                 /:/  /    /:/\\:\\  \\     /:/\\ \\  \\     /:/\\:\\  \\   \n");
	printf("     |:|__|__   /:/  \\:\\  \\   /:/  /  ___            /:/  /    /:/  \\:\\  \\   _\\:\\~\\ \\  \\   /::\\~\\:\\  \\  \n");
	printf("     /::::\\__\\ /:/__/ \\:\\__\\ /:/__/  /\\__\\          /:/__/    /:/__/ \\:\\__\\ /\\ \\:\\ \\ \\__\\ /:/\\:\\ \\:\\__\\ \n");
	printf("    /:/~~/~    \\:\\  \\ /:/  / \\:\\  \\ /:/  /          \\:\\  \\    \\:\\  \\ /:/  / \\:\\ \\:\\ \\/__/ \\:\\~\\:\\ \\/__/ \n");
	printf("   /:/  /       \\:\\  /:/  /   \\:\\  /:/  /            \\:\\  \\    \\:\\  /:/  /   \\:\\ \\:\\__\\    \\:\\ \\:\\__\\   \n");
	printf("   \\/__/         \\:\\/:/  /     \\:\\/:/  /              \\:\\  \\    \\:\\/:/  /     \\:\\/:/  /     \\:\\ \\/__/   \n");
	printf("                  \\::/  /       \\::/  /                \\:\\__\\    \\::/  /       \\::/  /       \\:\\__\\     \n");
	printf("                   \\/__/         \\/__/                  \\/__/     \\/__/         \\/__/         \\/__/      \n\n\n\n");
	
               
	printf("       .sNMMMNmdhyyssyhdmNMMMMNmdyo+:- \n");          
	printf("      -NMm+-````````` `````-:/+sydmNMNNmdyyoo+/.  \n");
	printf("      oMM/                      ```.-/omMMNNMMMN. \n");
	printf("     /mMM/                             dMM...hMM- \n");
	printf("    oMMy-`                            `NMd   yMM- \n");
	printf("   `NMd`                              -MMy   yMM- \n");
	printf("   .MMd                               /MM+   sMM- \n");
	printf("  .hMNy`                              oMM:   sMM: \n");
	printf(" `dMN:`                               yMM-   sMM: \n");
	printf(" -MMy                                 yMM.   sMM: \n");
	printf(" `NMm-                                hMM.   sMM: \n");
	printf("  :mMNo                               yMM.   sMM: \n");
	printf("  `hMMo        ``````             ``..yMM:```sMM: \n");
	printf("  /MMs`    .oyhhddddhhyo-      .:shdmmNMMmdhhmMM- \n");
	printf("  +MM/     -hdhdMMNdMMmm+    .omMNdso+++ossyhdho` \n");
	printf("  .NMm/-----/oymMNshMM.`    :mMm+.                \n");
	printf("   -dNNNNNNNNNmy+-`MMd     :NMd.                  \n");
	printf("    `.-:::::-.`   `MMy    .NMm.                   \n");
	printf("                  `NMh    sMM:                    \n");
	printf("                   yMN-  `NMm`                    \n");
	printf("                   .mMm+-:MMy                     \n");
	printf("                    .yNMMMMM+                     \n");
	printf("                      `-::-`    \n");

}

/*
Finishing function, it asks the user if he wants another round or finish
input:none
output:none
*/
void finish()
{
	char choose=' ';
	do 
	{
		printf("Would you like to play again? (y/n):");
		choose=getch();
		putchar(choose);
		printf("\n");
	}while(choose!='y'&&choose!='n');
	
	if (choose=='y')
	{
		main();
	}
	else
	{
		printf("Bye Bye!");
	}
}