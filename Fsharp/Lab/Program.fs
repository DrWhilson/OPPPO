// For more information see https://aka.ms/fsharp-console-apps
open System.IO

let readLinesFromFile (filePath: string) =
    let lines = ref []
    use reader = new StreamReader(filePath)

    while not reader.EndOfStream do
        lines := reader.ReadLine() :: !lines

    List.rev !lines

let filePath = "./input"
let lines = readLinesFromFile filePath
printfn "Содержимое файла %s:" filePath
lines |> List.iter (fun line -> printfn "%s" line)
