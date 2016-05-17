#include"IUnKnown.h"

IUnKnown::IUnKnown()
{
	m_refcount = 0;
}
IUnKnown::~IUnKnown()
{
	
}

int32_t IUnKnown::AddRef()
{
	m_refcount++;

	return m_refcount;
}

int32_t IUnKnown::Release()
{
	if (--m_refcount == 0)
	{	
		delete this;
		return 0;  //the obj have delete, don't use m_refcount
	}

	return m_refcount;
}


//规则:
//1.返回接口指针时调用AddRef
//2.接口用完后调用Release
//3.赋值后调用AddRef.



//g++ *cpp *.h -std=c++11


int main()
{
	IUnKnown *IUN = new IUnKnown;
	
	IUN->AddRef();
	
	IUN->Release();
	return 0;
}
