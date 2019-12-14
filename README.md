### Compile & Run a cpp file

```
#!/bin/sh
g++ -std=c++14 -Wall -O2 ${1} -o solution
./solution < input.txt
```
