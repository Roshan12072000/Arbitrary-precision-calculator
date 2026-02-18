# 🔢 Arbitrary Precision Calculator (APC) in C

## 📌 About the Project

The **Arbitrary Precision Calculator (APC)** is a command-line based application developed in C to perform arithmetic operations on very large numbers.

Unlike standard data types that are limited by size, this calculator can handle numbers of arbitrary length by processing digits individually using dynamic data structures.

The project demonstrates implementation of big integer arithmetic using linked lists along with multi-file compilation using a Makefile.

---

## ⚙️ How It Works

The program accepts operands and operators as command-line arguments.

Digits of large numbers are stored and processed individually, enabling arithmetic operations beyond built-in data type limits.

### Execution Format

```
./calc.exe <operand1> <operator> <operand2>
```


## ➕ Supported Operations

* Addition (+)
* Subtraction (-)
* Multiplication (*)
* Division (/)

---

## 🖥️ Sample Execution

### Valid Input

```
$ ./calc.exe 1234 + 5689

  1 2 3 4
  5 6 8 9
  6 9 2 3
```


### Large Number Operation

```
$ ./calc.exe 12345511111111111111111111111111111111 + 222222222222222222222222222222222222222

Result computed successfully for large operands.
```

This demonstrates arbitrary precision capability.

---

### Invalid Input Handling

```
$ ./calc.exe 1 2 3 '+' 4 5 6
Invalid Input :-(
Enter valid operator such as '+', '-', '*', '/'
```


## 🧰 Build System (Makefile)

This project uses a **Makefile** for automated compilation.

### Compile Project

```
make
```

### Run Executable

```
./calc.exe <operand1> <operator> <operand2>
```

### Clean Build Files

```
make clean
```


## 📂 Project Structure

```
APC/
│
├── main.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── store.c
├── apc.h
├── Makefile
├── README.md
```

---

## 🛠️ Technologies Used

* C Programming
* Linked Lists
* Dynamic Memory Allocation
* Pointer Manipulation
* Makefile Build Automation

---

## 🎯 Applications

* Cryptography calculations
* Financial systems
* Scientific computing
* Big integer processing
* Compiler arithmetic modules

---

## 📚 Learning Outcomes

* Linked list data representation
* Big number arithmetic
* Carry and borrow handling
* Multi-file project compilation
* Build automation using Makefile

---

## 👨‍💻 Author

**Roshan Jameer**
GitHub: https://github.com/Roshan12072000

---

## 📜 Note

This project was developed for educational purposes to understand arbitrary precision arithmetic and large number computation techniques.
