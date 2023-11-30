open System
open System.IO
open System.Collections.Generic
// open FSharpx.Collections.Experimental

type Point3D =
    struct
        val x: int
        val y: int
        val z: int

        new(_x: int, _y: int, _z: int) = { x = _x; y = _y; z = _z }

        member this.PrintPoint(p: Point3D) =
            printfn "X: %d \nY: %d \nZ:%d" p.x p.y p.z
    end

type Figure(_Name, _Density) =
    let mutable Name = _Name
    let mutable Density = _Density

    abstract member PrintFig: unit
    default u.PrintFig = printfn "Name: %s\nDensity: %f" Name Density

type Sphere(_Name, _Density, _Radius) =
    inherit Figure(_Name, _Density)

    let mutable Radius = _Radius

    override u.PrintFig =
        base.PrintFig
        printfn "Radius: %d" Radius

type Parall(_Name, _Density, _edgeA, _edgeB, _edgeC) =
    inherit Figure(_Name, _Density)

    let mutable edgeA = _edgeA
    let mutable edgeB = _edgeB
    let mutable edgeC = _edgeC

    override u.PrintFig =
        base.PrintFig
        printfn "edge: %d %d %d" edgeA edgeB edgeC

type Cyll(_Name, _Density, _X, _Y, _Z, _Heigh, _Radius) =
    inherit Figure(_Name, _Density)

    let mutable Center = Point3D(_X, _Y, _Z)
    let mutable Heigh = _Heigh
    let mutable Radius = _Radius

    override u.PrintFig =
        base.PrintFig
        printfn "Center: %d %d %d \nHeigh: %d \nRadius: %d" Center.x Center.y Center.z Heigh Radius

// let readLinesFromFile (filePath: string) =
//     let lines = ref []
//     use reader = new StreamReader(filePath)
//
//     while not reader.EndOfStream do
//         lines := reader.ReadLine() :: !lines
//
//     List.rev !lines
//
// let filePath = "./input"
// let lines = readLinesFromFile filePath
// printfn "Содержимое файла %s:" filePath
// lines |> List.iter (fun line -> printfn "%s" line)

let obj = Sphere("Name", 4.0, 5)

obj.PrintFig
