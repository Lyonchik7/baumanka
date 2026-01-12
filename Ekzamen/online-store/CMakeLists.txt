cmake_minimum_required(VERSION 3.10)
project(OnlineStore)

set(CMAKE_CXX_STANDARD 17)

# Найти библиотеки PostgreSQL
find_package(PostgreSQL REQUIRED)
find_package(libpqxx REQUIRED)

# Добавить директорию include
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${PostgreSQL_INCLUDE_DIRS})

# Список исходных файлов
set(SOURCES
    src/main.cpp
    src/DatabaseConnection.cpp
    src/User.cpp
    src/Product.cpp
    src/Order.cpp
    src/Payment.cpp
)

# Создать исполняемый файл
add_executable(online_store ${SOURCES})

# Подключить библиотеки
target_link_libraries(online_store
    ${PostgreSQL_LIBRARIES}
    libpqxx::pqxx
)

# Включить предупреждения
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(online_store PRIVATE -Wall -Wextra)
endif()
