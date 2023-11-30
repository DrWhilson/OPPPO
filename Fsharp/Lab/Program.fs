open System
open System.IO
open System.Collections.Generic
open FSharpx.Collections.Experimental

type Point3D =
    val X: int
    val Y: int
    val Z: int

type Figure() =
    let mutable Name = ""
    let mutable Density = 0.0

type Sphere() =
    inherit Figure()

    let mutable Radius = 0

type Parall() =
    inherit Figure()

    let mutable edgeA = 0
    let mutable edgeB = 0
    let mutable edgeC = 0

type Cyll() =
    inherit Figure()

    let mutable Heigh = 0
    let mutable Radius = 0

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
