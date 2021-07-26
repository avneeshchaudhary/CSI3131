# Module 10 - Mass Storage Structure (Chapter 11)

## Hard Disk Drive (HDD)
* Structure: Each disk **platter** has a flat circular shape. A **read–write head** “flies” just above each surface of every platter. The heads are attached to a **disk arm** that moves all the heads as a unit. The surface of a platter is logically divided into circular **tracks**, which are subdivided into **sectors**. The set of tracks at a given arm position make up a **cylinder**. </br>
    ![hdd-struct](./picture/hdd-struct.png)

## HDD Scheduling
1. Whenever a process needsI/O to or from the drive, it issues a system call to the operating system. The request specifies several pieces of information:
    * Whether this operation is input or output
    * The open file handle indicating the file to operate on
    * What the memory address for the transfer is
    * The amount of data to transfer
2. Parameters to consider:
    * **Seek time (Positioning time)**: the time taken for the disk drive to position itself on the desired cylinder.
    * **Rotation latency time**: the time taken by the read-write head which is on the correct cylinder to position yourself on the desired sector.
    * **Reading time**: time needed to read the track

### FCFS Scheduling
The simplest form of disk scheduling is, of course, the first-come, first-served (FCFS) algorithm (or FIFO).
![hdd-fcfs](./picture/hdd-fcfs.png)

### SCAN Scheduling