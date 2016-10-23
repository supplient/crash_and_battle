#pragma once
#include "stdafx.h"
#include <windows.h>
#include<string>
#include<vector>
int init();
int update();
class DataBox;
enum DataType  { MAP_DATA };
class Data
{
public:
	friend class DataBox;
	DataType m_eType;
};
class MapData:public Data
{
public:
	char** m_vecMap;
};
class DataBox
{
public:
	static DataBox* GetInstance();
	void SendData(Data* pDa);
	Data* GetData();
private:
	static DataBox* m_pBox;
	std::vector<Data*> m_vecData;
};