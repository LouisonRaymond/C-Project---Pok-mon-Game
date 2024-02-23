cmake_minimum_required(VERSION 3.26)
project(SupPoke_Game C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(SupPoke_Game
        include/fight.h
        include/game.h
        include/shop.h
        include/struct.h
        include/supcenter.h
        src/fight.c
        src/game.c
        src/shop.c
        src/supcenter.c
        main.c)
