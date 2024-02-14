(lang dune 3.11)

(using directory-targets 0.1)

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
  (dune
   (>= 3.11))
  (ocaml
   (>= 5.1.0))
  ppx_deriving
  ; (reason
  ;  (>= 3.10.0))
  reason
  (riot
   (>= 0.0.7))
  (containers
   (>= 3.13.1))
  (stdio
   (>= 0.16.0))
  (ocaml-lsp-server
   (>= 1.17.0))
  ocamlformat
  rtop)
 (tags
  (reasonml, ocaml)))
