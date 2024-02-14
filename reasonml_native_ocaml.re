// This file is our true entrypoint
// This should eventually make it easier to load things into rtop (still figuring it out)

// let () = Reasonml_native_ocaml_src.Entry.run();
Riot.run @@
(
  () => {
    open Riot;
    let pid = spawn(() => Format.printf("Hello, %a!", Pid.pp, self()));
    wait_pids([pid]);
    shutdown();
  }
);
