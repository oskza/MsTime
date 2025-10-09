# MsTime

A lightweight Arduino library for non-blocking time-based events using `millis()`.

Features:

- **`Timer`** – track time intervals with optional repeat
- **`TaskTimer`** – extends **`Timer`** to run scheduled callbacks (`onStart`, `exec`, `onReset`)
- **`StopWatch`** – measure elapsed time with `start`, `stop` and `lap` functions
