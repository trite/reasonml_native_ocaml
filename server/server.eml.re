let count = ref(0);

let count_requests = (inner_handler, request) => {
  count := count^ + 1;
  inner_handler(request);
};

let home = {
  <html>
    <body>
      <p><%s "Client hello message, using ReasonReact!" %></p>
      <div id="clientRoot"></div>
      <script src="/static/main.js"></script>
    </body>
  </html>
};

let () =
  Dream.run
  @@ Dream.logger
  @@ Dream.router([

    Dream.get("/",
      (_ => Dream.html(home))),

    Dream.get("/static/**",
      Dream.static("./static")),

  ]);