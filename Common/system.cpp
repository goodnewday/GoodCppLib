#include <stdio.h>
#include <string.h>

unsigned int  GetNumProcessors()
{   
	int  readlen = 0;
    char cpuBuffer[8192] = "";
    FILE    *cpuFile = ::fopen( "/proc/cpuinfo", "r" );
    if (cpuFile)
    {   readlen = ::fread(cpuBuffer, sizeof(char),  sizeof(cpuBuffer), cpuFile);
        ::fclose(cpuFile);
    }
    
	char *search_pos = NULL;
    unsigned int numCPUs = 0;
	
	search_pos = cpuBuffer;
    
    while(search_pos = strstr(search_pos, "processor") ) 
    {
          numCPUs ++; 
		  search_pos++;		  
    }
    
    if (numCPUs == 0)
        numCPUs = 1;
        
    return numCPUs;

}

int main ()
{
	unsigned int cpu_num =  GetNumProcessors();
	printf("%u\n", cpu_num);
	
	return 0;
}

