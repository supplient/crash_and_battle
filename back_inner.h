#pragma once
#include "backTimerQueue.h"
#include "backMainQueue.h"
#include "elements.h"
#include "events.h"
#include "map.h"
#include "backState.h"

//front files
#include "Data.h"

bool backInit();
void backProcess();

//back_inner process
void proBackgroundEvent(backgroundEvent *);
void proTimerEvent(timerEvent*);
void proMainEvent(mainEvent*);

void proMoveEvent(moveEvent * p);

void proKeyboardEvent(keyboardEvent*);


//port with front
bool updateMap();