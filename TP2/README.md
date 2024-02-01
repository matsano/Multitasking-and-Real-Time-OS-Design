# TP2
Multitasking and Real Time OS Design Course

##  Compilation

### 1) Create a folder called "build" and access it

```bash
mkdir build
cd build
```

### 2) To compile the project, run the following commands:

```bash
cmake ..
make
```

## Execution

After compiling with the commands above, 2 executables will be generated in the "build" folder. Each executable represents a question of the TP. The commands to run each of them are:

- Question A
```bash
./MainA 100000000 2
```

- Question B
```bash
./MainB 100000000 2 protected
./MainB 100000000 2 unprotected
```

It is worth noting that in Question A and Question B, it is necessary to declare the nLoops variable and the number of tasks. In Question B, if the third argument is "protected", the increment of counter must be protected by a mutex. If it is "unprotected", it must be done without protection.
