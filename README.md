# Operating System Concepts Laboratory

This repository contains the lab implementations for the **Operating System Concepts Laboratory** course (Semester 3) at **Dr. Vishwanath Karad MIT World Peace University (MIT-WPU), Pune**.

---

## 📑 Syllabus & Laboratory Exercises Overview

| Exp No. | Experiment Title | Description | Files |
| :---: | :--- | :--- | :--- |
| **01** | **Linux Commands & Shell Scripting** | Menu-driven arithmetic operations, conditional logic, and looping constructs in Bash. | `arithmetic_op.sh`, `case_statement.sh`, `for_loop.sh`, `while_loop.sh`, `positive_negative.sh`, `voting_check.sh`, `variables_demo.sh` |
| **02** | **Process Management (Process Control)** | Process creation with `fork()`. Parent sorts ascending, child sorts descending; Orphan process; Zombie process. | `asc_desc_sort.c`, `orphan_process.c`, `zombie_process.c`, `demos/*` |
| **03** | **Process Management (CPU Scheduling)** | Simulation of First-Come, First-Served (FCFS), Shortest Remaining Time First (SRTF Preemptive), and SJF Non-preemptive scheduling. | `fcfs.c`, `srtf_preemptive.c`, `sjf_non_preemptive.c` |
| **04** | **Process Management (IPC)** | Inter-Process Communication using Unnamed Pipes and Shared Memory (System V IPC). | `pipe_ipc.c`, `shared_memory_ipc.c` |
| **05** | **Process Synchronization (Deadlocks)** | Banker's Algorithm for deadlock avoidance and Resource-Request Algorithm. | `bankers_algorithm.c`, `resource_request_algorithm.c` |
| **06** | **Process Synchronization (Semaphores)** | Classical synchronization problems: Readers-Writers and Producer-Consumer using semaphores and mutexes. | `reader_writer.c`, `producer_consumer.c` |
| **07** | **Memory Management (Page Replacement)** | Page replacement algorithms simulation: First-In-First-Out (FIFO) and Least Recently Used (LRU). | `fifo_page_replacement.c`, `lru_page_replacement.c` |

---

## 📂 Directory Structure

```text
OS_Lab/
├── Experiment-01_Shell_Scripting/
│   ├── arithmetic_op.sh          # Menu-driven calculator (+, -, *, /)
│   ├── case_statement.sh         # Case statement example
│   ├── for_loop.sh               # For loop summation
│   ├── while_loop.sh             # While loop multiplication table
│   ├── positive_negative.sh      # Number sign check
│   ├── voting_check.sh           # Age eligibility check
│   └── variables_demo.sh         # Shell variables and input
│
├── Experiment-02_Process_Control/
│   ├── asc_desc_sort.c           # Parent sorts ascending, child sorts descending
│   ├── orphan_process.c          # Orphan process demonstration
│   ├── zombie_process.c          # Zombie process demonstration
│   └── demos/
│       ├── basic_fork.c          # Elementary fork() call
│       ├── fork_child_parent.c   # Branching by PID
│       ├── fork_variable_sharing.c # Memory copy demonstration
│       └── fork_wait.c           # Synchronization with wait()
│
├── Experiment-03_CPU_Scheduling/
│   ├── fcfs.c                    # First Come First Serve (Non-preemptive)
│   ├── srtf_preemptive.c         # Shortest Remaining Time First (Preemptive)
│   └── sjf_non_preemptive.c      # Shortest Job First (Non-preemptive)
│
├── Experiment-04_Inter_Process_Communication/
│   ├── pipe_ipc.c                # Unnamed pipe communication between parent & child
│   └── shared_memory_ipc.c       # Shared memory segment IPC (shmget/shmat)
│
├── Experiment-05_Deadlock_Avoidance/
│   ├── bankers_algorithm.c       # Banker's safety state determination
│   └── resource_request_algorithm.c # Additional resource request feasibility check
│
├── Experiment-06_Process_Synchronization/
│   ├── reader_writer.c           # Readers-Writers problem using POSIX semaphores
│   └── producer_consumer.c       # Bounded-buffer Producer-Consumer problem
│
├── Experiment-07_Page_Replacement/
│   ├── fifo_page_replacement.c   # FIFO page replacement algorithm
│   └── lru_page_replacement.c    # LRU page replacement algorithm
│
└── README.md
```

---

## 🛠️ Compilation & Execution Instructions

### Prerequisites
- GCC / Clang compiler
- Bash shell
- POSIX-compliant environment (Linux or macOS)

---

### Experiment 1: Shell Scripting
Make the scripts executable and run:
```bash
cd Experiment-01_Shell_Scripting
chmod +x arithmetic_op.sh
./arithmetic_op.sh
```

---

### Experiment 2: Process Control
Compile and execute using GCC:
```bash
cd Experiment-02_Process_Control

# 2a. Ascending / Descending sort with fork()
gcc asc_desc_sort.c -o asc_desc_sort
./asc_desc_sort

# 2b. Orphan Process
gcc orphan_process.c -o orphan_process
./orphan_process

# 2c. Zombie Process
gcc zombie_process.c -o zombie_process
./zombie_process
```

---

### Experiment 3: CPU Scheduling
```bash
cd Experiment-03_CPU_Scheduling

# FCFS
gcc fcfs.c -o fcfs
./fcfs

# SRTF (Preemptive)
gcc srtf_preemptive.c -o srtf_preemptive
./srtf_preemptive

# SJF (Non-preemptive)
gcc sjf_non_preemptive.c -o sjf_non_preemptive
./sjf_non_preemptive
```

---

### Experiment 4: Inter-Process Communication (IPC)
```bash
cd Experiment-04_Inter_Process_Communication

# Pipe IPC
gcc pipe_ipc.c -o pipe_ipc
./pipe_ipc

# Shared Memory IPC
gcc shared_memory_ipc.c -o shared_memory_ipc
./shared_memory_ipc
```

---

### Experiment 5: Deadlock Avoidance (Banker's Algorithm)
```bash
cd Experiment-05_Deadlock_Avoidance

# Banker's Algorithm
gcc bankers_algorithm.c -o bankers_algorithm
./bankers_algorithm

# Resource Request Algorithm
gcc resource_request_algorithm.c -o resource_request_algorithm
./resource_request_algorithm
```

---

### Experiment 6: Process Synchronization
For multithreaded programs with POSIX threads and semaphores, link with `-pthread`:
```bash
cd Experiment-06_Process_Synchronization

# Readers-Writers Problem
gcc reader_writer.c -o reader_writer -pthread
./reader_writer

# Producer-Consumer Problem
gcc producer_consumer.c -o producer_consumer -pthread
./producer_consumer
```

---

### Experiment 7: Page Replacement Algorithms
```bash
cd Experiment-07_Page_Replacement

# FIFO Page Replacement
gcc fifo_page_replacement.c -o fifo_page_replacement
./fifo_page_replacement

# LRU Page Replacement
gcc lru_page_replacement.c -o lru_page_replacement
./lru_page_replacement
```

---

## 📜 References
- *Operating System Concepts* by Abraham Silberschatz, Peter Baer Galvin, Greg Gagne
- *Operating Systems: Internals and Design Principles* by William Stallings
