#include <atomic>

class Spinlock {
public:
//	Spinlock() = default;
	Spinlock() {
		lock_.clear(memory_order_release);
	}
	Spinlock(const Spinlock&) = delete;
	Spinlock& operator= (const Spinlock&) = delete;
	void lock() {
		while (lock_.test_and_set(std::memory_order_acquire)) {
			//do nothiing
		}
				
	}
	void unlock() {
		lock_.clear(std::memory_order_release);
	}
	
	private:
		atomic_flag lock_;
};
