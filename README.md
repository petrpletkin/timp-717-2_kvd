## timp-717-1_kvd


# 717-2_kvd-1-1.c

Написать программу, печатающую в stdout фразу "Hello, World!" на отдельной строке.
Входные данные: - .
Выходные данные: string.


# 717-2_kvd-1-2.c
Написать программу, принимающую на вход два числа, разделённые пробелом, и суммирующую их. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647.

Входные данные: два числа int.
Выходные данные: int.


# 717-2_kvd-1-3.c

Написать программу, принимающую на вход числа x и y, разделённые пробелом, и вычисляющую x в степени y. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647. Реализовывать возведение в степень через цикл/рекурсию не допускается.

Входные данные:два числа int.
Выходные данные: int.


# 717-2_kvd-2-1.c

Вариант №5

На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖 | ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение среднего арифметического от всех 𝑥𝑖 .

Входные данные: int.
Выходные данные: int.


# 717-2_kvd-2-2.c

Вариант №19

На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖 | ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение ∏︁𝑛 𝑖=1 𝑥𝑖 (произведение от 1 до n по xi)

Входные данные: число unsignet int, и n чисел int
Выходные данные: int.


# 717-2_kvd-3-1.c

Необходимо реализовать функции для работы с односвязным списком.

Программа создает односвязный список и выполняет следующие функции:
* Инициализация пустого списка;
* Удаление всех элементов из списка;
* Проверка на пустоту списка;
* Поиск элемента по значению, вернуть NULL если элемент не найден;
* Поиск элемента по значению;
* Вставка значения в конец списка, и возвращает ноль если успешно;
* Вставка значения в начало списка, и возвращает ноль если успешно;
* Вставка элемента после указанного узла, и возвращает ноль если успешно;
* Удаление первого элемента из списка с указанным значением, и возвращает 0 если успешно;
* Вывод всех значений из списка в прямом порядке, через пробел, после окончания вывода перейти на новую строку;

Используя реализованные функции реализовать программу которая:
1. считать количество элементов;
2. создать пустой список, считать n элементов a , |a | ≤ 2147483647 и занести их в список;
3. вывести содержимое списка используя функцию print;
4. считать k1, k2, k3, |k | ≤ 2147483647 и вывести ‘1’ если в списке существует элемент с таким значением. ‘0’ если нет, перейти на новую строку.
5. считать m, |m| ≤ 2147483647 и вставить его в конец списка;
6. вывести содержимое списка используя функцию print;
7. считать t, |t| ≤ 2147483647 и вставить его в начало списка;
8. вывести содержимое списка используя функцию print;
9. считать j, 0 < j ≤ 2147483647 и x, |x| ≤ 2147483647 и вставить значение x после j-ого элемента списка;
10. вывести содержимое списка используя функцию print;
11. считать z, |z| ≤ 2147483647 и удалить первый элемент хранящий значение z из списка;
12. вывести содержимое списка используя функцию print;
13. очистить список.

Входные данные: int.
Выходные данные: int.


# 717-2_kvd-3-2.c

Необходимо реализовать функции для работы с двусвязным списком.

Программа создает двусвязный список и выполняет следующие функции:
* Инициализация пустого списка;
* Удаление всех элементов из списка;
* Проверка на пустоту списка;
* Gоиск элемента по значению, вернуть NULL если элемент не найден;
* Вставка значения в конец списка, и возвращает ноль если успешно;
* Вставка значения в начало списка, и возвращает ноль если успешно;
* Вставка элемента после указанного узла, и возвращает ноль если успешно;
* Удаление первого элемента из списка с указанным значением, и возвращает 0 если успешно;
* Вывод всех значений из списка в прямом порядке, через пробел, после окончания вывода перейти на новую строку;
* Вывод всех значений из списка в обратном порядке, через пробел, после окончания вывода перейти на новую строку;

Используя реализованные функции реализовать программу которая:
1. считать количество элементов;
2. создать пустой список, считать n элементов a , |a | ≤ 2147483647 и занести их в список;
3. вывести содержимое списка используя функцию print;
4. считать k1, k2, k3, k | ≤ 2147483647 и вывести ‘1’ если в списке существует элемент с таким значением. ‘0’ если нет, перейти на новую строку;
5. считать m, |m| ≤ 2147483647 и вставить его в конец списка;
6. вывести содержимое списка используя функцию print_invers;
7. считать t, |t| ≤ 2147483647 и вставить его в начало списка;
8. вывести содержимое списка используя функцию print;
9. считать j, 0 < j ≤ 2147483647 и x, |x| ≤ 2147483647 и вставить значение x после j-ого элемента списка;
10. вывести содержимое списка используя функцию print_invers;
11. считать u, 0 < u ≤ 2147483647 и y, |y| ≤ 2147483647 и вставить значение y перед u-ым элементом списка;
12. вывести содержимое списка используя функцию print;
13. считать z, |z| ≤ 2147483647 и удалить первый элемент хранящий значение z из списка;
14. вывести содержимое списка используя функцию print_invers;
15. считать r, |r| ≤ 2147483647 и удалить последний элемент хранящий значение r из списка;
16. вывести содержимое списка используя функцию print;
17. очистить список.

Входные данные: int.
Выходные данные: int.


# 717-2_kvd-4-1.c

Необходимо реализовать структуры данных и функции для работы с бинарным деревом поиска.

Программа создает структуру данных и функции для работы с бинарным деревом:\

* Инициализация пустого дерева;
* Удаление всех элементов из дерева;
* Вставка значения в дерево;
* Удаление элемента из дерева;
* Удаление минимального элемента из поддерева, корнем которого является n; 
* Выполнить правое вращение поддерева, корнем которого является n; 
* Выполнить левое вращение поддерева, корнем которого является n;
* Вывести все значения из поддерева корнем которого является n по уровнем, начиная с корня.;
* Вывести все значения дерева t;

Используя реализованные функции реализовать программу которая:
1. создать пустое дерево, считать 4 элементов a, |a| ≤ 2147483647 и занести их в дерево;
2. вывести дерево используя функцию printTree;
3. считать 3 элементов a , |a | ≤ 2147483647 и занести их в дерево;
4. вывести дерево используя функцию printTree;
5. считать m , |m | ≤ 2147483647 и найти элемент с заданным значением в дереве. вывести через пробел значение предка и потомков найденного элемента. если элемент не найден, вывести "_", если нет значений предка или потомков вывести ’’ вместо таких значений.
6. считать m , |m | ≤ 2147483647 и найти элемент с заданным значением в дереве. вывести через пробел значение предка и потомков найденного элемента. если элемент не найден, вывести ‘-’, если нет значений предка или потомков вывести ‘_’ вместо таких значений.
7. считать m , |m | ≤ 2147483647 и удалить из дерева элемент с заданным значением;
8. вывести деревео используя printTree;
9. выполнять левый поворот дерева относительно корня, пока это возможно;
10. вывести дерево используя команду printTree;
11. выполнять правый поворот дерева относительно корня, пока это возможно;
12. вывести дерево используя команду printTree;
13. вывести на экран количество элементов в дереве;
14. очистить дерево;
15. вывести дерево на экран используя printTree.

Входные данные: n чисел типа int.
Выходные данные: int (измененная структура дерева)

