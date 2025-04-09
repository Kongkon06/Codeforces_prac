
#include <stdio.h>
#include <stdlib.h>

void custom_free(void **pp) {
    *pp = (void *)((char *)*pp - sizeof(size_t)); // Move back
    size_t size = *(size_t *)*pp; // Read stored size
    printf("Freeing %zu bytes\n", size);
    free(*pp); // Free the actual memory
}

int main() {
    void *ptr = malloc(100 + sizeof(size_t)); // Allocate extra space
    *(size_t *)ptr = 100; // Store size at the beginning
    void *user_ptr = (char *)ptr + sizeof(size_t); // User's pointer

    custom_free(&user_ptr); // Free it correctly
    return 0;
}
