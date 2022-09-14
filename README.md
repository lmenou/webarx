# webarx
Find paper on Arxiv :postbox: :bookmark_tabs: in your terminal !

## WARNING: This is a work in progress ! :warning: :construction:
In other words, ***use it at your own risk !***

## Problem :triumph:
Subscribing or scrolling ArXiv or BioArxiv is time-consuming, there must be a
way to automate our need of curiosity. The aim of this project is to build a
simple CLI to query the API of both websites. Let us have a direct access to
new papers, their authors' names and their abstract right from the terminal !

## How to build ? :gear:
The build of the software is cmake based. Some requirements are necessary then,
e.g. boost and cmake. Note that `git` is also a necessary requirement but I
assume you have it if you read this.

For instance on MacOS:
```shell
brew install boost cmake
```

Once you have installed the dependencies, pull this repository and run ***from
the root of the source tree***:
```shell
cmake -B build -S .
cmake --build build
```

Minor dependencies (see Credits) are fetched during the build.

No system wide installation is planned yet. If all goes well, you shall find
the executable `webarx` in `./build/bin/`.

## How to try it out ?
Well, the CLI is quite straightforward to understand so far. To print the help,
simply run the executable:
```shell
./build/bin/webarx --help
```

## How to unit test ?
Unit tests are all put in the directory test so far. Hence to run from the root
of the project:
```shell
ctest --test-dir build/test
```

## Contributions and Bugs :thought_balloon:
Provided you decipher my hieroglyphs, you are more than welcome to open a pull
request or an issue. If you think that this code is ugly, I would also be glad
to receive some constructive critics.

## LICENSE :bookmark:
This software is MIT licensed. See the
[LICENSE](https://github.com/lmenou/webarx/blob/master/LICENSE) file for more
information.

## Credits
This software so far would have been impossible without those fantastic
libraries:   
- cpr (Copyright (c) 2017-2021 Huu Nguyen, Copyright (c) 2022 libcpr and many other contributors)
- TinyXML2 from Lee Thomason
- Boost from The Boost organization
- FTXUI from  ArthurSonzogni (Copyright (c) 2019 Arthur Sonzogni.)
