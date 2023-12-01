open System
open System.IO
open System.Collections.Generic
open FSharpx.Collections.Experimental

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
        printfn ("-Sphere-")
        base.PrintFig
        printfn "Radius: %d" Radius

type Parall(_Name, _Density, _edgeA, _edgeB, _edgeC) =
    inherit Figure(_Name, _Density)

    let mutable edgeA = _edgeA
    let mutable edgeB = _edgeB
    let mutable edgeC = _edgeC

    override u.PrintFig =
        printfn ("-Parallelepiped-")
        base.PrintFig
        printfn "edge: %d %d %d" edgeA edgeB edgeC

type Cyll(_Name, _Density, _X, _Y, _Z, _Heigh, _Radius) =
    inherit Figure(_Name, _Density)

    let mutable Center = Point3D(_X, _Y, _Z)
    let mutable Heigh = _Heigh
    let mutable Radius = _Radius

    override u.PrintFig =
        printfn ("-Cyllinder-")
        base.PrintFig
        printfn "Center: %d %d %d \nHeigh: %d \nRadius: %d" Center.x Center.y Center.z Heigh Radius

let commPrint (lst: LinkedList<Figure>) =
    printfn ("---List---")

    for fig in lst do
        fig.PrintFig

let commAdd (comm: array<string>, lst: LinkedList<Figure>) =
    if comm[0] = "Sphere" && comm.Length = 4 then
        let sph = new Sphere(comm[1], comm[2] |> float32, comm[3] |> int)

        lst.AddLast(sph) |> ignore
        lst
    elif comm[0] = "Parall" && comm.Length = 6 then
        let par =
            new Parall(comm[1], comm[2] |> float32, comm[3] |> int, comm[4] |> int, comm[5] |> int)

        lst.AddLast(par) |> ignore
        lst
    elif comm[0] = "Cyll" && comm.Length = 8 then
        let cyl =
            new Cyll(
                comm[1],
                comm[2] |> float32,
                comm[3] |> int,
                comm[4] |> int,
                comm[5] |> int,
                comm[6] |> int,
                comm[7] |> int
            )

        lst.AddLast(cyl) |> ignore
        lst
    else
        printfn ("Cant create fig")
        lst

// let commRem (comm: string, lst: LinkedList<Figure>) =

let readLinesFromFile (filePath: string) =
    let lines = ref []
    use reader = new StreamReader(filePath)

    while not reader.EndOfStream do
        lines := reader.ReadLine() :: !lines

    List.rev !lines

// ---start---
let filePath = "./input"
let lst = new LinkedList<Figure>()

let commands = readLinesFromFile filePath

for comm in commands do
    let commpart = comm.Split()

    if commpart[0] = "ADD" then
        commAdd (commpart[1..], lst) |> ignore
        printfn ("Add a fig")
    elif commpart[0] = "REM" then
        printfn ("Rem a fig")
    elif commpart[0] = "PRINT" then
        commPrint (lst)
        printfn ("List Printed")
    else
        printfn ("Not a command")

lst.Clear()
// ---end---
