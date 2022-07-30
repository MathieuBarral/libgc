#include "gc.h"

gc_t **get_gc_head(void)
{
    static gc_t *head = NULL;

    return (&head);
}

void destroy_gc(void)
{
    gc_t *next = NULL;

    for (gc_t **tmp = get_gc_head(); (*tmp); (*tmp) = next) {
        next = (*tmp)->next;
        free((*tmp)->ptr);
        free(*tmp);
    }
}

void __attribute__((destructor))call_on_exit(void)
{
    destroy_gc();
}

void add_ptr_to_gc(gc_t **g, void **ptr)
{
    gc_t *tmp = *g;
    gc_t *node = malloc(sizeof(gc_t));

    node->ptr = ptr;
    node->next = NULL;
    if (tmp == NULL) {
        (*g) = node;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = node;
}

void *gc_malloc(size_t size)
{
    gc_t **g = get_gc_head();
    void *ptr_tmp = malloc(size);

    add_ptr_to_gc(g, ptr_tmp);
    return (ptr_tmp);
}