Build Local Code in Docker Compose via an "Init Container"
----------------------------------------------------------
Docker compose has init containers?  It kind of does, yes.

`depends_on` will take the name of a service, but it will also take an object
that maps service to object, where the inner object can have a `condition`
property. The `condition` property can have the value
`service_completed_successfully`, which pretty much means that the named
service functions as an init container.

See [docker-compose.yaml](docker-compose.yaml). The app to run is `hello`: a
C++ program that prints "hello world" in a loop until it receives SIGTERM. The
[src/](src/) tree is mounted (not copied!) into a separate container, `build`,
which compiles the C++ program in a named volume. `hello` then runs the
finished binary from the same volume.

Try it out:
```console
$ docker compose up --build
```

If you then modify the sources (e.g. [src/main.cpp](src/main.cpp)) and run it
again, the code will recompile, but the docker containers will not need to be
rebuilt. Also, since the docker volume is persistent, you have incremental
builds.
