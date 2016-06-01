/*****************************************************************
Copyright (c) 2016 Jung-Min, Shin (tranxlate3@gmail.com)

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*****************************************************************/

#include "../include/Timer.h"



int SetTimer(thrtimer_t *info, int iID, int iTime)
{
	int iRet = 0;

	//printf("id:%d, Time:%d\n",iID, iTime);
	if(info->isUse[iID]!=0) return -1;
	info->isUse[iID] = 1;
	info->iLoopTime[iID] = iTime;
	info->iID[iID] = iID;
	iRet = pthread_create(&info->threads[iID], 0, &OnTimer, (void *)&info->iID[iID]);
	if(iRet!=0) return -1;
	//printf("id:%x, g_iLoopTime:%x\n",&g_iID[iID], &g_iLoopTime[iID]);	
	return 0;
}

int KillTimer(thrtimer_t *info, int iID)
{
	if(info->isUse[iID]!=0)
		pthread_cancel(info->threads[iID]);
	info->isUse[iID] = 0;
	info->iLoopTime[iID] = 0;
	info->iID[iID] = 0;
	return 0;
}

/*//////////////////////////////////////////////////////////////////////////////
// 개발자 : sjm
// 날짜 : 2015.03.12
// 명칭 : Thread Timer 생성자
// 기능 : .
//////////////////////////////////////////////////////////////////////////////*/

void CreateTimer(thrtimer_t *info)
{
	int i=0;
	
	for(i=0;i<MAX_TIMER;i++)
	{
		info->isUse[i] = 0;
		info->iLoopTime[i] = 0;
		info->iID[i] = 0;
	}
}

/*//////////////////////////////////////////////////////////////////////////////
// 개발자 : sjm
// 날짜 : 2015.03.12
// 명칭 : Thread Timer 소멸자
// 기능 : .
//////////////////////////////////////////////////////////////////////////////*/

void DestroyTimer(thrtimer_t *info)
{
	int i=0;
	
	for(i=0;i<MAX_TIMER;i++)
	{
		KillTimer(info, i);
	}
}
