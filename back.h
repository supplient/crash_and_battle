#pragma once
#include "backgroundQueue.h"
#include "backTimerQueue.h"
#include "backMainQueue.h"
#include "elements.h"
#include "events.h"
#include "map.h"


void backProcess();


void proBackgroundEvent(backgroundEvent *);
void proTimerEvent(timerEvent*);
void proMainEvent(mainEvent*);

void proMoveEvent(moveEvent * p);

void proKeyboardEvent(keyboardEvent*);