#pragma once

#include "../include/Timer.h"
#include <stdio.h>
#include <unistd.h>

class Test
{
private:
	int cnt1;
	int cnt2;
	int cnt3;

public:
	thrtimer_t timer;
	
public:
	void Process();
	void Cnt1();
	void Cnt2();
	void Cnt3();
	
public:
	Test();
	~Test();
};