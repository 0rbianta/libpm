cmake_minimum_required(VERSION 3.10.2)



project("rootpowermanager")


add_library(pm
             SHARED
        libpm.c)

find_library(log-lib
              log )


target_link_libraries(
                        pm

                       ${log-lib} )