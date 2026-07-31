## Symbol Frequency Table

| Symbol | Frequency |
| ------ | --------- |
| A      | 0.2       |
| B      | 0.1       |
| C      | 0.1       |
| D      | 0.15      |
| E      | 0.45      |

## Shannon-Fano algorithm

- **Step 1:** Sort the table in descending order.
  | E    | A   | D    | B   | C   |
  | ---- | --- | ---- | --- | --- |
  | 0.45 | 0.2 | 0.15 | 0.1 | 0.1 |
- **Step 2:** Partition into E(0.45) and ADBC(0.55). Assign `0` to E(0) and `1` to ADBC(1)
- **Step 3:** Partition ADBC(0.55) into AD(0.35) and BC(0.2). Append `0` to AD(10) and `1` BC(11)
- **Step 4:** Partition AD(10) into A(0.2) and D(0.15). Append `0` to A(100) and `1` to D(101)
- **Step 5:** Partition BC(11) into B(0.1) and C(0.1). Append `0` to B(110) and `1` to C(111)

### Code table

| Symbol | Code |
| ------ | ---- |
| A      | 100  |
| B      | 110  |
| C      | 111  |
| D      | 101  |
| E      | 0    |

### Expected Length Calculation

| Symbol | Frequency | Bit Length | Probability | Expected Length |
| ------ | --------- | ---------- | ----------- | --------------- |
| E      | 0.45      | 1          | 0.45        | 0.45            |
| A      | 0.2       | 3          | 0.2         | 0.6             |
| D      | 0.15      | 3          | 0.15        | 0.45            |
| B      | 0.1       | 3          | 0.1         | 0.3             |
| C      | 0.1       | 3          | 0.1         | 0.3             |

Expected Length = 2.1 bits/symbol

## Huffman Algorithm

- **Step 1:** Sort in ascending order
    | B   | C   | D    | A   | E    |
    | --- | --- | ---- | --- | ---- |
    | 0.1 | 0.1 | 0.15 | 0.2 | 0.45 |
- **Step 2:** Initialize minimum heap.
    | Queue | Frequency |
    | ----- | --------- |
    | B     | 0.1       |
    | C     | 0.1       |
    | D     | 0.15      |
    | A     | 0.2       |
    | E     | 0.45      |
- **Step 3:** Get two minimum elements from heap. [0.1(B), 0.1(C)]. Sum frequency is 0.2. Add 0.2 into heap.
    | Queue | Frequency |
    | ----- | --------- |
    | D     | 0.15      |
    | A     | 0.2       |
    | BC    | 0.2       |
    | E     | 0.45      |
- **Step 4:** Get two minimum elements from heap. [0.15(D), 0.2(A)]. Sum frequency is 0.35. Add 0.35 into heap.
    | Queue | Frequency |
    | ----- | --------- |
    | BC    | 0.2       |
    | DA    | 0.35      |
    | E     | 0.45      |
- **Step 5:** Get two minimum elements from heap. [0.2(BC), 0.35(DA)]. Sum frequency is 0.55. Add 0.55 into heap.
    | Queue | Frequency |
    | ----- | --------- |
    | E     | 0.45      |
    | BCDA  | 0.55      |
- **Step 6:** Sum two final frequency [0.45(E), 0.55(BCDA)]. Sum frequency is 1. Add into heap.
    | Queue | Frequency |
    | ----- | --------- |
    | EBCDA | 1         |

### Code table

| Symbol | Code |
| ------ | ---- |
| A      | 111  |
| B      | 100  |
| C      | 101  |
| D      | 110  |
| E      | 0    |

### Expected Length Calculation

| Symbol | Frequency | Bit Length | Probability | Expected Length |
| ------ | --------- | ---------- | ----------- | --------------- |
| E      | 0.45      | 1          | 0.45        | 0.45            |
| A      | 0.2       | 3          | 0.2         | 0.6             |
| D      | 0.15      | 3          | 0.15        | 0.45            |
| B      | 0.1       | 3          | 0.1         | 0.3             |
| C      | 0.1       | 3          | 0.1         | 0.3             |

Expected Length = 2.1 bits/symbol