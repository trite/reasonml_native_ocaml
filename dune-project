(lang dune 3.11)

(using directory-targets 0.1)

(using melange 0.1)

(name reasonml_native_ocaml)

(generate_opam_files true)

(source
 (github trite/reasonml_native_ocaml))

(authors "Paul Brunner")

(maintainers "Paul Brunner")

(license MIT)

(documentation https://github.com/trite/reasonml_native_ocaml)

(package
 (name reasonml_native_ocaml)
 (synopsis "TODO: this")
 (description "TODO: this")
 (allow_empty)
 (depends
  (containers
   (>= 3.13.1))
  (dream
   (>= 1.0.0~alpha5))
  (dune
   (>= 3.11))
  (melange
   (>= 2.1.0))
  (ocaml
   (>= 5.1.0))
  (ocaml-lsp-server
   (>= 1.17.0))
  melange-webapi
  ocamlformat
  opam-check-npm-deps
  ppx_deriving
  reason
  reason-react-ppx
  rtop)
 (tags
  (reasonml, ocaml)))
