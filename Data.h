#pragma once
class DataBox;
enum DataType { MAP_DATA };


class Data
{
public:
	friend class DataBox;
	DataType m_eType;
};


class MapData :public Data
{
public:
	char** m_vecMap;
	MapData(char** _m_vecMap = nullptr) :m_vecMap(_m_vecMap)
	{
	}
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
