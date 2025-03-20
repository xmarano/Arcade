# ARCADE

### How to implement new graphics/games libraries

1. Set your `.so` file into the [`./lib`](lib/) directory
2. Compile with `make`
3. Start with `./arcade lib/[your_lib]`

Should be architectured like this :
```shell
.
├── Assets
├── Makefile
├── README.md
├── doc
├── lib
│    ├── [HERE]
│    └── [HERE]
└── src
```
