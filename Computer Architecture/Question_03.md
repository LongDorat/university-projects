# Big-endian and Little-endian

# Differences

- Big-endian stores the most significant byte at the smallest memory address.
- Little-endian stores the least significant byte at the smallest memory address.

## Examples

Say you want to store a 32-bit integer 0x12345678 in 8-bit memory.
- Big-endian:

| 0x1000 | 0x1001 | 0x1002 | 0x1003 |
| ------ | ------ | ------ | ------ |
| 0x12   | 0x34   | 0x56   | 0x78   |

- Little-endian:

| 0x1000 | 0x1001 | 0x1002 | 0x1003 |
| ------ | ------ | ------ | ------ |
| 0x78   | 0x56   | 0x34   | 0x12   |

# MIPS choice

MIPS designer **chose big-endian format** according to the "Computer Organization And Design: The Hardware/Software Interface 6th Edition" by David A. Patterson and John L. Hennessy.