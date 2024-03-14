# TP5
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

After compiling with the commands above, executable will be generated in the "build" folder. The executable represents a question of the TP. The commands to run each of them are:

- Question C
```bash
sudo ./Main false
sudo ./Main true
```

It is worth noting that it is necessary to declare if the code will execute the priority inversion. If the argument is "true", the priority inversion will be executed. If the argument is "false", the priority inversion will not be executed.
