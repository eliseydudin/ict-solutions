# ict-solutions 🎓
solutions for tasks on different platforms ([here](https://informatics.msk.ru) for example)
PS: some solutions for dynamic programming can be found [here](https://github.com/eliseydudin/dp-school)

# running
most of the solutions are written in c++, they can be compiled using meson:
```shell
meson setup builddir
meson compile -C builddir
exec builddir/<website>/<task> # for example `exec builddir/informatic/111403`
```
all other solutions can be ran using their respective programs (like go & python)

# contributing
any contributions are welcome! provide any solutions for any website with programming tasks, the only requirement is that they pass _some_ tests
