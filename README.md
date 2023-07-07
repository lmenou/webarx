# webarx
Find paper on Arxiv :postbox: :bookmark_tabs: in your terminal !

## Problem :triumph:
Subscribing or scrolling ArXiv or is time-consuming, there must be a way to
automate our need of curiosity. The aim of this project is to build a simple
CLI to query the API of the website. Let us have a direct access to new papers,
their authors' names and their abstract right from the terminal !

This software targets mainly UNIX users (MacOS, Linux) and is not tested (yet?)
on Windows, *BSD.   

## How to build ? :gear:

### Requirements :lock_with_ink_pen:
The build of the software is cmake based. The following *needs* to be installed
on the system:   
- CMake, minimal version 3.20
- Git, minimal version 2.34 (to fetch third party libraries)
- Boost, minimal version 1.74

The software is also using [CURL](https://curl.se/) under the hood, hence, you
can speed up the build process by installing the latter. However, if not found,
the library is fetched during configuration of the build (thank you very much
[cpr](https://docs.libcpr.org/)!).   

For instance on MacOS:
```shell
brew install boost cmake
```

Debian based distributions users (e.g. Ubuntu), feel free to have a look at the
[wiki](https://github.com/lmenou/webarx/wiki/Build-on-a-Debian-based-distribution)

### Build
Once you have installed the dependencies, pull this repository and run ***from
the root of the source tree***:
```shell
cmake -B build -S .
make -Cbuild -j10 # or simply make -Cbuild, no parallelization
```

Minor dependencies (see Credits) are fetched during the build.

If all goes well, you shall find the executable `webarx` in `./build/bin/`.

## How to try it out ?
Well, the CLI is quite straightforward to understand so far. To print the help,
simply run the executable:
```shell
./build/bin/webarx --help
```

## How to install ? :incoming_envelope:
If you are satisfied with the software, and you wish to have it system wide, an
install target is provided. After having run the build, simply write:
```shell
make -Cbuild install
webarx -v
```

I am working on an uninstall target, but I need to be careful with that, to not
corrupt my system, and more importantly, yours. Hence, if you installed the
software and you wish afterwards to uninstall it, have a look at the
`build/install_manifest.txt`, and remove the specified directories (you should
see directories created by `cpr`, `tinyxml2`, and `ftxui` libraries plus the
`webarx` executable in your local bin).

## Contributions and Bugs :thought_balloon:
Provided you decipher my hieroglyphs, you are more than welcome to open a pull
request or an issue. If you think that this code is ugly, I would also be glad
to receive some constructive critics. This is a work in progress, even in my
view, some parts of the code are not elegant at all, I am working on it :grin:.

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
