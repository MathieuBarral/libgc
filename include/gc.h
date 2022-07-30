#ifndef GC_H
    #define GC_H

    #include <stdlib.h>

    // Garbage collector node structure
    typedef struct gc_s {
        void *ptr;
        struct gc_s *next;
    } gc_t;

    /**
     * @brief Get the garbage collector list head
     *
     * @return gc_t **
     */
    gc_t **get_gc_head(void);

    /**
     * @brief Allocate memory block and add reference in list
     *
     * @param size
     *
     * @return void *
     */
    void *gc_malloc(size_t size);

    /**
     * @brief Free specified memory block and remove it from list
     *
     * @param ptr
     *
     * @return none
     */
    void gc_free(void *ptr);

#endif