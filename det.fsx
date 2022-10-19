type Matrix = { values: float[,] }
    with
        static member ofArray2D (values: float [,]) = 
            { values = values }
    
    end

type result =
    | Error of string
    | SuccessZero of int 

let rec checkZero(A:Matrix, rows:int, cols:int, size:int):result =
    if (rows >= size) then
        Error ("in func Zero: rows bigger size")
    else
        if (A.values[rows, cols] = 0.) then
            checkZero(A, rows+1, cols, size)
        else 
            SuccessZero(rows)

let rec Umatrix (A:Matrix, rows:int, cols:int, size:int):result = 
    if (rows >= size) then
        Error ("rows bigger size")    
    else
        if (A.values[rows, cols] = 0.) then
            let ZeroResult = checkZero(A, rows+1, cols, size)
            let temp = 
                match ZeroResult with 
                | Error("in func Zero: rows bigger size") -> Error("det = 0")
                | SuccessZero(rows) -> Error("Success!")
            temp
        else
            Error("Success!")





let size = 3
let a = array2D [[6.;2.;20.]
                 [4.;9.;6.]
                 [10.;7.;4.]]
let A = Matrix.ofArray2D a
let Q = Umatrix(A, 2, 2, 3)
printfn "%A" Q