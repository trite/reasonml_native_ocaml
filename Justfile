@_default:
  just --list

# In case you need to point opam at a specific install:
opam := "opam"

dune := "opam exec -- dune"

# Remove all generated files
hard-reset:
  rm -f reasonml_native_ocaml.opam
  rm -rf _build
  rm -rf _opam
  rm -rf node_modules

# Create Opam switch
create-switch:
  {{ opam }} switch create . 5.1.0 -y --deps-only

# Quick install
install:
  npm install
  {{ dune }} build reasonml_native_ocaml.opam # Generate the opam file
  {{ opam }} install -y . --deps-only --with-test
  {{ opam }} exec opam-check-npm-deps

# Full install, the `&& install` means run the install recipe after this recipe
full-install: && install
  {{ opam }} update
  {{ opam }} install dune

# Initialize the project
init: create-switch full-install

# Watch for changes and rebuild
watch:
  {{ dune }} build -w

# Build
build:
  {{ dune }} build

# Execute, passing along any arguments
run *args:
  {{ dune }} exec ./_build/default/reasonml_native_ocaml.exe {{ args }}

# RTop
rtop:
  {{ opam }} exec -- rtop -init .rtopinit
