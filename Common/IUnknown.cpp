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

//����:
//1.���ؽӿ�ָ��ʱ����AddRef
//2.�ӿ���������Release
//3.��ֵ�����AddRef.



//g++ *cpp *.h -std=c++11


int main()
{
	IUnKnown *IUN = new IUnKnown;
	
	IUN->AddRef();
	
	IUN->Release();
	return 0;
}