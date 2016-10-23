#include "Graphic.h"
#include "back.h"
int main()
{
	Init();
	//test
	PushMsg("Use Up,Down,Left,Right Keys to move and  Esc to quit");
	//back init
	backInit();


	update();
	system("pause");
	return 0;
}