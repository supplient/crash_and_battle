#include <iostream>
using std::cout;
using std::cin;

#include "back.h"

backgroundQueue bq;
backTimerQueue tq;
backMainQueue mq;
map m;

player* iPlayer = new player;

void proBackgroundEvent(backgroundEvent *);
void proTimerEvent(timerEvent*);
void proMainEvent(mainEvent*);

void proMoveEvent(moveEvent * p);

void proKeyboardEvent(keyboardEvent*);

int main()
{
	keyboardEvent* initE=new keyboardEvent('w');
	bq.push(static_cast<backgroundEvent*>(initE));

	while (bq.size() != 0)
	{
		backgroundEvent * p = bq.pop();
		proBackgroundEvent(p);
		delete p;
	}

	tq.countdown();
	while (tq.size() != 0)
	{
		timerEvent* p = tq.top();
		if (p->getTime() > 0)
			break;
		tq.pop();
		proTimerEvent(p);
		delete p;
	}

	while (mq.size() != 0)
	{
		mainEvent* p = mq.pop();
		proMainEvent(p);
		delete p;
	}

	return 0;
}

void proBackgroundEvent(backgroundEvent* p)
{
	switch (p->getType())
	{
	case KEYBOARD_EVENT:
		proKeyboardEvent(dynamic_cast<keyboardEvent*>(p));
		break;
	}
}

void proKeyboardEvent(keyboardEvent* p)
{
	pos op = iPlayer->getPos();
	pos np;
	moveTimerEvent* m;

	switch (p->getKey())
	{
	case 'w':
		np = pos(op.x, op.y - 1);
		m = new moveTimerEvent(1, iPlayer, np);
		tq.push(m);
		break;
	case 'a':
		np = pos(op.x - 1, op.y);
		m = new moveTimerEvent(1, iPlayer, np);
		tq.push(m);
		break;
	case 's':
		np = pos(op.x, op.y + 1);
		m = new moveTimerEvent(1, iPlayer, np);
		tq.push(m);
		break;
	case 'd':
		np = pos(op.x + 1, op.y);
		m = new moveTimerEvent(1, iPlayer, np);
		tq.push(m);
		break;
	}
}


void proTimerEvent(timerEvent * p)
{
	mainEvent* np = p->turnToMainEvent();
	mq.push(np);
}


void proMainEvent(mainEvent * p)
{
	switch (p->getType())
	{
	case MOVE_EVENT:
		proMoveEvent(dynamic_cast<moveEvent*>(p));
		break;
	}
}

void proMoveEvent(moveEvent* p)
{
	object* target = p->getTarget();
	pos op = target->getPos();
	pos np = p->getTo();
	
	m.remove(op, target);
	m.put(np, target);

	//prepare send update_event for front
	cout << "Complete~~" << std::endl;
	int sus;
	cin >> sus;
}