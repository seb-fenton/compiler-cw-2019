1,16c1
< x=0
< 
< def f():
<     global x
<     x=x+1
<     return x
< 
< def main():
<     return f()+f()
< 
< # Boilerplate
< if __name__ == "__main__":
<     import sys
<     ret=main()
<     sys.exit(ret)
< 
---
> x=0
\ No newline at end of file
