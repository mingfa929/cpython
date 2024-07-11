1. 编译  
gcc -g -O0 -shared -o example.so example.c -I$HOME/anaconda3/envs/numbaenv/include/python3.10 -fPIC -Wl,-rpath,$HOME/anaconda3/envs/numbaenv/lib -L$HOME/anaconda3/envs/numbaenv/lib -lpython3.10  

2. run  
python example.py  

3. gdb debug  
gdb --args /opt/python/3.10/bin/python3 example.py
ps: 直接指定python路径
```
wangmingfa@n37-003-157:~/code/github/mingfa929/cpython/mytest$ gdb --args /opt/python/3.10/bin/python3 example.py 
Reading symbols from /opt/python/3.10/bin/python3...
(gdb) b example_hello
Function "example_hello" not defined.
Make breakpoint pending on future shared library load? (y or [n]) y
Breakpoint 1 (example_hello) pending.
(gdb) run
Starting program: /data00/python/3.10/bin/python3 example.py
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, example_hello (self=0x7ffff73f0e30, args=0x7ffff7398230) at example.c:4
4         PyObject *name = NULL;
(gdb) py-bt
Undefined command: "py-bt".  Try "help".
(gdb) source ~/code/github/cpython/build/python-gdb.py 
(gdb) py-bt
Traceback (most recent call first):
  <built-in method hello of module object at remote 0x7ffff73f0e30>
  File "/data00/home/wangmingfa/code/github/mingfa929/cpython/mytest/example.py", line 4, in <module>
    ret = example.hello("world")
(gdb) p args
$1 = ('world',)
(gdb) py-print args
Unable to read information on python frame
(gdb) py-print args[0]
Unable to read information on python frame
(gdb) py-list
   1    import example
   2    
   3    # print(example.add(2, 3))
  >4    ret = example.hello("world")
   5    print(f"ret={ret}")
(gdb) 
```