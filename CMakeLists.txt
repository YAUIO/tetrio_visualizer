cmake_minimum_required(VERSION 3.28.1)
project(TETR_IO_Visulizer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/)
include_directories(imports/)
include_directories(structures/)
include_directories(render/)

add_executable(TETR_IO_Visulizer main.cpp
        Utils.cpp
        structures/Ttr.h
        structures/Player.h
        structures/Board.h
        structures/Handling.h
        structures/Minoskin.h
        structures/Options.h
        structures/Clears.h
        structures/Falling.h
        structures/Stats.h
        structures/tData.h
        structures/IntData.h
        structures/IgeData.h
        structures/Killer.h
        structures/Time.h
        structures/Garbage.h
        structures/Finesse.h
        structures/Controlling.h
        structures/Data.h
        structures/tEvent.h
        structures/Aggregatestats.h
        structures/Hold.h
        structures/Points.h
        structures/PointsExtra.h
        structures/AvgTracking.h
        structures/ExtraAvgTracking.h
        structures/Replay.h
        structures/Source.h
        structures/Objective.h
        structures/Enemy.h
        structures/Target.h
        structures/BoardV.h
        structures/ConstantsOverrides.h
        Utils.h
        render/Render.cpp
        render/Render.h
)
