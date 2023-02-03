#Copyright 2022 Freedom Veículos Elétricos LTDA.
#SPDX - License - Identifier : Apache - 2.0

list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR} / gpio)

    cmake_minimum_required(VERSION 3.20.0)

        find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE}) project(gpio_api)

            target_sources(app PRIVATE src / main.cpp)
