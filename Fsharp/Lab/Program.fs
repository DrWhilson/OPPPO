open System
open System.IO
open System.Collections.Generic
open FSharpx.Collections.Experimental

// ---struct zone---
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

    abstract member getName: string
    abstract member PrintFig: unit
    abstract member CalcCap: float

    default u.getName = Name
    default u.PrintFig = printfn "Name: %s\nDensity: %f" Name Density
    default u.CalcCap = 0.0

type Sphere(_Name, _Density, _Radius) =
    inherit Figure(_Name, _Density)

    let mutable Radius = _Radius: int

    override u.getName = base.getName

    override u.PrintFig =
        printfn ("-Sphere-")
        base.PrintFig
        printfn "Radius: %d \nCapacity: %f" Radius u.CalcCap

    override u.CalcCap = 4.0 / 3.0 * 3.14 * ((Radius |> float) ** 3)

type Parall(_Name, _Density, _edgeA, _edgeB, _edgeC) =
    inherit Figure(_Name, _Density)

    let mutable edgeA = _edgeA: int
    let mutable edgeB = _edgeB: int
    let mutable edgeC = _edgeC: int

    override u.getName = base.getName

    override u.PrintFig =
        printfn ("-Parallelepiped-")
        base.PrintFig
        printfn "edge: %d %d %d \nCapacity: %f" edgeA edgeB edgeC u.CalcCap

    override u.CalcCap = (edgeA |> float) * (edgeB |> float) * (edgeC |> float)

type Cyll(_Name, _Density, _X, _Y, _Z, _Heigh, _Radius) =
    inherit Figure(_Name, _Density)

    let mutable Center = Point3D(_X, _Y, _Z)
    let mutable Heigh = _Heigh: int
    let mutable Radius = _Radius: int

    override u.getName = base.getName

    override u.PrintFig =
        printfn ("-Cyllinder-")
        base.PrintFig

        printfn
            "Center: %d %d %d \nHeigh: %d \nRadius: %d \nCapacity: %f"
            Center.x
            Center.y
            Center.z
            Heigh
            Radius
            u.CalcCap

    override u.CalcCap = 3.14 * ((Radius |> float) ** 2) * (Heigh |> float)

// ---func zone---
let IsContainDigit (str: string) : bool =
    str |> Seq.forall (fun c -> not (Char.IsDigit(c)))

let checker (fig: Figure, comm: array<string>) : bool =
    if comm.Length = 3 then
        if comm[0] = "name" && comm[1] = "=" then
            fig.getName = comm[2]
        elif comm[0] = "Cap" then
            if comm[1] = "=" then
                fig.CalcCap = (comm[2] |> float)
            elif comm[1] = ">" then
                fig.CalcCap > (comm[2] |> float)
            elif comm[1] = "<" then
                fig.CalcCap < (comm[2] |> float)
            else
                printfn ("Not a operation sign")
                false
        else
            printfn ("Not a comm")
            false
    else
        printfn ("Not a rem comm")
        false

let commPrint (lst: LinkedList<Figure>) =
    printfn ("---List---")

    for fig in lst do
        fig.PrintFig

let commAdd (comm: array<string>, lst: LinkedList<Figure>) =
    if Char.IsUpper(comm[1][0]) && IsContainDigit(comm[1]) then
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
    else
        printfn ("Error in fig Name")
        lst

let removeElements (comm: array<string>, list: LinkedList<Figure>) =
    let mutable currentNode = list.First

    while currentNode <> null do
        let nextNode = currentNode.Next

        if checker (currentNode.Value, comm) then
            list.Remove(currentNode)

        currentNode <- nextNode


let commRem (comm: array<string>, lst: LinkedList<Figure>) = removeElements (comm, lst)

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

    if commpart.Length > 1 && commpart[0] = "ADD" then
        commAdd (commpart[1..], lst) |> ignore
        printfn ("Add a fig")
    elif commpart.Length > 1 && commpart[0] = "REM" then
        commRem (commpart[1..], lst) |> ignore
        printfn ("Rem a fig")
    elif commpart.Length = 1 && commpart[0] = "PRINT" then
        commPrint (lst)
        printfn ("List Printed")
    else
        printfn ("Not a command")

lst.Clear()
// ---end---
