# Graph Ranker

[![license: MIT][license-img]][license-link]
![latest commit](https://img.shields.io/github/last-commit/Silemo/api-2021-manfredi)


## About

Graph Ranker is the final project of **"API-Algorithms and Principles of Informatics"**, course of **"Computer Science & Engineering"** held at Politecnico di Milano (2020/2021).

**Professor** Matteo Pradella

**Tutor** Valentina Deda

**Final Score:** 30/30 cum laude

## Specifications

The objective of the project is the implementation of a **full-C11** program which is capable of managing
a ranking system of graphs. The program keeps tracks and saves the best *k* graphs (*k* is an input parameter) 
and once the *TopK* command read outputs the index of all the best graphs the program kept track of.

### Inputs

The program gets two parameters once the program is started (first line of the input_file):
* *d*  : the number of nodes of each graph
* *k*  : the length of the ranking the program needs to keep track of

*WARNING* :warning: : *n* and *k* can be represented as 32-bit integers.

The program also gets a sequence of two commands between:
* *AggiungiGrafo*  : A command followed by a matrix of d*d dimension which asks the program to add the 
                     graph represented by the matrix to be evaluated (and if it's the case, added in the ranking)
* *TopK*  : A command which asks the program to consider each graph from the beginning of the file to that 
            *TopK* command and print the index of the best *K* graphs based on the rules below.

The rules are specified in the specs file you can find [here][specs-link].

### Graph Example

The following text will represent the graph in the image below:
```
AggiungiGrafo
3,7,42
0,7,2
7,4,3
```

![i1][graph-img]

### Execution Example

The following text taken as input_file should output the one below:

#### Input
```
3,2
AggiungiGrafo
0,4,3
0,2,0
2,0,0
AggiungiGrafo
0,0,2
7,0,4
0,1,0
AggiungiGrafo
3,1,8
0,0,5
0,9,0
TopK
```

#### Output
```
0 1
```
or
```
1 0
```

## Test Cases

The program is evaluated by using three sequences of tests.

### UpTo18

| #   |      Outcome       |        Output         | Execution time | Memory used |
|:----|:------------------:|:---------------------:|:--------------:|:------------|
| 1   | :white_check_mark: | The output is correct |    1,320 s     | 256 KiB     |
| 2   | :white_check_mark: | The output is correct |    1,908 s     | 1,45 MiB    |
| 3   | :white_check_mark: | The output is correct |    1,882 s     | 1,36 MiB    |
| 4   | :white_check_mark: | The output is correct |    1,823 s     | 1,44 MiB    |
| 5   | :white_check_mark: | The output is correct |    1,590 s     | 6,10 MiB    |
| 6   | :white_check_mark:  | The output is correct |    1,889 s     | 75,4 MiB    |

### UpTo30

| #   |      Outcome       |        Output         | Execution time | Memory used |
|:----|:------------------:|:---------------------:|:--------------:|:------------|
| 1   | :white_check_mark: | The output is correct |    1,294 s     | 356 KiB     |
| 2   | :white_check_mark: | The output is correct |    1,898 s     | 1,48 MiB    |
| 3   | :white_check_mark: | The output is correct |    1,895 s     | 1,40 MiB    |
| 4   | :white_check_mark: | The output is correct |    1,821 s     | 1,48 MiB    |
| 5   | :white_check_mark: | The output is correct |    1,584 s     | 6,10 MiB    |
| 6   | :white_check_mark:  | The output is correct |    1,900 s     | 75,4 MiB    |

### CumLaude

| #   |      Outcome       |        Output         | Execution time | Memory used |
|:----|:------------------:|:---------------------:|:--------------:|:------------|
| 1   | :white_check_mark: | The output is correct |    1,295 s     | 128 KiB     |

### Compilation Output

This is the time and memory space the test server has taken to compile. 
The time and space occupied is nearly identical for each set of tests.

| #   |      Outcome       | Compilation time | Memory used |
|:----|:------------------:|:----------------:|:------------|
| 1   | :white_check_mark: |     0,260 s      | 14.5 MiB    |

## Software used

**CLion** - main IDE

**GitKraken** - github

**OneDrive** - file sharing

### Compiling

**GCC**

**GDB**

### Visualising usage

**Valgrind**

**Callgrind**

**Massif-Visualizer**

<!Links of the document-->
[license-img]: https://img.shields.io/badge/license-GPL--3.0-blue
[license-link]: https://github.com/Silemo/api-2021-manfredi/blob/master/LICENSE
[specs-link]: https://github.com/Silemo/api-2021-manfredi/tree/main/specs
[graph-img]: https://github.com/Silemo/api-2021-manfredi/blob/main/github/graph_example.png

