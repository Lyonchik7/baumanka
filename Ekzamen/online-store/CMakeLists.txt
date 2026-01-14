cmake_minimum_required(VERSION 3.12)
project(OnlineStore
    VERSION 1.0.0
    DESCRIPTION "Система интернет-магазина на C++/PostgreSQL"
    LANGUAGES CXX
)

# C++17 с поддержкой всех функций
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Опции проекта
option(BUILD_TESTS "Собрать тесты" OFF)
option(ENABLE_SANITIZERS "Включить санитайзеры (Debug)" OFF)

# Политики CMake
cmake_policy(SET CMP0077 NEW)  # Целевые ссылки

# Пути выходных файлов
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Поиск зависимостей
find_package(PostgreSQL REQUIRED)

find_path(PQXX_INCLUDE_DIR NAMES pqxx/pqxx
    PATHS /usr/include /usr/local/include /opt/local/include)
find_library(PQXX_LIBRARY NAMES pqxx
    PATHS /usr/lib /usr/local/lib /opt/local/lib)

if(NOT PQXX_INCLUDE_DIR OR NOT PQXX_LIBRARY)
    message(FATAL_ERROR "libpqxx не найден. Установите: sudo apt-get install libpqxx-dev")
endif()

message(STATUS "Найдено: PostgreSQL ${PostgreSQL_VERSION}")
message(STATUS "Найдено: libpqxx в ${PQXX_LIBRARY}")

# Исходные файлы
set(SOURCES
    src/main.cpp
    src/DatabaseConnection.cpp
    src/User.cpp
    src/Admin.cpp
    src/Manager.cpp
    src/Customer.cpp
    src/Order.cpp
    src/OrderItem.cpp
    src/Product.cpp
    src/Payment.cpp
    src/PaymentStrategy.cpp
    src/CardPayment.cpp
    src/WalletPayment.cpp
    src/SBPPayment.cpp
)

# Заголовочные файлы
set(HEADERS
    include/DatabaseConnection.h
    include/User.h
    include/Admin.h
    include/Manager.h
    include/Customer.h
    include/Order.h
    include/OrderItem.h
    include/Product.h
    include/Payment.h
    include/PaymentStrategy.h
    include/CardPayment.h
    include/WalletPayment.h
    include/SBPPayment.h
)

# Основное приложение
add_executable(online_store ${SOURCES} ${HEADERS})

# Включение директорий
target_include_directories(online_store PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${PQXX_INCLUDE_DIR}
    ${PostgreSQL_INCLUDE_DIRS}
)

# Подключение библиотек
target_link_libraries(online_store PRIVATE
    ${PQXX_LIBRARY}
    ${PostgreSQL_LIBRARIES}
)

# Настройка свойств цели
set_target_properties(online_store PROPERTIES
    OUTPUT_NAME "online_store"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Флаги компилятора
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(online_store PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
    )
    
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(online_store PRIVATE -g -O0)
        message(STATUS "Режим: Debug")
        
        if(ENABLE_SANITIZERS)
            target_compile_options(online_store PRIVATE
                -fsanitize=address,undefined
                -fno-omit-frame-pointer
            )
            target_link_options(online_store PRIVATE
                -fsanitize=address,undefined
            )
            message(STATUS "Санитайзеры: включены")
        endif()
    else()
        target_compile_options(online_store PRIVATE -O2)
        message(STATUS "Режим: Release")
    endif()
    
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(online_store PRIVATE /W4 /WX)
endif()

# Создание служебных директорий
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/sql)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/reports)

# Копирование SQL файлов
if(EXISTS ${CMAKE_SOURCE_DIR}/sql)
    file(COPY ${CMAKE_SOURCE_DIR}/sql/ DESTINATION ${CMAKE_BINARY_DIR}/sql)
endif()

# Опциональные тесты
if(BUILD_TESTS)
    enable_testing()
    message(STATUS "Тесты: включены")
    
    # Можно добавить GoogleTest или Catch2
    # add_subdirectory(tests)
endif()

# Инсталляция
install(TARGETS online_store
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION bin
)

install(DIRECTORY sql/ DESTINATION share/${PROJECT_NAME}/sql)
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})

# Информация
message(STATUS "")
message(STATUS "  ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "  Компилятор: ${CMAKE_CXX_COMPILER}")
message(STATUS "  C++ стандарт: ${CMAKE_CXX_STANDARD}")
message(STATUS "Для сборки:")
message(STATUS "  mkdir build && cd build")
message(STATUS "  cmake .. [-DBUILD_TESTS=ON]")
message(STATUS "  make -j4")
message(STATUS "")
message(STATUS "Для запуска:")
message(STATUS "  ./bin/online_store")
