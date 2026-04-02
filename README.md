# C++ Tutorial — StachnissLab Homework Corrections

Solutions to all homework assignments of the **Modern C++ for Computer Vision
and Image Processing** course by Cyrill Stachniss
([StachnissLab](https://www.ipb.uni-bonn.de/), University of Bonn).

---

## Prerequisites

| Tool | Version |
|------|---------|
| C++ compiler | C++11 or later (g++ / clang++) |
| CMake | ≥ 3.1 |

---

## Repository structure

```
.
├── HW1/   # Homework 1 – Basic C++: string tokenisation & word frequency
├── HW2/   # Homework 2 – Greyscale image class with PGM file I/O
└── HW3/   # Homework 3 – Colour image class with Strategy-pattern I/O
```

---

## HW1 – String operations

**Topics covered:** `std::string`, `std::vector`, `std::map`, range-based for
loops, function design.

**Tasks:**
- `Tokenize(str, delimiter)` — splits a string into tokens using a delimiter
  character, skipping empty tokens.
- `CountWordFrequency(str)` — counts how often each word appears in a string
  and returns an alphabetically sorted list of `(word, count)` pairs.

### Build & run

```bash
cd HW1 && mkdir build && cd build
cmake ..
make
./bin/hw1_main
ctest --output-on-failure
```

---

## HW2 – Greyscale image class (`igg::Image`)

**Topics covered:** classes, const/non-const overloading, file I/O streams,
`std::vector`, histogram computation, image scaling.

**Class interface (`igg::Image`):**

| Method | Description |
|--------|-------------|
| `Image()` | Default constructor (empty image) |
| `Image(rows, cols)` | Constructor — creates a zero-filled image |
| `int rows() const` | Returns number of rows |
| `int cols() const` | Returns number of columns |
| `int& at(row, col)` | Pixel setter (returns mutable reference) |
| `const int& at(row, col) const` | Pixel getter (returns const reference) |
| `bool FillFromPgm(file)` | Reads an ASCII PGM (P2) file |
| `void WriteToPgm(file)` | Writes an ASCII PGM (P2) file |
| `vector<float> ComputeHistogram(bins)` | Computes pixel-count histogram |
| `void DownScale(scale)` | Sub-samples by keeping every `scale`-th pixel |
| `void UpScale(scale)` | Repeats each pixel `scale` times in both dimensions |

**Four demo applications** are provided in `src/application{1..4}/`:
1. Getter/setter demonstration
2. Read a PGM file, draw a diagonal, write it back
3. Compute and print a 10-bin histogram
4. Downscale and upscale a PGM image

### Build & run

```bash
cd HW2 && mkdir build && cd build
cmake ..
make
ctest --output-on-failure
```

---

## HW3 – Colour image class with Strategy pattern (`igg::Image`)

**Topics covered:** inheritance, virtual functions, abstract base classes,
the Strategy design pattern, colour images (RGB), PPM file format.

**Class hierarchy:**

```
IoStrategy          (abstract base)
├── DummyIoStrategy (always succeeds write; returns empty on read — for tests)
└── PpmIoStrategy   (plain PPM P3 format)
```

**`igg::Image` interface:**

| Method | Description |
|--------|-------------|
| `Image(strategy)` | Constructor — binds an I/O strategy |
| `Image(rows, cols, strategy)` | Constructor — creates a zero-filled image |
| `int rows() / int cols()` | Dimension accessors |
| `Pixel& at(row, col)` | Pixel accessor (read/write) |
| `const Pixel& at(row, col) const` | Pixel accessor (read-only) |
| `bool ReadFromDisk(file)` | Reads image via the strategy |
| `void WriteToDisk(file)` | Writes image via the strategy |

### Build & run

```bash
cd HW3 && mkdir build && cd build
cmake ..
make
ctest --output-on-failure
```
