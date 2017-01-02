#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
	
void tv_add(struct timeval *tv, const struct timeval *a, const struct timeval *b)
{
	tv->tv_sec = a->tv_sec + b->tv_sec;
	tv->tv_usec = a->tv_usec + b->tv_usec;
	if (tv->tv_usec >= 1000000) {
		tv->tv_sec++;
		tv->tv_usec -= 1000000;
	}
}

void tv_sub(struct timeval *tv, const struct timeval *a, const struct timeval *b)
{
	tv->tv_sec = a->tv_sec - b->tv_sec;
	tv->tv_usec = a->tv_usec - b->tv_usec;
	if (((long) tv->tv_usec) < 0) {
		tv->tv_sec--;
		tv->tv_usec += 1000000;
	}
}

void tv_div(struct timeval *tv, const struct timeval *a, int n)
{
	tv->tv_usec = (a->tv_sec % n * 1000000 + a->tv_usec + n / 2) / n;
	tv->tv_sec = a->tv_sec / n + tv->tv_usec / 1000000;
	tv->tv_usec %= 1000000;
}

void tv_mul(struct timeval *tv, const struct timeval *a, int n)
{
	tv->tv_usec = a->tv_usec * n;
	tv->tv_sec = a->tv_sec * n + tv->tv_usec / 1000000;
	tv->tv_usec %= 1000000;
}

int test_tv_sub()
{
	struct timeval tv_begin;
	struct timeval tv_end;
	struct timeval tv_cost;

	gettimeofday(&tv_begin, NULL);
	usleep(20);
	gettimeofday(&tv_end, NULL);

	tv_sub(&tv_cost, &tv_end, &tv_begin);

	printf("%ld %ld\n", tv_cost.tv_sec, tv_cost.tv_usec);
	
	return 0;
}


int main()
{
	
	test_tv_sub();
	
	return 0;	
}
