# TP4
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

After compiling with the commands above, executables will be generated in the "build" folder. Each executable represents a question of the TP. The commands to run each of them are:

- Question A
```bash
./MainA 100000000 2
```

- Question B
```bash
./MainB 100000000 2
```

- Question C
```bash
./MainC 3 3 3
```

It is worth noting that in Questions A and B, it is necessary to declare the nLoops variable and the number of tasks.
In Question C, it is necessary to declare: the number of producer tasks (nProd), the number of consumer tasks (nCons) and the maximum number of tokens (maxTokens), in this order.

## Question A
Lorsque on exécute le programme plusieurs fois, on rend compte que la valeur finale du compteur ne correspond pas à la valeur attendue. Par exemple, lorsque on lance l'exécution avec nLoops égal à $10^8$ pour $2$ taches, on attend à obtenir un compteur final égal à $2x10^8$. Par contre, on obtient une valeur différente.
Cela est dû au fait que les deux tâches n'accèdent pas à la même variable "counter" et ne la modifient pas de manière atomique. Par conséquent, une tâche peut accéder à la variable au moment où l'autre tâche la met à jour, ce qui rend la valeur obtenue par la première tâche obsolète.
La solution consiste donc à protéger l'accès au compteur avec un mutex, de sorte que l'accès et la modification de cette variable soient des opérations atomiques.

## Question B

Lorsque on lance l'exécution avec nLoops égal à $10^8$ pour $2$ tâches avec une protection par mutex, les opérations d'accès et d'écriture du compteur sont atomiques et donc la valeur finale du compteur est correcte ($2x10^8$). Dans ce cas, la tache doit prendre et vendre le mutex à chaque fois qu'elle accède au compteur et le modifie, ce qui rend le processus plus lent et avec un temps d'exécution beaucoup plus long.

## Question C

On analyse 3 cas différents:

- Situation 1

```bash
./MainC 3 3 3
```

Dans cette situation, on teste si tous les jetons créés ont été bien consommés.

Dans ce cas, 3 tâches productrices donneront chacune 1 jeton au sémaphore. Comme il dispose d'un nombre maximum de jetons égal à 3, le sémaphore recevra les 3 jetons et sera saturé. Ensuite, chacune des 3 tâches consommatrices prendra 1 jeton, laissant le sémaphore avec 0 jeton à la fin.


- Situation 2

```bash
./MainC 3 2 2
```

Dans cette situation, on teste le cas où un tâche productrice essaie de donner 1 jeton à un sémaphore qui est saturé.

Dans ce cas, 3 tâches productrices essaieront de donner 1 jeton chacune au sémaphore, mais le sémaphore est saturé avec 2 jetons. Par conséquent, seules 2 tâches productrices pourront donner 1 jeton au sémaphore, qui ne contiendra finalement que 2 jetons. Ensuite, chacune des deux tâches consommatrices prendra 1 jeton, laissant le sémaphore avec 0 jeton à la fin.


- Situation 3

```bash
./MainC 2 3 2
```

Dans cette situation, on teste le cas où une tâche consommatrice essaie de prendre 1 jeton d'un sémaphore vide.

Dans ce cas, 2 tâches productrices essaieront de donner chacune 1 jeton au sémaphore, ce qui fera que le sémaphore aura deux jetons et sera saturé. Ensuite, chacune des 3 tâches consommatrices tentera d'obtenir 1 jeton. Cependant, il n'y a que 2 jetons dans le sémaphore. Par conséquent, seules 2 tâches de consommation pourront récupérer 1 jeton, tandis qu'une tâche de consommation sera bloquée. Cette tâche ne sera débloquée que lorsqu'un jeton sera disponible au sémaphore.
