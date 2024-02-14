// Function composition operator
let (>>) = CCFun.Infix.(%>);

/* This version will write output we don't want, but it's a good example for that purpose
   let addAndPrint =
     CCInt.of_string
     >> CCOption.map((+)(1))
     >> CCOption.fold(
          () => Stdio.printf("Your number + 1 = %d\n"),
          print_endline("Invalid input!"),
        );

   let runBad = () => {
     switch (Sys.argv) {
     | [||]
     | [|_|] =>
       In_channel.stdin
       |> In_channel.input_line
       |> CCOption.fold(() => addAndPrint, print_endline("No input!"))

     | [|_exe_path, arg|] => arg |> addAndPrint

     | args =>
       args |> CCArray.to_list |> CCList.drop(1) |> CCList.iter(addAndPrint)
     };
   };
   */

let add1 =
  CCInt.of_string
  >> CCOption.map(CCInt.succ >> CCInt.to_string)
  >> CCOption.fold((_, x) => "Your number is: " ++ x, "Invalid input!");

let getInputCreateOutput = () =>
  switch (Sys.argv) {
  | [||]
  | [|_|] =>
    let _ = print_endline("Enter your number: ");

    In_channel.stdin
    |> In_channel.input_line
    |> CCOption.fold((_, x) => x |> add1, "No input!");

  | [|_exe_path, arg|] => arg |> add1

  | args =>
    args
    |> CCArray.to_list
    |> CCList.drop(1)
    |> CCList.map(add1)
    |> CCString.concat("\n")
  };

let run = () => {
  getInputCreateOutput() |> print_endline;
};
