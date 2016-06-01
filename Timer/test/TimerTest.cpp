#include "../include/Timer.h"
#include <stdio.h>
#include <unistd.h>

///////////////////////////////////////////////
// Timer Func.
///////////////////////////////////////////////
thrtimer_t timer;

int cnt1;
int cnt2;
int cnt3;

void* OnTimer(void* iID)
{
	int id = *(int *)iID;
	
	for(;;)
	{
		usleep(timer.iLoopTime[id]*1000);
		
		switch(id)
		{
		case 1:
			cnt1++;
			printf("cnt1 : %d\n",cnt1);
			break;
		case 2:
			cnt2++;
			printf("cnt2 : %d\n",cnt2);
			if(cnt2>=5)
			{
				printf("Killed Timer2\n");
				KillTimer(&timer,2);
			}
			break;
		case 3:
			cnt3+=2;
			printf("cnt3 : %d\n",cnt3);
			if(cnt3>=5)
			{
				printf("Killed Timer3\n");
				KillTimer(&timer,3);
			}
			break;
		}
	}	
}

int main()
{
	printf("==================\n");
	printf("Timer Module Check\n");
	printf("==================\n");
	printf("Function : CreateTimer\n");
	CreateTimer(&timer);
	printf("Press Enter Key.\n");
	getchar();
	printf("=====================\n");
	printf("Function : SetTimer\n");
	printf("Press Enter Key.\n");
	getchar();
	SetTimer(&timer,1,1000);
	for(;;)
	{
		if(cnt1>=5)
		{
			printf("Killed Timer1\n");
			KillTimer(&timer,1);
			break;
		}
		usleep(100000);
	}

	printf("=====================\n");
	printf("Function : SetTimer x2\n");
	printf("Press Enter Key.\n");
	getchar();

	SetTimer(&timer,2,1000);
	SetTimer(&timer,3,2000);

	for(;;)
	{
		if(cnt2>=5 && cnt3 >= 5) break;
		usleep(100000);
	}
	
	printf("=====================\n");
	printf("Function : DestroyTimer\n");
	DestroyTimer(&timer);
	printf("Press Enter Key.\n");
	getchar();
	printf("=====================\n");
	printf("End.\n\n");
	return 0;
}