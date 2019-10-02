# webServer

## Description
Simple web server application capable of a subset of the HyperText Transfer Protocol.

## Table of Content
- [Installation](#installation)
- [Specification](#specification)

## Installation

Download the repository.
```sh
git clone https://github.com/Peter408/webServer.git
```

Make sure you have [Boost](https://www.boost.org/) downloaded on your system since boost asio is used for socket streams.


add a `public_html` directory and fill with your files.

update the `httpd.conf` file with the correct path for your system.


#### Run

Run the `makefile` build to have executable file.
```sh
make build
```

Then run the executable `program` with run.

```sh
make run
```

Alternatively, you could just run the `makefile`.

```sh
make
```


## Specification

- Read,and store, standard configuration files for use in responding to client requests

- Parse HTTP requests

- Generate and send HTTP responses

- Respond to multiple simutaneous request through the use of threads

- Logging
