module App = {
  [@react.component]
  let make = () =>
    <div>
      <p> {React.string("Client hello message, using ReasonReact!")} </p>
    </div>;
};

ReactDOM.querySelector("#clientRoot")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
