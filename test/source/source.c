#include "../../source.h"
#include "../../../convert/fd/source.h"
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    assert (argc == 2);
    
    window_unsigned_char contents = {0};
    fd_source fd_source = fd_source_init (STDIN_FILENO, &contents);

    vluint_result result;

    if (!vluint_read_source(&result, &fd_source.source, atoi(argv[1])))
    {
	printf ("An error occurred\n");
	abort();
    }
    
    printf("%llu\n", result);

    return 0;
}
