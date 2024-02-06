# TP3
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
./MainA
```

- Question B
```bash
./MainB
```

## Question B
La classe Timer étant abstraite, elle ne peut pas être instanciée. En fait, elle est utilisée comme superclasse pour d'autres classes, telles que la classe CountDown. Comme l'opération "call_callback" est la même pour toutes les sous-classes, elle est implémentée par la fonction abstraite Timer et n'a pas besoin d'être visible par les autres classes. Ainsi, cette opération est privée. L'opération "callback", en revanche, n'est pas implémentée par la classe Timer, car chacune de ses sous-classes possède sa propre implémentation. Par conséquent, comme cette opération doit être accessible aux sous-classes, elle a une visibilité protégée.
Les autres opérations doivent être visibles par toutes les classes, car elles seront appelées dans la Main.

La méthode statique "call_callback" est utilisée comme une fonction de rappel (callback) lorsqu'un signal SIGRTMIN est reçu. Cette méthode statique permet au système de rediriger les signaux vers une fonction membre d'une instance particulière de la classe Timer. Étant donné que call_callback() est une méthode statique, elle n'a pas d'instance associée. Cependant, elle utilise les informations fournies par le système d'exploitation via la structure siginfo_t, qui inclut un pointeur vers Timer.

En utilisant ce pointeur, la méthode "call_callback" peut accéder à la fonction de rappel "callback". Une fois que "call_callback" a accès à l'instance de une sub-classe de Timer, elle peut appeler la fonction de rappel "callback" de cette instance spécifique.
Cela permet d'exécuter le code spécifique au traitement de l'événement de temporisation pour cette instance particulière.

En résumé, la méthode "call_callback" agit comme un pont entre la réception d'un signal système (SIGRTMIN) et l'exécution de la fonction de rappel "callback" associée à une instance spécifique de la sub-classe de Timer.

Dans la classe de base Timer, les méthodes qui doivent être modifiées ou implémentées dans les classes dérivées doivent être déclarées comme virtuelles. Par exemple, comme on veut implémenter distinctement la méthode "callback" pour chaque classe dérivée telle que CountDown, alors "callback" doit être déclarée comme virtuelle.
