#include "TimerTest2.h"

// Global class variable
Test *g_test;

///////////////////////////////////////////////
// Timer Function with Class style
///////////////////////////////////////////////

void* OnTimer(void* iID)
{
	int id = *(int *)iID;
	
	for(;;)
	{
		usleep(g_test->timer.iLoopTime[id]*1000);
		
		switch(id)
		{
		case 1:
			g_test->Cnt1();
			break;
		case 2:
			g_test->Cnt2();
			break;
		case 3:
			g_test->Cnt3();
			break;
		}
	}	
}

void Test::Cnt1()
{
	cnt1++;
	printf("cnt1 : %d\n",cnt1);
}

void Test::Cnt2()
{
	g_test->cnt2++;
	printf("cnt2 : %d\n", cnt2);
	if(cnt2>=5)
	{
		printf("Killed Timer2\n");
		KillTimer(&timer,2);
	}
}

void Test::Cnt3()
{
	g_test->cnt3+=2;
	printf("cnt3 : %d\n",cnt3);
	if(cnt3>=5)
	{
		printf("Killed Timer3\n");
		KillTimer(&timer,3);
	}
}


void Test::Process()
{
	printf("==================\n");
	printf("Timer Module Check\n");
	printf("==================\n");
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
	printf("Press Enter Key.\n");
	getchar();
	printf("=====================\n");
	printf("End.\n\n");
}


Test::Test()
{
	cnt1 = 0;
	cnt2 = 0;
	cnt3 = 0;
	g_test = this;
	CreateTimer(&timer);
}

Test::~Test()
{
	DestroyTimer(&timer);
}


/////////////////////////////////////////////////////////
// Main

int main()
{
	Test test;
	test.Process();
	return 0;
}