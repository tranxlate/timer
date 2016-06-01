
/*//////////////////////////////////////////////////////////////////////////////
// 개발자 : sjm
// 날짜 : 2015.03.12
// 명칭 : Timer
// 기능 : 타이머를 관리할 수 있다.
//////////////////////////////////////////////////////////////////////////////*/

#ifndef _TIMER_H_
#define _TIMER_H_

#include <pthread.h>

#define MAX_TIMER 32

struct THREADTIMER
{
	pthread_t threads[MAX_TIMER];
	int isUse[MAX_TIMER];
	int iLoopTime[MAX_TIMER];
	int iID[MAX_TIMER];
};
typedef struct THREADTIMER thrtimer_t;
/*
static pthread_t *threads;
static int *g_isUse;
static int *g_iLoopTime;
static int *g_iID;
*/

void CreateTimer(thrtimer_t *info);
void DestroyTimer(thrtimer_t *info);
void* OnTimer(void *info);
int SetTimer(thrtimer_t *info, int iID, int iTime);
int KillTimer(thrtimer_t *info, int iID);

#endif