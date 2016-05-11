

//----------------------------------------lock--
#include <mutex>

int test_lock()
{
	std::mutex  lock_bus;
	
	lock_bus.lock();
	
	lock_bus.unlock();
}

//------------------------------------------

int main ()
{
	test_lock();
	
	return 0;
}