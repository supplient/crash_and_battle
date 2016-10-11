#include "stdafx.h"
DataBox* DataBox::m_pBox = 0;
DataBox* DataBox::GetInstance()
{
	if (m_pBox == 0)m_pBox = new DataBox;
	return m_pBox;
}
void DataBox::SendData(Data*pD) 
{
	m_vecData.push_back(pD);
}
Data* DataBox::GetData()
{
	if (m_vecData.size() == 0)return 0;
	Data * pre=m_vecData.back();
	m_vecData.pop_back();
	return pre;
}