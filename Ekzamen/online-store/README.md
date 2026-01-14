# Система управления интернет-магазином
## Экзаменационная работа по информатике 2025

##  Содержание
1. [Цель проекта](#цель-проекта)
2. [Функциональность](#функциональность)
3. [Технологии](#технологии)
4. [Установка и запуск](#установка-и-запуск)


##  Цель проекта
Разработка полнофункциональной системы интернет-магазина на C++ с использованием:
- Объектно-ориентированного программирования (ООП)
- Умных указателей для управления памятью
- PostgreSQL для хранения данных
- Транзакций для обеспечения целостности данных
- Системы ролей и прав доступа

## Функциональность

### Роли пользователей
| Роль | Возможности |
|------|-------------|
| **Администратор** | Полный доступ: управление товарами, заказами, пользователями, просмотр отчётов |
| **Менеджер** | Обработка заказов, управление складом, утверждение заказов |
| **Покупатель** | Создание заказов, оплата, отслеживание статусов, возврат товаров |

### Основные функции
 **Управление товарами**
- Добавление/редактирование/удаление товаров
- Контроль остатков на складе
- История изменений цен

 **Работа с заказами**
- Полный цикл: создание → оплата → выполнение → доставка
- Отмена и возврат заказов
- Автоматический расчёт стоимости
- Несколько способов оплаты (карта, электронный кошелёк, СБП)

 **Безопасность и аудит**
- Хеширование паролей
- Автоматическое логирование всех действий
- Проверка прав доступа
- История изменений статусов заказов

 **Отчётность**
- Генерация CSV-отчётов
- Аналитика продаж
- Журнал аудита действий пользователей

##  Технологии

| Компонент | Технология |
|-----------|------------|
| Язык программирования | C++17 |
| База данных | PostgreSQL 12+ |
| Библиотека для БД | libpqxx 7.0+ |
| Система сборки | CMake 3.10+ |
| Управление памятью | Умные указатели (unique_ptr, shared_ptr) |
| Алгоритмы | STL (find_if, copy_if, accumulate) |

### Структура базы данных
**Основные таблицы:**
1. `users` - пользователи системы
2. `products` - товары магазина
3. `orders` - заказы
4. `order_items` - элементы заказов
5. `order_status_history` - история статусов
6. `audit_log` - журнал аудита

## Установка и запуск

### Предварительные требования
```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install postgresql postgresql-contrib libpqxx-dev cmake g++

# macOS (Homebrew)
brew install postgresql libpqxx cmake

# Запуск PostgreSQL (если не запущен)
sudo systemctl start postgresql  # Linux
brew services start postgresql   # macOS

# Создание базы данных и пользователя
sudo -u postgres psql -c "CREATE DATABASE online_store;"
sudo -u postgres psql -c "CREATE USER store_admin WITH PASSWORD 'secure_password123';"
sudo -u postgres psql -c "GRANT ALL PRIVILEGES ON DATABASE online_store TO store_admin;"

# Запуск PostgreSQL (если не запущен)
sudo systemctl start postgresql  # Linux
brew services start postgresql   # macOS

# Создание базы данных и пользователя
sudo -u postgres psql -c "CREATE DATABASE online_store;"
sudo -u postgres psql -c "CREATE USER store_admin WITH PASSWORD 'secure_password123';"
sudo -u postgres psql -c "GRANT ALL PRIVILEGES ON DATABASE online_store TO store_admin;"

# Переход в директорию с SQL скриптами
cd sql/

# Создание таблиц и структуры
psql -h localhost -U store_admin -d online_store -f tables.sql
psql -h localhost -U store_admin -d online_store -f functions.sql
psql -h localhost -U store_admin -d online_store -f triggers.sql
psql -h localhost -U store_admin -d online_store -f procedures.sql
psql -h localhost -U store_admin -d online_store -f sample_data.sql
