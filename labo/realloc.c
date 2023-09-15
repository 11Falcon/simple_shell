#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void* _realloc(void* ptr, size_t new_size)
{
	if (new_size == 0)
	{
		free(ptr);
		return NULL;
	}
	if (ptr == NULL)
	{
		return malloc(new_size);
	}

    size_t old_size = malloc_usable_size(ptr);  // Get the old size of the memory block.

    if (old_size >= new_size) {
        return ptr;  // No need to reallocate if the old size is sufficient.
    }

    void* new_ptr = malloc(new_size);  // Allocate new memory.

    if (new_ptr) {
        // Use the brk system call to move the program break and extend the heap.
        if (brk(new_ptr + new_size) == 0) {
            memcpy(new_ptr, ptr, old_size);  // Copy data from old to new memory.
            free(ptr);  // Free the old memory.
            return new_ptr;  // Return the new memory block.
        } else {
            free(new_ptr);  // brk failed, free new memory.
        }
    }

    return NULL;  // Allocation failed, return NULL.
}
