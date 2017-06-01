# CPE_2016_Corewar

### Prerequisites

What things you need to install the corewar

```
GlibC , GCC and make
```

### Installing

There is a Makefile in the repository

```
make
```

### USAGE

```
./asm file_name[.s]
```

### Example of .s

```
.name "zork"
.comment " just a basic living prog"
l2:
sti r1, %:live, %1
and r1 ,%0 , r1
live: live %1
zjmp %: live
```

## Authors

* **Quentin Sonnefraud** -*Parsing in linked list to facilitate writing of instructions* - [Quentin Sonnefraud](https://github.com/Vatoth)
* **Nikola Tomic** - *Wrting Instruction in bytes code* - [Pujomir](https://github.com/Pujomir)

Made with love at Epitech Paris in 2017
