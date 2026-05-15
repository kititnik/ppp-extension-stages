# Отчёт по заданию 6

## Ход разработки:
1. Добавлен новый модуль `container_combination_info_out.c` для обработки комбинаций типов `OperationSystem` внутри контейнера.
2. Реализована обобщённая функция `combination_info` с перегрузками для всех возможных пар типов `LinuxOS` и `WindowsOS`.
3. В `main.c` вызов стандартного вывода заменён на `container_combination_info_out`.