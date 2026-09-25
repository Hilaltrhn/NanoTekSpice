# NanoTekSpice

A digital electronics simulator written in C++.

It reads a circuit description file (`.nts`), builds the circuit from its components and links, and lets you set inputs and simulate it tick by tick from an interactive shell.

## Build

```bash
make
```

## Usage

```bash
./nanotekspice circuit.nts
```

### Shell commands

| Command         | Description                                  |
|-----------------|----------------------------------------------|
| `input=value`   | Set an input (`0`, `1` or `U` for undefined) |
| `simulate`      | Run one tick                                 |
| `display`       | Show the current tick, inputs and outputs    |
| `loop`          | Simulate continuously until `Ctrl+C`         |
| `exit`          | Quit                                         |

## Circuit file example

```
.chipsets:
input a
input b
4081 and
output s

.links:
a:1 and:1
b:1 and:2
and:3 s:1
```

## Components

- Special: `input`, `output`, `clock`, `true`, `false`
- Elementary gates: AND, OR, XOR, NOT, NAND, NOR
- 40xx chips (4001, 4011, 4030, 4069, 4071, 4081, ...)
