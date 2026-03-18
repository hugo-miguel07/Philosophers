*This project has been created as part of the 42 curriculum by htavares.*

## Description

**Philosophers** is an implementation of the famous **Dining Philosophers Problem**, a classic synchronization and concurrency challenge in computer science. In this problem, a number of philosophers sit around a table with a bowl of spaghetti in the middle. Between each philosopher is a single fork. To eat, a philosopher needs to use both the left and right forks.

##### Goal:

The project demonstrates how to:
- Manage **multiple threads** safely using **mutexes** and **synchronization primitives**
- Prevent **deadlock** and **race conditions**
- Simulate realistic concurrent systems where resources must be shared fairly among competing processes
- Monitor and control thread lifecycle and state transitions

### Key Features

- **Thread-based simulation** of philosophers eating, thinking, and sleeping
- **Mutex protection** for shared resources (forks and table state)
- **State tracking** with logging of philosopher activities
- **Configurable parameters**: number of philosophers, time to die, time to eat, and time to sleep
- **Death detection** and simulation termination when any philosopher dies or all have eaten a set number of times
- **Precise timing** using system time functions

## Instructions

### Compilation

```bash
make
```

This will compile all source files and create the `philo` executable using the following options:
- `-Wall -Wextra -Werror`: All warnings treated as errors
- `-pthread`: POSIX threads library
- `-g`: Debugging symbols included

### Execution

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

**Parameters:**
- `number_of_philosophers`: Number of philosophers at the table (and number of forks)
- `time_to_die`: Time in milliseconds before a philosopher dies if they haven't eaten
- `time_to_eat`: Time in milliseconds it takes a philosopher to eat
- `time_to_sleep`: Time in milliseconds a philosopher sleeps after eating
- `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation ends when all philosophers have eaten this many times

**Examples:**

```bash
./philo 5 800 200 200
./philo 4 410 200 200 10
./philo 1 800 200 200
```

### Cleanup

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile from scratch
```

## Resources

### Classic References
- **Dining Philosophers Problem** - Dijkstra's synchronization problem (1965)
  - https://en.wikipedia.org/wiki/Dining_philosophers_problem
- **POSIX Threads Programming**
  - https://computing.llnl.gov/tutorials/pthreads/
- **Mutex and Thread Synchronization**
  - https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/
- **Deadlock Prevention and Avoidance**
  - https://www.geeksforgeeks.org/deadlock-prevention/

### AI Usage

AI assistance was utilized during this project for the following tasks:
- **Code structure and organization**: Suggestions for modular file organization and header file organization
- **Thread synchronization debugging**: Understanding mutex behavior and identifying potential race conditions
- **Algorithm optimization**: Reviewing deadlock prevention strategies
- **Memory management review**: Verifying proper allocation and deallocation of thread-related structures
- **Documentation**: Creating clear code comments and README documentation

## Project Structure

```
philosophers/
├── philosophers.c    # Main entry point and thread creation
├── philosophers.h    # Header file with data structures and constants
├── routine.c         # Philosopher routine (eat, sleep, think cycle)
├── monitoring.c      # Death detection and simulation monitoring
├── innits.c          # Initialization of data structures
├── finishsim.c       # Simulation cleanup
├── time.c            # Time-related utilities
├── utils.c           # General utility functions
├── prints.c          # Output and logging functions
├── Makefile          # Build configuration
└── README.md         # This file
```

## Notes

- The program terminates when a philosopher dies OR (if specified) after all philosophers have eaten the maximum number of times
- Precise timing is critical; use realistic parameter values to observe proper synchronization behavior
- The simulation timestamp starts from `0` at program launch
