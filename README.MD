# Competitive Programming Solutions

This repository is a personal archive of my solved competitive programming problems (mostly **C++**).  My codeforces handle is Auchenai01.
I use it to track progress, keep solutions organized, and reuse templates across contests.

## Platforms / Folders

- **Codeforces** → `/codeforces`
  - Contests → `/codeforces/contests/<contest_id>/`
  - Gym → `/codeforces/gym/<gym_id>/`
- **AtCoder** → `/atcoder`
- **ICPC** → `/ICPC`

## Layout

Typical structure:

```
codeforces/
  contests/
    <contest_id>/
      A.cpp
      B.cpp
      ...
  gym/
    <gym_id>/
      A.cpp
      ...
atcoder/
  ...
ICPC/
  ...
```

## Build & Run (C++)

### Linux / macOS / WSL
```bash
g++ -std=c++20 -O2 -pipe -static -s main.cpp -o main
./main < input.txt
```

### Windows (PowerShell)
```powershell
g++ -std=c++20 -O2 -pipe main.cpp -o main.exe
.\main.exe < input.txt
```

## Notes

- Some solutions were written under contest time pressure and may prioritize speed of implementation over readability.
- I often reuse a personal template, so repeated headers/macros across files are expected.
- If you find a bug or have a cleaner approach, feel free to open an issue or PR.
- So far (Dec 3th 2025), my codeforces solve count is 1170. I expect this number to be continue growing.
## License 

Shared for reference and educational purposes.  
(Add a `LICENSE` file if you want to specify MIT/Apache-2.0/etc.)
