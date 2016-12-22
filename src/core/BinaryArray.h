#pragma once
#include <string>
using namespace std;

class BinaryArray
{
public:
	void Init(int size)
	{
		m_size = size;
		m_values = new unsigned int[size / sizeof(int) + 1];
		memset(m_values, 0, sizeof(m_values));
	}

	void Destroy()
	{
		if (m_values != NULL)
		{
			delete[] m_values;
			m_values = NULL;
		}
	}

	bool Get(int idx)
	{
		if (idx >= m_size)
			return false;

		int h = idx / m_size;
		int l = idx % m_size;

		int v = m_values[h] >> l & 0x01;
		return v ? true : false;
	}

	void Set(int idx, bool v)
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

	int Count()
	{
		return m_size;
	}

private:
	unsigned int*	m_values;
	int				m_size;
};