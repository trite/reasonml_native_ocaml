// This file is our true entrypoint
// This should eventually make it easier to load things into rtop (still figuring it out)

// let () = Reasonml_native_ocaml_src.Entry.run();
open Riot;

type Message.t +=
  | Hello_world;

let () =
  (
    () =>
      spawn(() =>
        switch (receive()) {
        | Hello_world => print_endline("Hello, World! :D")
        | _ => print_endline("Received something else")
        }
      )
      |> send(_, Hello_world)
  )
  |> Riot.run;
