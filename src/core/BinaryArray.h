#pragma once
#include <string>
using namespace std;

class BinaryArray
{
public:
	void Init(int size);

	void Destroy();

	bool Get(int idx);

	void Set(int idx, bool v);

	int Count();

private:
	uint32*			m_values;
	int				m_size;
};