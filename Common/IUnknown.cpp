#include"IUnKnown.h"

IUnKnown::IUnKnown()
{
	refcount = 0;
}
IUnKnown::~IUnKnown()
{
	
}

int32_t IUnKnown::AddRef()
{
	refcount++;

	return refcount;
}

int32_t IUnKnown::Release()
{
	if (--refcount == 0)
	{	
		delete this;		
	}

	return refcount;
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