#pragma once

class backState
{
public:
	~backState()
	{
	}

	static void setRunningState(bool s) { running = s; }
	static bool getRunningState() { return running; }

private:
	static bool running;


	backState()
	{
	}
};
