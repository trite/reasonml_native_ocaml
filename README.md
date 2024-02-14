# Rtop
Rtop is the ReasonML equivalent of utop. Utop is a repl for OCaml. Rtop is a repl for Reason. It's useful to know that it uses utop under the hood, so if you have issues you can look to discussions about utop for solutions.

Update the `.rtopinit` file in the root of the repo with any libraries you want loaded when running rtop.

Run rtop with: `just rtop`

## Pinnings
The latest version of rtop in opam was throwing an error about OCaml needing to be < 4.0.7. I pinned rtop (and consequently reason, since it complained otherwise) to the latest commits in git for the Reason repo. This shouldn't be needed forever, and if needed for long should probably be updated to pin a specific commit in github.
