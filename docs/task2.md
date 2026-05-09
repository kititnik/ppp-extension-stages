# Отчёт по заданию 2

## Ход разработки:
1.  Добавлена альтернатива `macOS` для `OperationSystem` в новых файлах `mac_os.h` и `mac_os.c`.
2.  Добавлен заголовок `mac_in_out.h` и его реализация с альтернативой для `InputTag` для полиморфного ввода/вывода.
3.  В эти файлы добавлены параметрические функции `OSIn<OperationSystem.macOS* os>(FILE* file)` и `OSOut<OperationSystem.macOS* os>(FILE* file)` для ввода/вывода MacOS.
4.  В эти файлы добавлена функция `OSCreateByTag<InputTag.macOS* tag>(int k)` для создания альтернативы `macOS` по тегу.

Таким образом файлы из задания 1 не были затронуты.