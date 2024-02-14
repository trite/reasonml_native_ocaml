// This file is our true entrypoint
// This should eventually make it easier to load things into rtop (still figuring it out)

// let () = Reasonml_native_ocaml_src.Entry.run();
open Riot;

type Message.t +=
  | Hello(string);

let () =
  Riot.run @@
  (
    () => {
      let rec loop = () => {
        switch (receive()) {
        | Hello(name) => print_endline("Hello, " ++ name ++ "! :D")
        | _ => print_endline("Oh no, an unhandled message! D:")
        };
        loop();
      };

      let pid = spawn(loop);
      send(pid, Hello("Joe"));
      send(pid, Hello("Mike"));
      send(pid, Hello("Robert"));
    }
  );
