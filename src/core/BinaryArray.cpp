#include "typedef.h"
#include "BinaryArray.h"

void BinaryArray::Init(int size)
{
	m_size = size;
	m_values = new uint32[size / sizeof(int) + 1];
	memset(m_values, 0, sizeof(m_values));
}

void BinaryArray::Destroy()
{
	if (m_values != NULL)
	{
		delete[] m_values;
		m_values = NULL;
	}
}

bool BinaryArray::Get(int idx)
{
	if (idx >= m_size)
		return false;

	int h = idx / m_size;
	int l = idx % m_size;

	int v = m_values[h] >> l & 0x01;
	return v ? true : false;
}

void BinaryArray::Set(int idx, bool v)
{
	if (idx >= m_size)
		return;

	int h = idx / m_size;
	int l = idx % m_size;

	if (v)
	{
		m_values[h] = m_values[h] | (0x01 << l);
	}
	else
	{
		m_values[h] = m_values[h] & ~(0x01 << l);
	}
}

int BinaryArray::Count()
{
	return m_size;
}