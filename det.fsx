type Matrix = { values: float[,] }
    with
        static member ofArray2D (values: float [,]) = 
            { values = values }
    
    end




let Umatrix (A:Matrix, rows:int, cols:int, size:int):int = 
    for i in 0..2 do
        if (A.values[i, i] = 9) then
            printfn "%A" A.values[i, i]
            2
        else 
            5
    3



let size = 3
let a = array2D [[6.;2.;20.]
                 [4.;9.;6.]
                 [10.;7.;4.]]
let A = Matrix.ofArray2D a
let q = Umatrix(A, 2, 3, 3)
printfn "%A"q 