cmake_minimum_required(VERSION 3.10)
project(MatrixProject)

# Устанавливаем стандарт языка C++
set(CMAKE_CXX_STANDARD 11)

# Добавляем исполняемый файл main.cpp
add_executable(MatrixClass /home/kavo/matr/matrix_class/src/matrix_class.cpp)

target_include_directories(MatrixClass PUBLIC /home/kavo/matr/matrix_class/include)

# Добавляем директорию, содержащую исходные файлы
target_sources(MatrixClass PRIVATE /home/kavo/matr/matrix_class/src)
