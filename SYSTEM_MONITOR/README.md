# System Monitor

## Overview
System Monitor is a C++ application that provides real-time monitoring of system resources and performance metrics. It helps you track CPU usage, memory consumption, process information, and other vital system statistics.

## Features
- Monitor CPU usage in real-time
- Track memory and RAM consumption
- Display active processes and their resource usage
- Monitor system temperature (if available)
- Generate system performance reports
- Display network statistics

## Requirements
- C++11 or later
- Standard C++ libraries
- Platform-specific system libraries (Windows, Linux, macOS)

## Compilation
To compile the System Monitor project:

```bash
g++ -std=c++11 -o system_monitor main.cpp
```

On Linux, you may need additional libraries:
```bash
g++ -std=c++11 -o system_monitor main.cpp -lm
```

## Usage
Run the compiled executable:

```bash
./system_monitor [options]
```

## Supported Metrics
- **CPU Usage**: Real-time processor utilization
- **Memory Usage**: RAM allocation and usage
- **Process Information**: Running processes and their details
- **System Uptime**: Time since last restart
- **Disk I/O**: Read/write statistics

## Platform Support
- Linux
- Windows
- macOS

## Notes
- Some features may require administrator/root privileges for full system access
- Real-time monitoring may impact system performance slightly
- Refresh rate can be adjusted based on system capabilities

## License
This project is part of the Cpp-Projects repository.

## Author
calti23
