![License](https://img.shields.io/badge/license-GPL3-green)
![License](https://img.shields.io/badge/version-v1.0.0-green)


# DRX types : type implementation for C, C++ and Python dev
Implementation of a lot of type with docstring documentation made has exercice to improve personal dev skill in C and C++.

## Dependencies :
- Need makefile (4.4.x)
- C (Version depend on the list under this)
- C++ (Version depend on the list under this)

## All types implemented
| Type name                | for C | for C++ | For python |          Folder            |
|:-------------------------|:------|:--------|:-----------|:--------------------------:|
| Linked list (single ptr) | X     | >v3     | X          | [▶](./src/cpp/chaine.cpp) |
| Vector3                  | X     | >v98    | X          | [▶](./src/cpp/Vector3.cpp)|

## All type to implement :
Legend:
| Symbol | Meaning           |
|:------:|:------------------|
|   🛑   | will node be made |
|   ❌    | not made          |
|   ✅    | made              |
|   ✅P   | made using Py API* |
|   🔁   | in dev            |

> *: Some python implementations is just C++ implementation of Python API, in this case, the symbol : `✅P`

| Type name                  | in C ? | in C++ ? | in Python ? |
|:---------------------------|:------:|:--------:|:-----------:|
| Linked list (double ptr)   |   ❌   |    ❌   |      ❌     |
| Linked list (single ptr)   |   🔁   |    ✅   |      ❌     |
| Dynamic Array              |   ❌   |    🔁   |      ❌     |
| Binary tree                |   ❌   |    ❌   |      ❌     |
| n-branch tree              |   ❌   |    ❌   |      ❌     |
| graphs                     |   ❌   |    ❌   |      ❌     |
| Vector3                    |   ❌   |    ✅   |      ❌     |
| Vector2                    |   ❌   |    ❌   |      ❌     |
| Vector n                   |   ❌   |    ❌   |      ❌     |
| Queue FIFO                 |   ❌   |    ❌   |      ❌     |
| Stack LIFO                 |   ❌   |    ❌   |      ❌     |
| Deque (double-ended queue) |   ❌   |    ❌   |      ❌     |

## Changelogs
- **v1.0.0**
    - Added Linked list in single ptr
- **v1.0.1**
    - Added Vector3 type and documentation

## Music
If you want to take a cup of coffee and see/review my code here one of my playlist with :

[![Ma Playlist](https://image-cdn-ak.spotifycdn.com/image/ab67706c0000da8457887b87c49785d8d3fc57b4)](https://open.spotify.com/playlist/2MxUFRUAxXbT7cG0rsOewU)