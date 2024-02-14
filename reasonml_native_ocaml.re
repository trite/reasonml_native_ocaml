// This file is our true entrypoint
// This should eventually make it easier to load things into rtop (still figuring it out)
// let () = Reasonml_native_ocaml_src.Entry.run();
let count = ref(0);

let count_requests = (inner_handler, request) => {
  count := count^ + 1;
  inner_handler(request);
};

let () =
  Dream.run @@
  Dream.logger @@
  count_requests @@
  Dream.router([
    Dream.get("/", _ =>
      Dream.html(Printf.sprintf("Saw %i request(s)!", count^))
    ),
  ]);
