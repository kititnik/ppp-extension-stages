# Отчёт по заданию 1

Выбран вариант 13.
## Ход разработки:
1. Добавлены обобщение `OperationSystem` и его альтернативы(`LinuxOS`, `WindowsOS`).
2. Добавлен заголовок `os_in_out` и его реализация с обобщением `InputTag` для полиморфного ввода.
3. Добавлены параметрические функции `OSIn<OperationSystem* os>(FILE* file)` и `OSOut<OperationSystem* os>(FILE* file)` для ввода и вывода.
4. Добавлены функции `OSCreateByTag<InputTag* tag>(int k)`(создать OS из `InputTag` если она соотвествует номеру `k`) и `OSCreateAndIn(FILE* ifst)`(создать OS через `OSCreateByTag` и ввести данные для конкретной OS).
5. Добавлены альтернативы для `InputTag` для `Windows` и `Linux` в отдельных заголовках и модулях `windows_in_out` и `linux_in_out` с обработчиками параметрических функций.
6. Добавлен `main.c`