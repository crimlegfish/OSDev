#pragma once

// eventually more states will be added (such as zombie states) but that is when I implement
// fork() and communication between parent and child processes (wait, waitpid). For now that is not an issue
#define RUNNING 0
#define READY 1
#define BLOCKED 2

typedef struct context {
        uint32_t edi;
        uint32_t esi;
        uint32_t ebx;
        uint32_t ebp;
        uint32_t eip;
} context_t;

typedef struct process {
        uint32_t pid;           // process id
        char name[16];          // process name
        uint32_t size;          // size of process in bytes
        uint32_t state;         // one of the three states: running, ready, or blocked
        pdirectory* pgdir;      // page directory for this process
        char* kstack;           // kernel stack for this process
        process_t* parent;      // parent process (for forks and stuff.. In the future!!)
        inode_t* directory;     // current working directory
        open_file_t* ofile[16]; // 16 open files max, keeps track of all open files for process
        context_t* context;     // for scheduler (in the future!!)
} process_t;
