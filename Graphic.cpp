// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//
#include"Graphic.h"
using namespace std;
const int winH = 30, winW = 90;
const int msX = 40, msY = 20;

const COORD WinSize = { winW,winH };
CHAR_INFO buffer[winH*winW];

HANDLE hOut, hOut2,hIn;

char canvas[msY][msX] = { 'a' };

const COORD infoBoxSize = { 30,msY-3 };
const COORD mapOrigin = { 5,2 };
const COORD infoBoxOrigin = { 5 + msX + 10,2 };
const COORD msgBoxSize = { winW-4,5 };
const COORD msgBoxOrigin = { 1,msY + 3 };

vector<string> msglist;
int msgindex = 0;
#define K_DOWN VK_DOWN
#define K_UP VK_UP
#define K_LEFT VK_LEFT
#define K_RIGHT VK_RIGHT
#define K_QUIT VK_ESCAPE
#define K_MSGUP VK_UP
#define K_MSGDOWN VK_DOWN
int Init()
{
	int result=1;

	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = FALSE;
	cinfo.dwSize = 1;
	DWORD mode;
	SMALL_RECT rect = { 0,0,WinSize.X - 1,WinSize.Y - 1 };//窗口比缓冲区小至少1
    //设置标题
	SetConsoleTitle(L"Cash and Battle");
	//获取句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	//获取窗口模式
	GetConsoleMode(hIn, &mode);
	mode = mode&(~ENABLE_MOUSE_INPUT)&(~ENABLE_QUICK_EDIT_MODE)&(~ENABLE_ECHO_INPUT)&(~ENABLE_LINE_INPUT);
	//创建背景缓冲区
	hOut2 = CreateConsoleScreenBuffer(
		GENERIC_READ |           // read/write access 
		GENERIC_WRITE,
		FILE_SHARE_READ |
		FILE_SHARE_WRITE,        // shared 
		NULL,                    // default security attributes 
		CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
		NULL);
	//隐藏光标
	result=result&SetConsoleCursorInfo(hOut, &cinfo); 
	result = result & SetConsoleCursorInfo(hOut2, &cinfo);
	//调整缓冲区大小和窗口大小
	result = result & SetConsoleWindowInfo(hOut, 1, &rect);
	result = result & SetConsoleScreenBufferSize(hOut, WinSize);
	result = result & SetConsoleWindowInfo(hOut2, 1, &rect);
	result = result & SetConsoleScreenBufferSize(hOut2, WinSize);
	//调整窗口模式
	result = result & SetConsoleMode(hIn,mode);
	return result;
}
void Line(int start_x, int start_y, int length, int xoff=1,int yoff=0, wchar_t k=L'+')
{
	if (length < 0)abort();
	COORD Start = { (short)start_x,(short)start_y };
	wchar_t buffer[1];
	buffer[0] = k;
	DWORD num;
	int i = 0;
	for (;i<length;i++)
	{
		WriteConsoleOutputCharacter(hOut2, buffer, 1, Start, &num);
		Start.X += xoff;
		Start.Y += yoff;
	}
}
void DrawBox(int left, int top, int right, int bottom, wchar_t k = L'+')
{
	Line(left+1, top,right-left-1,1,0,'_');
	Line(left,top+1,bottom-top,0,1,'|');
	Line(right, bottom, right - left, -1, 0, '_');
	Line(right, bottom, bottom - top, 0, -1, '|');
}
void TextBox(const char* msg, int left, int top, int right, int bottom)
{
	SMALL_RECT region = { left,top,right,bottom };
	COORD origin = { 0,0 }, size = { right - left + 1,bottom - top + 1 };
	int i = 0, j = 0;
	for (; i < size.Y; i++)
		for (j = 0; j < size.X; j++)
		{
			buffer[i*(right - left + 1) + j].Char.AsciiChar = *msg != '\0' ? *msg : '_';
			buffer[i*(right - left + 1) + j].Attributes = FOREGROUND_INTENSITY;
			if (*msg != '\0')msg++;
			//todo:COLOR
		}
	WriteConsoleOutput(hOut2, buffer, size, origin, &region);
}
void TextLine(const char*msg, int left, int top,int range)
{
	DWORD num;
	COORD origin = { left,top };
	WriteConsoleOutputCharacterA(hOut2, msg, range,origin , &num);
}
void Rectangle(int left, int top, int right, int bottom, wchar_t k = L'+')
{
	Line(left, top, right - left + 1, 1, 0, k);
	Line(left, top + 1, bottom - top, 0, 1, k);
	Line(right, bottom, right - left, -1, 0, k);
	Line(right, bottom, bottom - top, 0, -1, k);
}
int Encode(char ch, int color)
{
	int result = 0;
	result &= ch;
	return ch;
}
void DrawMap(char** ppcbuf,int x,int y)
{
	char(*cbuf)[msX] = (char(*)[msX])ppcbuf;
	SMALL_RECT region = { x,y,x+msX-1,y+msY-1};
	COORD origin = { 0,0 }, size = { msX,msY };
	char c;
	int i = 0, j = 0;
	for (; i < msY; i++)
		for (j = 0; j < msX; j++)
		{
		   buffer[i*msX + j].Char.AsciiChar = cbuf[i][j];
		   buffer[i*msX + j].Attributes = FOREGROUND_INTENSITY;
			//todo:COLOR
		}
	WriteConsoleOutput(hOut2, buffer,size,origin,&region);
}
void PushMsg(string msg)
{
	msglist.push_back(msg);
	msgindex = msglist.size() - 1;
}
void DrawFrame()
{
	MapData* p = (MapData*)DataBox::GetInstance()->GetData();
	if (p == 0)abort();
	DrawMap(p->m_vecMap,mapOrigin.X,mapOrigin.Y);
	DrawBox(msgBoxOrigin.X, msgBoxOrigin.Y, msgBoxSize.X + msgBoxOrigin.X, msgBoxSize.Y + msgBoxOrigin.Y);
	DrawBox(infoBoxOrigin.X, infoBoxOrigin.Y, infoBoxSize.X + infoBoxOrigin.X, infoBoxSize.Y + infoBoxOrigin.Y);
	TextBox(msglist[msgindex].c_str(),msgBoxOrigin.X+1,msgBoxOrigin.Y+1,msgBoxSize.X-1+msgBoxOrigin.X, msgBoxSize.Y - 1 + msgBoxOrigin.Y);
	TextLine("     Hp         10/10", infoBoxOrigin.X + 1, infoBoxOrigin.Y + 1,infoBoxSize.X-2);
	char buffer[30];
	sprintf_s(buffer,30, "Msg: %d/%d", msgindex+1, msglist.size());
	TextLine(buffer, infoBoxOrigin.X + 1, infoBoxOrigin.Y + 2, infoBoxSize.X - 2);
}
void Flip()
{
	HANDLE temp = hOut2;
    hOut2=hOut;
	hOut = temp;
	FlushConsoleInputBuffer(hOut2);
	SetConsoleActiveScreenBuffer(hOut);
}
char KeyMsgProcess()
{
	static bool reset = false;
	char c = 0;
	bool bOut = false;
	DWORD  rlength;
	INPUT_RECORD record;
	while (!bOut)
	{
		//	WaitForSingleObject(hOut, INFINITE);

		ReadConsoleInput(hIn, &record, 1, &rlength);
		if (record.EventType == KEY_EVENT)
		{
			if (record.Event.KeyEvent.bKeyDown == 0)
			{
				reset = false;
			}
			if (record.Event.KeyEvent.bKeyDown && !reset)
			{
				switch (record.Event.KeyEvent.wVirtualKeyCode)
				{
				case VK_DOWN:case VK_UP:case VK_LEFT:case VK_RIGHT:case VK_ESCAPE:
					//todo
					reset = true;
					c = record.Event.KeyEvent.wVirtualKeyCode;
					bOut = true;
				//	PushMsg("Some Function Key is pushed down");
					break;
				default:
					c = record.Event.KeyEvent.uChar.AsciiChar;
					bOut = true;
					reset = true;
					PushMsg("Some Alphabet Key is pushed down");
					break;
				}
				if (c == K_MSGUP&&msgindex>0) {
					msgindex -= 1;
				}
				else if (c == K_MSGDOWN && msgindex < msglist.size() - 1) { msgindex += 1; }
			}
		}
	}
	return c;
}
int update()
{
	int i = 0;
	while(1)
	{
		DrawFrame();
		Flip();
		KeyMsgProcess();
	}
}

