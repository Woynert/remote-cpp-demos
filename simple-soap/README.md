# Simple SOAP

### Development

Start Nix development shell:

```sh
nix-shell
```

#### Running

SOAP service will be exposed at `http://0.0.0.0:8080/sampleservice`:

```sh
./gradlew run
```

#### Format

`clang-format` required:

```sh
./format.sh clang-check # check (doesn't write)
./format.sh clang-format # apply (writes)
```

#### Generate SOAP client code

You need to have `wsimport`:

```sh
cd client/src/main/java
wsimport -keep -p simple.generated.soap http://localhost:8080/sampleservice?wsdl
```

To install `wsimport` using Nix:

```sh
nix-shell -p adoptopenjdk-openj9-bin-8
```

