# [LEARN C++](https://www.learncpp.com/)


## 5.1 — Operator precedence and associativity
**Use parentheses to make it clear how a non-trivial expression should evaluate (even if they are technically unnecessary).**
```cpp
x = ((y || z) && w); // instead of this
x = (y || z) && w;   // it's okay to do this

```

## 5.4 — Increment/decrement operators, and side effects

**Strongly favor the prefix version of the increment and decrement operators, as they are generally more performant, and you’re less likely to run into strange issues with them.**


**So when should you use the conditional operator?**

The conditional operator gives us a convenient way to compact some if/else statements. It’s most useful when we need a conditional initializer (or assignment) for a variable, or to pass a conditional value to a function.

It should not be used for complex if/else statements, as it quickly becomes both unreadable and error prone.

## 5.7 — Logical operators
**&&** is before **||**
```cpp
std::cout << !a && (b || c);
std::cout << not a and (b or c);
```










































































