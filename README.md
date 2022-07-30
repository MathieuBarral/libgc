# libgc

A library for garbage collection in C.

The implemented functions are :

```c
void *gc_malloc(size_t size);
void gc_free(void *ptr);
```

## Build

To build the project you can use the following command :

```
make                build the project
make re             clean and rebuild the project
make clean          clean object files
make fclean         clean object files and shared library
```

The result of the build is and shared library file named `libgc.so`.