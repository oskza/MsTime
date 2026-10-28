# MsTime

A lightweight C++11 library for non-blocking time-based events using caller-supplied millisecond timestamps. Compatible with Arduino and other C++ environments, without Arduino dependencies.

## Features

- **`Timer`** – tracks time intervals with optional repeats
- **`CallbackTimer`** – extends **`Timer`** to run scheduled callbacks (`onStart`, `onElapsed`, `onStop`)
- **`StopWatch`** – measures elapsed time with `start`, `stop` and `lap` functions
