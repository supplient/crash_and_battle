#include "back.h"

backgroundQueue* bq = backgroundQueue::getInstance();
backTimerQueue* tq = backTimerQueue::getInstance();
backMainQueue* mq = backMainQueue::getInstance();
map m;

player* iPlayer = player::getInstance();

static bool hasUpdateMap = false;

bool backInit()
{
	backState::setRunningState(true);//backState init

	return updateMap();
}

void backProcess()
{
	hasUpdateMap = false;

	while (bq->size() != 0)
	{
		backgroundEvent * p = bq->pop();
		proBackgroundEvent(p);
		delete p;
	}

	if (!backState::getRunningState())
		return;

	tq->countdown();
	while (tq->size() != 0)
	{
		timerEvent* p = tq->top();
		if (p->getTime() > 0)
			break;
		tq->pop();
		proTimerEvent(p);
		delete p;
	}

	while (mq->size() != 0)
	{
		mainEvent* p = mq->pop();
		proMainEvent(p);
		delete p;
	}

	if (!hasUpdateMap)
		updateMap();
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
		tq->push(m);
		break;
	case 'a':
		np = pos(op.x - 1, op.y);
		m = new moveTimerEvent(1, iPlayer, np);
		tq->push(m);
		break;
	case 's':
		np = pos(op.x, op.y + 1);
		m = new moveTimerEvent(1, iPlayer, np);
		tq->push(m);
		break;
	case 'd':
		np = pos(op.x + 1, op.y);
		m = new moveTimerEvent(1, iPlayer, np);
		tq->push(m);
		break;
	case 'q':
		backState::setRunningState(false);
		break;
	}
}


void proTimerEvent(timerEvent * p)
{
	mainEvent* np = p->turnToMainEvent();
	mq->push(np);
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

	if (!m.canMove(op, np))
		return;

	target->setPos(np);
	m.remove(op, target);
	m.put(np, target);
	
	updateMap();
}

bool updateMap()
{
	MapData* md = new MapData(m.getPaintingMap());
	DataBox* db = DataBox::GetInstance();
	db->SendData(md);
	hasUpdateMap = true;
	return true;
}