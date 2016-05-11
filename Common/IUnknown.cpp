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
	}

	return m_refcount;
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