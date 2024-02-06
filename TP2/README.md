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

## Question A
Lorsque on exécute le programme plusieurs fois, on rend compte que la valeur finale du compteur ne correspond pas à la valeur attendue. Par exemple, lorsque on lance l'exécution avec nLoops égal à $10^8$ pour $2$ taches, on attend à obtenir un compteur final égal à $2x10^8$. Par contre, on obtient une valeur différente.
Cela est dû au fait que les deux tâches n'accèdent pas à la même variable "counter" et ne la modifient pas de manière atomique. Par conséquent, une tâche peut accéder à la variable au moment où l'autre tâche la met à jour, ce qui rend la valeur obtenue par la première tâche obsolète.
La solution consiste donc à protéger l'accès au compteur avec un mutex, de sorte que l'accès et la modification de cette variable soient des opérations atomiques.

## Question B

Lorsque on lance l'exécution avec nLoops égal à $10^8$ pour $2$ tâches sans protection du mutex (unprotected), on obtient le même résultat que dans la Question A: un compteur final avec une valeur incorrecte.
En revanche, si on exécute la même chose avec une protection par mutex (protected), les opérations d'accès et d'écriture du compteur sont atomiques et donc la valeur finale du compteur est correcte ($2x10^8$). Dans ce cas, la tache doit prendre et vendre le mutex à chaque fois qu'elle accède au compteur et le modifie, ce qui rend le processus plus lent et avec un temps d'exécution beaucoup plus long.
