#include <atomic>

class IUnKnown
{
	public:
		IUnKnown();
		~IUnKnown();
		int32_t  AddRef();
		int32_t  Release();
		
	private:
		std::atomic<int32_t>  m_refcount;

};