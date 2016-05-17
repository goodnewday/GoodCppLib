#include "spin_lock.h"

int main()
{

	Spinlock S;

	S.lock();
	S.lock();
}
