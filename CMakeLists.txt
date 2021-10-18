cmake_minimum_required(VERSION 3.20)
project(AviCompany)

set(CMAKE_CXX_STANDARD 14)

add_executable(AviCompany main.cpp Implementation/Person.cpp Implementation/Person.h Implementation/Ticket.cpp Implementation/Ticket.h Implementation/Client.cpp Implementation/Client.h Implementation/Plaine.cpp Implementation/Plaine.h)