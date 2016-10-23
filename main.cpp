#include "Graphic.h"
#include "back.h"
int main()
{
	//front init
	Init();
	//back init
	backInit();

	//hallo info
	PushMsg("Use w,a,s,d Keys to move.");

	while (true)
	{
		update();
		backProcess();

		if (!backState::getRunningState())//quit
			break;
	}

	system("pause");
	return 0;
}