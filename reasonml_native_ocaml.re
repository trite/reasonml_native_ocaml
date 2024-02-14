// This file is our true entrypoint
// This should eventually make it easier to load things into rtop (still figuring it out)
// let () = Reasonml_native_ocaml_src.Entry.run();
let () = Dream.run(_ => Dream.html("Good morning, world!"));
