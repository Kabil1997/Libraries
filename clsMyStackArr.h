#pragma once
#include"clsMyQueueArr.h"
template <class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:
	void Push(T Item)
	{
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(Item);
	}
	T Top()
	{
		return clsMyQueueArr <T>::Front();

	}

	T Bottom()
	{
		return clsMyQueueArr <T>::Back();

	}
};

